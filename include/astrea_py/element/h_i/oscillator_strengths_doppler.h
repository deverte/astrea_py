#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_i {


inline void oscillator_strengths_doppler(py::module_& m) {
  auto oscillator_strengths_doppler =
    m.def_submodule("oscillator_strengths_doppler");

  oscillator_strengths_doppler.def(
    "f_KK",
    &astrea::element::h_i::oscillator_strengths_doppler::f_KK,
    "H I oscillator strengths (Doppler profile) by Mashonkina+2008.\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Oscillator strength in 1.\n"
  );
}


}