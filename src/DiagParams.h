/*! @file DiagParams.h

  @brief DiagParams.h is the class that hold the simulation parameters and can read from a file the namelist

  @author tommaso vinci
  @date 2013-02-15
*/

#ifndef DIAGPARAMS_H
#define DIAGPARAMS_H

#include <vector>
#include <string>

#include "InputData.h"
#include "PicParams.h"

//! this structure holds all the possible paraeters for phase diagnostics. Then every DiagnosticPhaseXXXXX will pick the ones that fit
struct phaseStructure {
	//!string defining the kind oh phase projections
    std::vector<std::string> kind;

    //! phase output every (every phase diagnostic must have this)
    unsigned int every;
	
	//! vector of pointer to species on which the phase diag will be applied (if omitted, it will be for all)
	std::vector<std::string> species;
	
    //! minimum position
	std::vector<double> pos_min;
    //! max position
	std::vector<double> pos_max;
    //! number of positions
	std::vector <unsigned int> pos_num;

    //! minimum momentum
	std::vector<double> mom_min;
    //! max momentum
	std::vector<double> mom_max;
    //! number of momenta
	std::vector <unsigned int> mom_num;
	
    //! minimum Lorentz factor
	std::vector<double> lor_min;
    //! max Lorentz factor
	std::vector<double> lor_max;
    //! number of Lorentz factors
	std::vector <unsigned int> lor_num;
	
};


//! this structure contains the definition of a probe (0D 1D 2D and 3D)
struct probeStructure {
    //! probe1D output every (every probe1D diagnostic must have this)
    unsigned int every;
    //! start position of the 1D probe
    std::vector<double> pos;
    
    //! end position of the probe along the first axe (only for 1Dprobe or 2Dprobe or 3D probe)
    std::vector<double> posFirst;
    
    //! end position of the probe along the second axe (only for 2Dprobe or 3D probe)
    std::vector<double> posSecond;
    
    //! end position of the probe along the second axe (only for 3D probe)
    std::vector<double> posThird;
    
    //! number of probes between pos and all the end positions (only for 1Dprobe or 2Dprobe or 3D probe)
    //! this will be one value for 1D probe, two values for 2D probe and three values for 3D probe
    std::vector<unsigned int> number;
};

// ---------------------------------------------------------------------------------------------------------------------
//! DiagParams class: holds all the properties of the simulation that are read from the input file
// ---------------------------------------------------------------------------------------------------------------------
class DiagParams {

public:
    //! Creator for DiagParams
    DiagParams(InputData &, PicParams&);

    //! field dump output
    unsigned int fieldDump_every;
    
    //! time-averaged field dump output
    unsigned int avgfieldDump_every;
    
    //! number of time-steps for time-averaging of fields
    unsigned int ntime_step_avg;

    //! particle dump output
    unsigned int particleDump_every;

    //! scalar output every scalar_every (namelist group "diagnostic scalar" key "every")
    unsigned int scalar_every;

    //! vector of 0D probes
    std::vector<probeStructure> probe0DStruc;

    //! vector of 1D probes
    std::vector<probeStructure> probe1DStruc;
    
    //! vector of 2D probes
    std::vector<probeStructure> probe2DStruc;
    
    //! every for the standard pic timeloop output
    unsigned int print_every;
	
	//! vector containing phase1D structures
	std::vector<phaseStructure> vecPhase;
};

#endif
