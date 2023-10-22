#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void cd(py::module_& m) {
  m.doc() =
    "Collisional de-excitation transitions rates from LTE (using Boltzmann\n"
    "distribution).\n"
  ;

  m.def(
    "R_x_z_ji",
    &astrea::transition::cd::R_x_z_ji,
    "Collisional de-excitation transitions rates from LTE (using Boltzmann\n"
    "distribution) at coordinate x for element z for j->i transition.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param R_x_z_ij: Collisional excitation rate of element z for i->j transition\n"
    "at coordinate x in s-1.\n"
    ":param g_z_i: Statistical weight of element z of term i in 1.\n"
    ":param g_z_j: Statistical weight of element z of term j in 1.\n"
    ":param E_z_ij: Energy differenece of element z between terms i and j in eV.\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("T_x"),
    py::arg("R_x_z_ij"),
    py::arg("g_z_i"),
    py::arg("g_z_j"),
    py::arg("E_z_ij")
  );

  m.def(
    "R_x_z",
    &astrea::transition::cd::R_x_z,
    "Collisional de-excitation transitions rates from LTE (using Boltzmann\n"
    "distribution) at coordinate x for element z.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param R_x_z: Collisional excitation rate of element z at coordinate x in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n"
    ":param g_z: Statistical weights of element z in 1.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_z: Energies of element z in eV.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("T_x"),
    py::arg("R_x_z"),
    py::arg("g_z"),
    py::arg("E_z")
  );

  m.def(
    "R_x",
    &astrea::transition::cd::R_x,
    "Collisional de-excitation transitions rates from LTE (using Boltzmann\n"
    "distribution) at coordinate x.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param R_x: Collisional excitation rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n",
    py::arg("T_x"),
    py::arg("R_x"),
    py::arg("g"),
    py::arg("E")
  );

  m.def(
    "R",
    &astrea::transition::cd::R,
    "Collisional de-excitation transitions rates from LTE (using Boltzmann\n"
    "distribution).\n"
    "\n"
    ":param T: Temperatures in K.\n"
    "Axis 0: Coordinate index.\n"
    ":param R: Collisional excitation rates in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n",
    py::arg("T"),
    py::arg("R"),
    py::arg("g"),
    py::arg("E")
  );
}


}