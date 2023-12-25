#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void collisional_excitation_regemorter(py::module_& m) {
  m.doc() =
    "Collisional excitation transitions rates using Regemorter formula.\n"
  ;

  m.def(
    "R_ij",
    &astrea::transition::collisional_excitation_regemorter::R_ij,
    "Collisional excitation transitions rate using Regemorter formula.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param g_i: Statistical weight of term i in 1.\n"
    ":param E_ij: Energy differenece between terms i and j in eV.\n"
    ":param f_vs_T: Effective collision strengths.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1:\n"
    "Effective collision strength in 1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("g_i"),
    py::arg("E_ij"),
    py::arg("f_vs_T")
  );

  m.def(
    "R_KK",
    &astrea::transition::collisional_excitation_regemorter::R_KK,
    "Collisional excitation transitions rates using Regemorter formula.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param g_K: Statistical weights in 1.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_K: Energies in eV.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order!\n"
    ":param f_vs_T_KK: Effective collision strengths.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1:\n"
    "Effective collision strength in 1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("g_K"),
    py::arg("E_K"),
    py::arg("f_vs_T_KK")
  );

  m.def(
    "R_ZKK",
    &astrea::transition::collisional_excitation_regemorter::R_ZKK,
    "Collisional excitation transitions rates using Regemorter formula.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":param f_vs_T_ZKK: Effective collision strengths.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1:\n"
    "Effective collision strength in 1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("g_ZK"),
    py::arg("E_ZK"),
    py::arg("f_vs_T_ZKK")
  );

  m.def(
    "R_XZKK",
    &astrea::transition::collisional_excitation_regemorter::R_XZKK,
    "Collisional excitation transitions rates using Regemorter formula.\n"
    "\n"
    ":param T_X: Temperature in K.\n"
    ":param N_e_X: Electron number densities in cm-3.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":param f_vs_T_ZKK: Effective collision strengths.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1:\n"
    "Effective collision strength in 1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T_X"),
    py::arg("N_e_X"),
    py::arg("g_ZK"),
    py::arg("E_ZK"),
    py::arg("f_vs_T_ZKK")
  );
}


}