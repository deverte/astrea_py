#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::optics {


inline void absorption_coefficient(py::module_& m) {
  m.doc() =
    "Absorption coefficient.\n"
  ;

  m.def(
    "alpha_nu_E",
    &astrea::optics::absorption_coefficient::alpha_nu_E,
    "Absorption coefficients.\n"
    "\n"
    ":param n: Element number density in cm-3.\n"
    ":param g_j: Statistical weight of level j in 1.\n"
    ":param g_i: Statistical weight of level i in 1.\n"
    ":param nu_ij: Frequency in s-1.\n"
    ":param A_ji: Spontaneous emission rate in s-1.\n"
    ":param H_E: Voigt function in s.\n"
    ":return: Absorption coefficients in au-1.\n",
    py::arg("n"),
    py::arg("g_j"),
    py::arg("g_i"),
    py::arg("nu_ij"),
    py::arg("A_ji"),
    py::arg("H_E")
  );

  m.def(
    "alpha_nu_XE",
    &astrea::optics::absorption_coefficient::alpha_nu_XE,
    "Absorption coefficients.\n"
    "\n"
    ":param n_X: Element number densities in cm-3.\n"
    ":param g_j: Statistical weight of level j in 1.\n"
    ":param g_i: Statistical weight of level i in 1.\n"
    ":param nu_ij: Frequency in s-1.\n"
    ":param A_ji: Spontaneous emission rate in s-1.\n"
    ":param H_E: Voigt function in s.\n"
    ":return: Absorption coefficients in au-1.\n",
    py::arg("n_X"),
    py::arg("g_j"),
    py::arg("g_i"),
    py::arg("nu_ij"),
    py::arg("A_ji"),
    py::arg("H_E")
  );
}


}