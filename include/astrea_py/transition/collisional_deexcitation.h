#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void collisional_deexcitation(py::module_& m) {
  m.doc() =
    "Collisional deexcitation transitions rates from LTE (using Boltzmann\n"
    "distribution).\n"
  ;

  m.def(
    "R_x_z_ji",
    &astrea::transition::collisional_deexcitation::R_ji,
    "Collisional deexcitation transitions rates from LTE (using Boltzmann\n"
    "distribution).\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param R_ij: Collisional excitation rate in s-1.\n"
    ":param g_i: Statistical weight of term i in 1.\n"
    ":param g_j: Statistical weight of term j in 1.\n"
    ":param E_ij: Energy differenece between terms i and j in eV.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("T"),
    py::arg("R_ij"),
    py::arg("g_i"),
    py::arg("g_j"),
    py::arg("E_ij")
  );

  m.def(
    "R_KK",
    &astrea::transition::collisional_deexcitation::R_KK,
    "Collisional deexcitation transitions rates from LTE (using Boltzmann\n"
    "distribution).\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param R_KK: Collisional excitation rate in s-1.\n"
    ":param g_K: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_K: Energies in eV.\n"
    "Must be sorted in ascending order!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T"),
    py::arg("R_KK"),
    py::arg("g_K"),
    py::arg("E_K")
  );

  m.def(
    "R_ZKK",
    &astrea::transition::collisional_deexcitation::R_ZKK,
    "Collisional deexcitation transitions rates from LTE (using Boltzmann\n"
    "distribution).\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param R_ZKK: Collisional excitation rates in s-1.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T"),
    py::arg("R_ZKK"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "R_XZKK",
    &astrea::transition::collisional_deexcitation::R_XZKK,
    "Collisional deexcitation transitions rates from LTE (using Boltzmann\n"
    "distribution).\n"
    "\n"
    ":param T_X: Temperatures in K.\n"
    ":param R_XZKK: Collisional excitation rates in s-1.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T_X"),
    py::arg("R_XZKK"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );
}


}