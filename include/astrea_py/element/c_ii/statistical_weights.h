#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_ii {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g_K",
    &astrea::element::c_ii::g_K,
    "C II statistical weights by Alexeeva+2015.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}