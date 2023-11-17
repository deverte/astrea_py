#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void ce(py::module_& m) {
  m.doc() =
    "Collisional excitation transitions rates using collision rate coefficients.\n"
  ;

  m.def(
    "R_ij",
    &astrea::transition::ce::R_ij,
    "Collisional excitation transitions rate.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param C_vs_T: Collision rate coefficient.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("C_vs_T")
  );

  m.def(
    "R_KK",
    &astrea::transition::ce::R_KK,
    "Collisional excitation transitions rate.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param C_vs_T_KK: Collision rate coefficient.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("C_vs_T_KK")
  );

  m.def(
    "R_ZKK",
    &astrea::transition::ce::R_ZKK,
    "Collisional excitation transitions rate.\n"
    "\n"
    ":param T: Temperature in K.\n"
    ":param N_e: Electron number density in cm-3.\n"
    ":param C_vs_T_ZKK: Collision rate coefficients.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("C_vs_T_ZKK")
  );

  m.def(
    "R_XZKK",
    &astrea::transition::ce::R_XZKK,
    "Collisional excitation transitions rates.\n"
    "\n"
    ":param T_X: Temperatures in K.\n"
    ":param N_e_X: Electron number densities in cm-3.\n"
    ":param C_vs_T_ZKK: Collision rate coefficients.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("T_X"),
    py::arg("N_e_X"),
    py::arg("C_vs_T_ZKK")
  );
}


}