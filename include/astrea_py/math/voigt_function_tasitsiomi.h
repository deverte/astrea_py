#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void voigt_function_tasitsiomi(py::module_& m) {
  m.def(
    "H_X",
    &astrea::math::voigt_function_tasitsiomi::H_X,
    "Voigt function Tasitsiomi approximation.\n"
    "\n"
    ":param u_X: u points.\n"
    ":param a: Normalized scaled parameter.\n"
    ":return: Distribution.\n",
    py::arg("u_X"),
    py::arg("a")
  );
}


}