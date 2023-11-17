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
    ":param x_X: Coordinates in au.\n"
    ":param n_X: Element number densities in cm-3.\n"
    ":param g_K: Statistical weights in 1.\n"
    ":param E_K: Energies in eV.\n"
    ":param A_KK: Spontaneous emission rates in s-1.\n"
    ":param nu: Frequency in s-1.\n"
    ":return: Optical depth in 1.\n",
    py::arg("x_X"),
    py::arg("n_X"),
    py::arg("g_K"),
    py::arg("E_K"),
    py::arg("A_KK"),
    py::arg("nu")
  );
}


}