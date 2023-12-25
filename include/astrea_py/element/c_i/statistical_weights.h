#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_i {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g_K",
    &astrea::element::c_i::g_K,
    "C I statistical weights by Alexeeva+2015.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}