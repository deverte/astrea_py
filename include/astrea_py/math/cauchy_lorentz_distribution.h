#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void cauchy_lorentz_distribution(py::module_& m) {
  m.def(
    "P_X",
    &astrea::math::cauchy_lorentz_distribution::P_X,
    "Cauchy-Lorentz distribution.\n"
    "\n"
    ":param x_X: x points.\n"
    ":param x_0: Center.\n"
    ":param gamma: Scale parameter.\n"
    ":return: Distribution.\n",
    py::arg("x_X"),
    py::arg("x_0"),
    py::arg("gamma")
  );
}


}