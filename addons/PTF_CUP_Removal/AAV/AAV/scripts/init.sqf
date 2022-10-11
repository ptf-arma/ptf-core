private "_inwater";
_aav=_this select 0;
_count=3; 
sleep 0.5;
if ((getpos _aav select 2)<-0.4) then {
        _inwater=1;
        _aav animate ["plate_front", 1];
        _aav animate ["turbine_cover_right", 1];
        _aav animate ["turbine_cover_left", 1];
        }
        else{_inwater=0};
             
while {alive _aav} do 
{
	sleep 2.0;
         if ((getpos _aav select 2)>-0.4) then {
         	if (_inwater==1) then {_count=0;_inwater=0; };
                 if (_count<4) then {_count=_count+1}; 
         } 
         else{
          	if (_inwater==0) then {_count=0;_inwater=1; };            
                 if (_count<4) then {_count=_count+1};                   
         }; 

         if (_count==3)then{
		_aav animate ["plate_front", _inwater];
		_aav animate ["turbine_cover_right", _inwater];
		_aav animate ["turbine_cover_left", _inwater];        
         };        
};