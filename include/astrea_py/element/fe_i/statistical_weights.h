#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_i {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g",
    &astrea::element::fe_i::g,
    "Fe I statistical weights by Mashonkina+2011.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}