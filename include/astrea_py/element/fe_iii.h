#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/fe_iii/cooling_efficiency.h"
#include "astrea_py/element/fe_iii/effective_collision_strengths.h"
#include "astrea_py/element/fe_iii/energies.h"
#include "astrea_py/element/fe_iii/info.h"
#include "astrea_py/element/fe_iii/oscillator_strengths.h"
#include "astrea_py/element/fe_iii/photoionization_cross_sections.h"
#include "astrea_py/element/fe_iii/principal_quantum_numbers.h"
#include "astrea_py/element/fe_iii/statistical_weights.h"
#include "astrea_py/element/fe_iii/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void fe_iii_(py::module_& m) {
  m.doc() =
    "Fe III data by NIST (https://www.nist.gov/pml/atomic-spectra-database)\n"
    "Gnat+2011 (http://wise-obs.tau.ac.il/~orlyg/ion_by_ion/).\n"
  ;

  astrea_py::element::fe_iii::cooling_efficiency(m);
  astrea_py::element::fe_iii::effective_collision_strengths(m);
  astrea_py::element::fe_iii::energies(m);
  astrea_py::element::fe_iii::info(m);
  astrea_py::element::fe_iii::oscillator_strengths(m);
  astrea_py::element::fe_iii::photoionization_cross_sections(m);
  astrea_py::element::fe_iii::principal_quantum_numbers(m);
  astrea_py::element::fe_iii::statistical_weights(m);
  astrea_py::element::fe_iii::structure(m);
}


}