#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_iii {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g",
    &astrea::element::mg_iii::g,
    "Mg III statistical weights from NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database).\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}