#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void cd_regemorter(py::module_& m) {
  m.doc() =
    "Collisional de-excitation transitions rates using Regemorter formula.";

  m.def(
    "R_x_z_ji",
    &astrea::transition::cd_regemorter::R_x_z_ji,
    "Collisional de-excitation transitions rate using Regemorter formula at\n"
    "coordinate x for element z for j->i transition.\n"
    "\n"
    ":param g_z_j: Statistical weight of element z of term j in 1.\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("g_z_j"),
    py::arg("T_x"),
    py::arg("N_e_x")
  );

  m.def(
    "R_x_z",
    &astrea::transition::cd_regemorter::R_x_z,
    "Collisional de-excitation transitions rates using Regemorter formula at\n"
    "coordinate x for element z.\n"
    "\n"
    ":param g_z: Statistical weights of element z in 1. Must be sorted in ascending\n"
    "order over energies!\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("g_z"),
    py::arg("T_x"),
    py::arg("N_e_x")
  );

  m.def(
    "R_x",
    &astrea::transition::cd_regemorter::R_x,
    "Collisional de-excitation transitions rates using Regemorter formula at\n"
    "coordinate x.\n"
    "\n"
    ":param g: Statistical weights in 1. Must be sorted in ascending order over\n"
    "energies per element!\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("g"),
    py::arg("T_x"),
    py::arg("N_e_x")
  );
}


}