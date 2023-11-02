#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/fe_ii/cooling_efficiency.h"
#include "astrea_py/element/fe_ii/effective_collision_strengths.h"
#include "astrea_py/element/fe_ii/energies.h"
#include "astrea_py/element/fe_ii/info.h"
#include "astrea_py/element/fe_ii/oscillator_strengths.h"
#include "astrea_py/element/fe_ii/principal_quantum_numbers.h"
#include "astrea_py/element/fe_ii/statistical_weights.h"
#include "astrea_py/element/fe_ii/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void fe_ii_(py::module_& m) {
  m.doc() =
    "Fe II data by Mashonkina+2011, Bautista+1998, Zhang+1995, IRON project, NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database), Gnat+2011\n"
    "(http://wise-obs.tau.ac.il/~orlyg/ion_by_ion/).\n"
  ;

  astrea_py::element::fe_ii::cooling_efficiency(m);
  astrea_py::element::fe_ii::effective_collision_strengths(m);
  astrea_py::element::fe_ii::energies(m);
  astrea_py::element::fe_ii::info(m);
  astrea_py::element::fe_ii::oscillator_strengths(m);
  astrea_py::element::fe_ii::principal_quantum_numbers(m);
  astrea_py::element::fe_ii::statistical_weights(m);
  astrea_py::element::fe_ii::structure(m);
}


}