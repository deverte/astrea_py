#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_i {


inline void oscillator_strengths(py::module_& m) {
  m.def(
    "f",
    &astrea::element::fe_i::f,
    "Fe I oscillator strengths by Mashonkina+2011.\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Oscillator strength in 1.\n"
  );
}


}