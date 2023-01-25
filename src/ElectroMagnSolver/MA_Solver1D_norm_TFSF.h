#ifndef MA_SOLVER1D_NORM_TFSF_H
#define MA_SOLVER1D_NORM_TFSF_H

#include "Solver1D.h"
#include "SolverTFSF.h"
class ElectroMagn;
class Patch;

//  --------------------------------------------------------------------------------------------------------------------
//! Class Pusher
//  --------------------------------------------------------------------------------------------------------------------
class MA_Solver1D_norm_TFSF : public Solver1D, public SolverTFSF
{

public:
    //! Creator for MF_Solver1D_Yee
    MA_Solver1D_norm_TFSF( Params &params );
    virtual ~MA_Solver1D_norm_TFSF();

    //! Overloading of () operator
    virtual void operator()( ElectroMagn *fields, Patch *patch, double time );

protected:

};//END class

#endif

