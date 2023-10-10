#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::population {


inline void boltzmann_distribution(py::module_& m) {
  m.doc() = "LTE electrons population calculation.";

  m.def(
    "n_x_z",
    &astrea::population::boltzmann_distribution::n_x_z,
    "Calculates LTE electrons population using Boltzmann distribution at\n"
    "coordinate x for element z.\n"
    "\n"
    ":param g_z: Statistical weights for element z in 1.\n"
    ":param E_z: Energies for element z in eV.\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":return: Electrons population in 1.\n",
    py::arg("g_z"),
    py::arg("E_z"),
    py::arg("T_x")
  );

  m.def(
    "n_x",
    &astrea::population::boltzmann_distribution::n_x,
    "Calculates LTE electrons population using Boltzmann distribution at\n"
    "coordinate x.\n"
    "\n"
    ":param g: Statistical weights in 1.\n"
    ":param E: Energies in eV.\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":return: Electrons population in 1.\n",
    py::arg("g"),
    py::arg("E"),
    py::arg("T_x")
  );
}


}