#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_iii {


inline void oscillator_strengths(py::module_& m) {
  m.def(
    "f_KK",
    &astrea::element::mg_iii::f_KK,
    "Mg III oscillator strengths.\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Oscillator strength in 1.\n"
  );
}


}