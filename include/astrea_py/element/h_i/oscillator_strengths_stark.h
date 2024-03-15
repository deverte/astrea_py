#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_i {


inline void oscillator_strengths_stark(py::module_& m) {
  auto oscillator_strengths_stark =
    m.def_submodule("oscillator_strengths_stark");

  oscillator_strengths_stark.def(
    "f_KK",
    &astrea::element::h_i::oscillator_strengths_stark::f_KK,
    "H I oscillator strengths (Stark profile) by Mashonkina+2008.\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Oscillator strength in 1.\n"
  );
}


}