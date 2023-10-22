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
    "n_x_z",
    &astrea::population::boltzmann_distribution::n_x_z,
    "Calculates LTE electrons population using Boltzmann distribution at\n"
    "coordinate x for element z.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param g_z: Statistical weights for element z in 1.\n"
    "Axis 0: Term.\n"
    ":param E_z: Energies for element z in eV.\n"
    "Axis 0: Term.\n"
    ":return: Electrons population at point x for element z in 1.\n"
    "Axis 0: Term.\n",
    py::arg("T_x"),
    py::arg("g_z"),
    py::arg("E_z")
  );

  m.def(
    "n_x",
    &astrea::population::boltzmann_distribution::n_x,
    "Calculates LTE electrons population using Boltzmann distribution at\n"
    "coordinate x.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    ":return: Electrons population at point x in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n",
    py::arg("T_x"),
    py::arg("g"),
    py::arg("E")
  );

  m.def(
    "n",
    &astrea::population::boltzmann_distribution::n,
    "Calculates LTE electrons population using Boltzmann distribution across all\n"
    "spatial points.\n"
    "\n"
    ":param T: Temperatures in K.\n"
    "Axis 0: Coordinate index.\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    ":return: Electrons population in 1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Term.\n",
    py::arg("T"),
    py::arg("g"),
    py::arg("E")
  );
}


}