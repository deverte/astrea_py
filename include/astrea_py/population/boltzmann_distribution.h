#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::population {


inline void boltzmann_distribution(py::module_& m) {
  m.doc() =
    "LTE electrons population calculation."
  ;

  m.def(
    "n_K",
    &astrea::population::boltzmann_distribution::n_K,
    "Calculates LTE electrons population using Boltzmann distribution.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param g_K: Statistical weights in 1.\n"
    ":param E_K: Energies in eV.\n"
    ":return: Electrons population in 1.\n",
    py::arg("T"),
    py::arg("g_K"),
    py::arg("E_K")
  );

  m.def(
    "n_ZK",
    &astrea::population::boltzmann_distribution::n_ZK,
    "Calculates LTE electrons population using Boltzmann distribution.\n"
    "\n"
    ":param T: Temperature at coordinate x in K.\n"
    ":param g: Statistical weights in 1.\n"
    ":param E: Energies in eV.\n"
    ":return: Electrons population at point x in 1.\n",
    py::arg("T"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "n_XZK",
    &astrea::population::boltzmann_distribution::n_XZK,
    "Calculates LTE electrons population using Boltzmann distribution.\n"
    "\n"
    ":param T_X: Temperatures in K.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Electrons population in 1.\n",
    py::arg("T_X"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );
}


}