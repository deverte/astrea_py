#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/h_ii/cooling_efficiency.h"
#include "astrea_py/element/h_ii/energies.h"
#include "astrea_py/element/h_ii/info.h"
#include "astrea_py/element/h_ii/principal_quantum_numbers.h"
#include "astrea_py/element/h_ii/statistical_weights.h"
#include "astrea_py/element/h_ii/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void h_ii_(py::module_& m) {
  m.doc() =
    "H II data by Mashonkina+2008, NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database).\n"
  ;

  astrea_py::element::h_ii::cooling_efficiency(m);
  astrea_py::element::h_ii::energies(m);
  astrea_py::element::h_ii::info(m);
  astrea_py::element::h_ii::principal_quantum_numbers(m);
  astrea_py::element::h_ii::statistical_weights(m);
  astrea_py::element::h_ii::structure(m);
}


}