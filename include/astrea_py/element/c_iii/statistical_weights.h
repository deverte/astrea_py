#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_iii {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g_K",
    &astrea::element::c_iii::g_K,
    "C III statistical weights by ?.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}