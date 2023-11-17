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
    "alpha_nu",
    &astrea::optics::alpha_nu,
    "Absorption coefficient.\n"
    "\n"
    ":param n: Element number density in cm-3.\n"
    ":param g_K: Statistical weights in 1.\n"
    ":param E_K: Energies in eV.\n"
    ":param A_KK: Spontaneous emission rates in s-1.\n"
    ":param nu: Frequency in s-1.\n"
    ":return: Absorption coefficient in au-1.\n",
    py::arg("n"),
    py::arg("g_K"),
    py::arg("E_K"),
    py::arg("A_KK"),
    py::arg("nu")
  );

  m.def(
    "alpha_nu_X",
    &astrea::optics::alpha_nu_X,
    "Absorption coefficients.\n"
    "\n"
    ":param n_X: Element number densities in cm-3.\n"
    ":param g_K: Statistical weights in 1.\n"
    ":param E_K: Energies in eV.\n"
    ":param A_KK: Spontaneous emission rates in s-1.\n"
    ":param nu: Frequency in s-1.\n"
    ":return: Absorption coefficients in au-1.\n",
    py::arg("n_X"),
    py::arg("g_K"),
    py::arg("E_K"),
    py::arg("A_KK"),
    py::arg("nu")
  );
}


}