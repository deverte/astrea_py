#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_i {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g_K",
    &astrea::element::h_i::g_K,
    "H I statistical weights by Mashonkina+2008.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}