
#include "MA_Solver1D_norm_TFSF.h"

#include "ElectroMagn.h"
#include "Field1D.h"

MA_Solver1D_norm_TFSF::MA_Solver1D_norm_TFSF( Params &params )
    : Solver1D( params ), SolverTFSF( params )
{
}

MA_Solver1D_norm_TFSF::~MA_Solver1D_norm_TFSF()
{
}

void MA_Solver1D_norm_TFSF::operator()( ElectroMagn *fields, Patch *patch, double time )
{
    vector<int> cell_start_global_index = { patch->getCellStartingGlobalIndex( 0 ) };
    vector<int> cell_end_global_index   = { patch->getCellStartingGlobalIndex( 0 ) + num_cells_per_patch[0] };

    Field1D *Ey1D = static_cast<Field1D *>( fields->Ey_ );
    Field1D *Ez1D = static_cast<Field1D *>( fields->Ez_ );
    Field1D *By1D = static_cast<Field1D *>( fields->By_ );
    Field1D *Bz1D = static_cast<Field1D *>( fields->Bz_ );

    // Lower surface
    if( number_of_scat_field_cells[0][0] >= cell_start_global_index[0] &&
        number_of_scat_field_cells[0][0] <  cell_end_global_index[0] ) {

      int local_ix = number_of_scat_field_cells[0][0] - cell_starting_global_index[0] + oversize[0];

      vector<double> pos = { global_pos_field_dual[0][0] };

      for( unsigned int n_incfield=0; n_incfield<fields->incidentFields.size(); n_incfield++ ) {

        double By = fields->incidentFields[n_incfield]->profile[4]->valueAt( pos, time );
        double Bz = fields->incidentFields[n_incfield]->profile[5]->valueAt( pos, time );

        ( *Ey1D )( local_index ) = ( *Ey1D )( local_index ) + dt_ov_dx * Bz ;
        ( *Ez1D )( local_index ) = ( *Ez1D )( local_index ) - dt_ov_dx * By ;

      }
    }

    // Higher surface
    if( number_of_scat_field_cells[0][1] >= cell_start_global_index[0] &&
        number_of_scat_field_cells[0][1] <  cell_end_global_index[0] ) {

      vector<int> local_ix = cell_ending_global_index[0] - number_of_scat_field_cells[0][1];

      vector<double> pos = global_pos_field_dual[0][1];

      for( unsigned int n_incfield=0; n_incfield<fields->incidentFields.size(); n_incfield++ ) {

        double By = fields->incidentFields[n_incfield]->profile[4]->valueAt( pos[0], time );
        double Bz = fields->incidentFields[n_incfield]->profile[5]->valueAt( pos[0], time );

        ( *Ey1D )( local_index ) = ( *Ey1D )( local_index ) - dt_ov_dx * Bz ;
        ( *Ez1D )( local_index ) = ( *Ez1D )( local_index ) + dt_ov_dx * By ;

      }
    }




}

