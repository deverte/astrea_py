#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::population {


inline void saha_ionization_equation(py::module_& m) {
  m.doc() =
    "LTE elements population calculation.\n"
  ;

  m.def(
    "Sigma_Z",
    &astrea::population::saha_ionization_equation::Sigma_Z,
    "Saha equation helper function.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Helper quantities in 1.\n",
    py::arg("T"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "Phi_Z",
    &astrea::population::saha_ionization_equation::Phi_Z,
    "Elements population relations N_z / N_{z + 1}.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Relative elements populations in cm3.\n",
    py::arg("T"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "Pi_Z",
    &astrea::population::saha_ionization_equation::Pi_Z,
    "Saha equation helper function.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Helper quantities in 1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "Sigma_Pi",
    &astrea::population::saha_ionization_equation::Sigma_Pi,
    "Saha equation helper function.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Helper quantity in 1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "N_Z",
    &astrea::population::saha_ionization_equation::N_Z,
    "Calculates LTE elements population using Saha equation.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Elements populations in 1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "n_ZK",
    &astrea::population::saha_ionization_equation::n_ZK,
    "Calculates LTE electrons population using Saha equation.\n"
    "\n"
    ":param n_ZK: Per element electrons populations in 1.\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Electrons populations in 1.\n",
    py::arg("n_ZK"),
    py::arg("T"),
    py::arg("N_e"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "n_XZK",
    &astrea::population::saha_ionization_equation::n_XZK,
    "Calculates LTE electrons population using Saha equation.\n"
    "\n"
    ":param n_XZK: Per element electrons populations in 1.\n"
    ":param T_X: Temperature in K.\n"
    ":param N_e_X: Electron number density in cm-3.\n"
    ":param I_Z: Ionization energies in eV.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    ":param E_ZK: Energies in eV.\n"
    ":return: Electrons populations in 1.\n",
    py::arg("n_XZK"),
    py::arg("T_X"),
    py::arg("N_e_X"),
    py::arg("I_Z"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );
}


}