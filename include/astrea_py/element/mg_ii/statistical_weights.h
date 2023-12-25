#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_ii {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g_K",
    &astrea::element::mg_ii::g_K,
    "Mg II statistical weights by Alexeeva+2018.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}