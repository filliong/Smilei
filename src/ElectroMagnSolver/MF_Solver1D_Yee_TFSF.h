#ifndef MF_SOLVER1D_YEE_TFSF_H
#define MF_SOLVER1D_YEE_TFSF_H

#include "Solver1D.h"
#include "SolverTFSF.h"
class ElectroMagn;
class Patch;

//  --------------------------------------------------------------------------------------------------------------------
//! Class Pusher
//  --------------------------------------------------------------------------------------------------------------------
class MF_Solver1D_Yee_TFSF : public Solver1D, public SolverTFSF
{

public:
    //! Creator for MF_Solver1D_Yee_TFSF
    MF_Solver1D_Yee_TFSF( Params &params );
    virtual ~MF_Solver1D_Yee_TFSF();

    //! Overloading of () operator
    virtual void operator()( ElectroMagn *fields, Patch* partch );

protected:

};//END class

#endif

