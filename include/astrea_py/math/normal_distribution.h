#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void normal_distribution(py::module_& m) {
  m.def(
    "P_X",
    &astrea::math::normal_distribution::P_X,
    "Normal distribution.\n"
    "\n"
    ":param x_X: x points.\n"
    ":param x_0: Center.\n"
    ":param sigma: Standard deviation.\n"
    ":return: Distribution.\n",
    py::arg("x_X"),
    py::arg("x_0"),
    py::arg("sigma")
  );
}


}