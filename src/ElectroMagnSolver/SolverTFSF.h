#ifndef SOLVER_H
#define SOLVER_H

#include "Params.h"

class ElectroMagn;

//  --------------------------------------------------------------------------------------------------------------------
//! Class SolverTFSF
//  --------------------------------------------------------------------------------------------------------------------
class SolverTFSF
{

public:
    //! Creator for SolverTFSF
    SolverTFSF( Params &params ) :
      number_of_scat_field_cells(params.number_of_scat_field_cells),
      oversize(params.oversize) {

      std::vector<unsigned int> n_space(params.n_space);
      if ( params.multiple_decomposition )
            n_space = params.n_space_region;


      global_pos_primal.resize(number_of_scat_field_cells.size());
      global_pos_dual.resize(number_of_scat_field_cells.size());
      num_cells_per_patch.resize(n_space.size());

      // Computes the global position where the profile has to be evaluated
      for( unsigned int dim=0; dim<number_of_scat_field_cells.size(); dim++ ) {

          num_cells_per_patch[dim] = n_space[dim] + 2*params.oversize[dim];

          double global_pos_primal_min = ( number_of_scat_field_cells[dim][0] + 1 ) * params.cell_length[dim];
          double global_pos_primal_max = ( params.n_space_global[dim] - number_of_scat_field_cells[dim][1] - 1 ) * params.cell_length[dim];

          double global_pos_dual_min = ( number_of_scat_field_cells[dim][0] + 0.5 ) * params.cell_length[dim];
          double global_pos_dual_max = ( params.n_space_global[dim] - number_of_scat_field_cells[dim][1] - 0.5 ) * params.cell_length[dim];

          global_pos_primal[dim] = { global_pos_primal_min, global_pos_primal_max };
          global_pos_dual[dim]   = { global_pos_dual_min, global_pos_dual_max };

      }
    };
    virtual ~SolverTFSF() {};

    std::vector< std::vector<int> > number_of_scat_field_cells;
    std::vector< std::vector<double> > global_pos_primal;
    std::vector< std::vector<double> > global_pos_dual;
    std::vector<int> num_cells_per_patch;
    std::vector<int> oversize;


protected:

};//END class


#endif

