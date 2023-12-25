#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void voigt_function(py::module_& m) {
  m.def(
    "H_X",
    &astrea::math::voigt_function::H_X,
    "Voigt function.\n"
    "\n"
    ":param u_X: u points.\n"
    ":param a: Normalized scaled parameter.\n"
    ":param Y: Number of integration points.\n"
    ":return: Distribution.\n",
    py::arg("u_X"),
    py::arg("a"),
    py::arg("Y") = int(1e3)
  );
}


}