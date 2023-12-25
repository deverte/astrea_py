#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void radiative_recombination(py::module_& m) {
  m.doc() =
    "Radiative recombination transition.\n"
  ;

  m.def(
    "R_ZK",
    &astrea::transition::radiative_recombination::R_ZK,
    "Radiative recombination transition rates calculation using LTE.\n"
    "\n"
    ":param R_ZK: Photoionization rates in s-1.\n"
    ":param T: Temperature in K.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Transition rates in s-1.\n",
    py::arg("R_ZK"),
    py::arg("T"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "R_XZK",
    &astrea::transition::radiative_recombination::R_XZK,
    "Radiative recombination transition rates calculation using LTE.\n"
    "\n"
    ":param R_XZK: Photoionization rates in s-1.\n"
    ":param T_X: Temperatures in K.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Transition rates in s-1.\n",
    py::arg("R_XZK"),
    py::arg("T_X"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );
}


}