#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void ce_regemorter(py::module_& m) {
  m.doc() =
    "Collisional excitation transitions rates using Regemorter formula.";

  m.def(
    "R_x_z_ij",
    &astrea::transition::ce_regemorter::R_x_z_ij,
    "Collisional excitation transitions rate using Regemorter formula at\n"
    "coordinate x for element z for i->j transition.\n"
    "\n"
    ":param g_z_i: Statistical weight of element z of term i in 1.\n"
    ":param E_z_ij: Energy differenece of element z between terms i and j in eV.\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("g_z_i"),
    py::arg("E_z_ij"),
    py::arg("T_x"),
    py::arg("N_e_x")
  );

  m.def(
    "R_x_z",
    &astrea::transition::ce_regemorter::R_x_z,
    "Collisional excitation transitions rates using Regemorter formula at\n"
    "coordinate x for element z.\n"
    "\n"
    ":param g_z: Statistical weights of element z in 1. Must be sorted in ascending\n"
    "order over energies!\n"
    ":param E_z: Energies of element z in eV. Must be sorted in ascending order!\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("g_z"),
    py::arg("E_z"),
    py::arg("T_x"),
    py::arg("N_e_x")
  );

  m.def(
    "R_x",
    &astrea::transition::ce_regemorter::R_x,
    "Collisional excitation transitions rates using Regemorter formula.\n"
    "\n"
    ":param g: Statistical weights in 1. Must be sorted in ascending order over\n"
    "energies per element!\n"
    ":param E: Energies in eV. Must be sorted in ascending order per element!\n"
    ":param T_x: Temperature in K.\n"
    ":param N_e_x: in cm-3.\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("g"),
    py::arg("E"),
    py::arg("T_x"),
    py::arg("N_e_x")
  );
}


}