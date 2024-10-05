#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::n_i {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g_K",
    &astrea::element::n_i::g_K,
    "N I statistical weights by Mashonkina+2024.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}