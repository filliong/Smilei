/*
 * SmileiIO.h
 *
 *  Created on: 3 juil. 2013
 *      Author: jderouil
 */

#ifndef SMILEIIO_H
#define SMILEIIO_H

#include <string>
#include <vector>
#include <hdf5.h>

class PicParams;
class SmileiMPI;
class ElectroMagn;
class Field;
class Species;

class SmileiIO {
public:
    SmileiIO( PicParams* params, SmileiMPI* smpi );
    virtual ~SmileiIO();

    //! Write all fields of all time step in the same file
    void writeAllFieldsSingleFileTime( ElectroMagn* EMfields, int itime );
    //! Write current field in specified group of the global file
    virtual void writeFieldsSingleFileTime( Field* field, hid_t group_id ) = 0;

    //! Each MPI process writes is particles in its own file
    void writePlasma( std::vector<Species*> vecSpecies, double time, SmileiMPI* smpi );

    //! Id of "Fields.h5", contains all fields per timestep
    hid_t global_file_id_;

    //! Property list for collective dataset write.
    hid_t write_plist;

    //! Id of "particles-mpirank.h5", contains particles of current mpirank
    hid_t  partFile_id;

    //! Particles output in progress
    unsigned int nDatasetSpecies;
    hid_t* partDataset_id;  /* identifiers */
    hid_t partMemSpace;
    int particleSize;

    //! Write field on its own file (debug)
    virtual void write( Field* field ) = 0;

private:
};

#endif /* SMILEI_OUTPUT_H_ */
