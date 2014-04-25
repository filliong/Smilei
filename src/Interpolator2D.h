#ifndef INTERPOLATOR2D_H
#define INTERPOLATOR2D_H


#include "Interpolator.h"

//  --------------------------------------------------------------------------------------------------------------------
//! Class Interpolator 2D
//  --------------------------------------------------------------------------------------------------------------------
class Interpolator2D : public Interpolator
{
public:
    Interpolator2D(PicParams* params, SmileiMPI* smpi): Interpolator(params, smpi) {};
    virtual ~Interpolator2D() {};
    virtual void mv_win(unsigned int shift) {i_domain_begin += shift;}

    virtual void operator() (ElectroMagn* EMfields, Particles &particles, int ipart, LocalFields* ELoc, LocalFields* BLoc) = 0;

protected:
    //! Inverse of the spatial-step
    double dx_inv_;
    double dy_inv_;
    int i_domain_begin;
    int j_domain_begin;
};

#endif
