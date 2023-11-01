#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/fe_iii/energies.h"
#include "astrea_py/element/fe_iii/info.h"
#include "astrea_py/element/fe_iii/principal_quantum_numbers.h"
#include "astrea_py/element/fe_iii/statistical_weights.h"
#include "astrea_py/element/fe_iii/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void fe_iii_(py::module_& m) {
  m.doc() =
    "Fe III data by NIST (https://www.nist.gov/pml/atomic-spectra-database).\n"
  ;

  astrea_py::element::fe_iii::energies(m);
  astrea_py::element::fe_iii::info(m);
  astrea_py::element::fe_iii::principal_quantum_numbers(m);
  astrea_py::element::fe_iii::statistical_weights(m);
  astrea_py::element::fe_iii::structure(m);
}


}