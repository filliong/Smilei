/*
 * SmileIO_Cart1D.h
 *
 *  Created on: 3 juil. 2013
 *      Author: jderouil
 */

#ifndef SMILEIO_CART1D_H
#define SMILEIO_CART1D_H

#include <string>
#include <vector>

#include "SmileiIO.h"
#include "Tools.h"

class SmileiIO_Cart1D : public SmileiIO {
public:
    SmileiIO_Cart1D( PicParams* params, SmileiMPI* smpi );
    ~SmileiIO_Cart1D();

    //! Build memory and file space for HDF5 write/read
    void createPattern( PicParams* params, SmileiMPI* smpi );
    hid_t createFileSpace( int ix_isPrim );

    //! Write current field in specified group of the global file
    void writeFieldsSingleFileTime( Field* field, hid_t group_id );

    //! Write field on its own file (debug)
    void write( Field* field );

private:
    //! memory space for HDF5 write/read
    // [primDual][primDual]
    hid_t memspace_ [2];
    //! file space for HDF5 write/read
    hid_t filespace_[2];

    //! \todo Define chunk size of output for interpolated output
    //hsize_t chunk_dims[1];
    PicParams* params_;
    SmileiMPI* smpi_;

};

#endif /* SMILEIO_CART1D_H */
