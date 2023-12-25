#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i {


inline void oscillator_strengths(py::module_& m) {
  m.def(
    "f_KK",
    &astrea::element::o_i::f_KK,
    "O I oscillator strengths by Sitnova2012, Sitnova2017.\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Oscillator strength in 1.\n"
  );
}


}