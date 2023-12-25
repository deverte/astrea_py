#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i {


inline void statistical_weights(py::module_& m) {
  m.def(
    "g_K",
    &astrea::element::o_i::g_K,
    "O I statistical weights by Przybilla2000, Sitnova2012, Sitnova2017.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Statistical weight in 1.\n"
  );
}


}