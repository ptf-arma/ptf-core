// El Sindicato uniform reissues. The Apex Syndikat bandit shirts and the
// vanilla guerrilla set are already Independent-linked, so only the civilian
// items need the side-lock wrapper (see cfgPerenosUniforms.hpp for why).

// UniformItem is already declared by cfgPerenosUniforms.hpp, included first.
class U_C_WorkerCoveralls;

class PTF_U_sind_coveralls: U_C_WorkerCoveralls
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "Work Coveralls (Sindicato)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Sind_estibador";
      containerClass = "Supply40";
      mass = 40;
   };
};
