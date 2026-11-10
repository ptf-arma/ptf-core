"""Capture the Arma 3 window, and only that window, to an image (Windows).

The owner allows capturing the Arma window specifically, nothing else on screen. This finds
the game's top-level window by its process (arma3_x64.exe) and asks Windows to render that
window into a bitmap with PrintWindow and PW_RENDERFULLCONTENT, which works for a DirectX
window that is behind others or unfocused (not minimized). Unlike the game's own
`screenshot` command, the result includes dialogs and UI such as the Billet tablet.

    from capture import capture_arma
    capture_arma(Path("shot.png"))   # True if captured
"""
import ctypes
import ctypes.wintypes as wt
from pathlib import Path

from PIL import Image

user32 = ctypes.windll.user32
gdi32 = ctypes.windll.gdi32
kernel32 = ctypes.windll.kernel32
PW_RENDERFULLCONTENT = 2


def _exe_of(pid):
    handle = kernel32.OpenProcess(0x1000, False, pid)  # PROCESS_QUERY_LIMITED_INFORMATION
    if not handle:
        return ""
    try:
        buf = ctypes.create_unicode_buffer(1024)
        size = wt.DWORD(1024)
        if kernel32.QueryFullProcessImageNameW(handle, 0, buf, ctypes.byref(size)):
            return Path(buf.value).name.lower()
        return ""
    finally:
        kernel32.CloseHandle(handle)


def arma_window():
    """The Arma 3 game window's handle, or None."""
    found = []

    @ctypes.WINFUNCTYPE(wt.BOOL, wt.HWND, wt.LPARAM)
    def each(hwnd, _):
        if not user32.IsWindowVisible(hwnd):
            return True
        pid = wt.DWORD()
        user32.GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
        if _exe_of(pid.value) == "arma3_x64.exe":
            rect = wt.RECT()
            user32.GetClientRect(hwnd, ctypes.byref(rect))
            if rect.right * rect.bottom > 0:
                found.append((rect.right * rect.bottom, hwnd))
        return True

    user32.EnumWindows(each, 0)
    return max(found)[1] if found else None


def capture_arma(target):
    hwnd = arma_window()
    if not hwnd or user32.IsIconic(hwnd):
        return False
    rect = wt.RECT()
    user32.GetWindowRect(hwnd, ctypes.byref(rect))
    w, h = rect.right - rect.left, rect.bottom - rect.top
    window_dc = user32.GetWindowDC(hwnd)
    mem_dc = gdi32.CreateCompatibleDC(window_dc)
    bitmap = gdi32.CreateCompatibleBitmap(window_dc, w, h)
    gdi32.SelectObject(mem_dc, bitmap)
    ok = user32.PrintWindow(hwnd, mem_dc, PW_RENDERFULLCONTENT)

    class BITMAPINFOHEADER(ctypes.Structure):
        _fields_ = [("biSize", wt.DWORD), ("biWidth", wt.LONG), ("biHeight", wt.LONG), ("biPlanes", wt.WORD),
                    ("biBitCount", wt.WORD), ("biCompression", wt.DWORD), ("biSizeImage", wt.DWORD),
                    ("biXPelsPerMeter", wt.LONG), ("biYPelsPerMeter", wt.LONG), ("biClrUsed", wt.DWORD),
                    ("biClrImportant", wt.DWORD)]

    header = BITMAPINFOHEADER(ctypes.sizeof(BITMAPINFOHEADER), w, -h, 1, 32, 0, 0, 0, 0, 0, 0)
    pixels = ctypes.create_string_buffer(w * h * 4)
    gdi32.GetDIBits(mem_dc, bitmap, 0, h, pixels, ctypes.byref(header), 0)
    gdi32.DeleteObject(bitmap)
    gdi32.DeleteDC(mem_dc)
    user32.ReleaseDC(hwnd, window_dc)
    if not ok:
        return False
    image = Image.frombuffer("RGBA", (w, h), pixels, "raw", "BGRA", 0, 1).convert("RGB")
    if max(image.getextrema()[0][1], image.getextrema()[1][1], image.getextrema()[2][1]) < 8:
        return False  # all black: nothing rendered
    Path(target).parent.mkdir(parents=True, exist_ok=True)
    image.save(target)
    return True


if __name__ == "__main__":
    import sys
    print(capture_arma(Path(sys.argv[1] if len(sys.argv) > 1 else "arma.png")))
