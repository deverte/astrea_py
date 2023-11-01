#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/fe_i/effective_collision_strengths.h"
#include "astrea_py/element/fe_i/energies.h"
#include "astrea_py/element/fe_i/info.h"
#include "astrea_py/element/fe_i/oscillator_strengths.h"
#include "astrea_py/element/fe_i/photoionization_cross_sections.h"
#include "astrea_py/element/fe_i/principal_quantum_numbers.h"
#include "astrea_py/element/fe_i/statistical_weights.h"
#include "astrea_py/element/fe_i/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void fe_i_(py::module_& m) {
  m.doc() =
    "Fe I data by Mashonkina+2011, Bautista+1998, NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database), IRON Project.\n"
  ;

  astrea_py::element::fe_i::effective_collision_strengths(m);
  astrea_py::element::fe_i::energies(m);
  astrea_py::element::fe_i::info(m);
  astrea_py::element::fe_i::oscillator_strengths(m);
  astrea_py::element::fe_i::photoionization_cross_sections(m);
  astrea_py::element::fe_i::principal_quantum_numbers(m);
  astrea_py::element::fe_i::statistical_weights(m);
  astrea_py::element::fe_i::structure(m);
}


}