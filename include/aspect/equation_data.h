//-------------------------------------------------------------
//    $Id: simulator.h 232 2011-10-19 13:30:15Z bangerth $
//
//    Copyright (C) 2011 by the authors of the ASPECT code
//
//-------------------------------------------------------------
#ifndef __aspect__equation_data_h
#define __aspect__equation_data_h


#include <deal.II/base/point.h>
#include <deal.II/base/symmetric_tensor.h>



//TODO: should move into namespace aspect
namespace EquationData
{
  using namespace dealii;

  extern const double year_in_seconds;

  extern double R0, R1;
  extern double T0, T1;
  extern double apperture_angle;

  template <int dim>
  class AdiabaticConditions
  {
    public:
      AdiabaticConditions (const aspect::MaterialModel::Interface<dim> * material_model);

      double temperature (const dealii::Point<dim> &p) const;
      double pressure (const dealii::Point<dim> &p) const;

    private:
      const unsigned int n_points;
      std::vector<double> temperatures, pressures;
  };

}


#endif
