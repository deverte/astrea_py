#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::optics {


inline void optical_depth(py::module_& m) {
  m.doc() =
    "Optical depth.\n"
  ;

  m.def(
    "tau",
    &astrea::optics::optical_depth::tau,
    "Optical depth.\n"
    "\n"
    ":param x_X: Coordinates (positive, over single axis in ascending order) in au.\n"
    ":param alpha_nu_X: Absorption coefficients in au-1.\n"
    ":return: Optical depth in 1.\n",
    py::arg("x_X"),
    py::arg("alpha_nu_X")
  );

  m.def(
    "tau_E",
    &astrea::optics::optical_depth::tau_E,
    "Optical depth.\n"
    "\n"
    ":param x_X: Coordinates (positive, over single axis in ascending order) in au.\n"
    ":param alpha_nu_XE: Absorption coefficients in au-1.\n"
    ":return: Optical depth in 1.\n",
    py::arg("x_X"),
    py::arg("alpha_nu_XE")
  );
}


}