#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void re_lorentz(py::module_& m) {
  m.doc() =
    "Radiative excitation (photoexcitation) transitions rates using Lorentz line\n"
    "shape.\n"
  ;

  m.def(
    "R_ij",
    &astrea::transition::re_lorentz::R_ij,
    "Radiative excitation (photoexcitation) transition rate using Lorentz line\n"
    "shape.\n"
    "\n"
    ":param g_i: Statistical weight term i in 1.\n"
    ":param g_j: Statistical weight of term j in 1.\n"
    ":param E_ij: Energies differenece between terms i and j in eV.\n"
    ":param A_ji: Spontaneous emission rate for j->i transition in s-1.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("g_i"),
    py::arg("g_j"),
    py::arg("E_ij"),
    py::arg("A_ji"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau")
  );

  m.def(
    "R_KK",
    &astrea::transition::re_lorentz::R_KK,
    "Radiative excitation (photoexcitation) transition rates using Lorentz line\n"
    "shape.\n"
    "\n"
    ":param g_K: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_K: Energies in eV.\n"
    "Must be sorted in ascending order!\n"
    ":param A_KK: Spontaneous emission rates in s-1.\n"
    "Must be sorted in ascending order over energies for both axes.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row).\n"
    "Row 0: Wavelength in nm. Row 1: Spectral irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("g_K"),
    py::arg("E_K"),
    py::arg("A_KK"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau")
  );

  m.def(
    "R_ZKK",
    &astrea::transition::re_lorentz::R_ZKK,
    "Radiative excitation (photoexcitation) transition rates using Lorentz line\n"
    "shape.\n"
    "\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":param A_ZKK: Spontaneous emission rates in s-1.\n"
    "Must be sorted in ascending order over energies for both axes for each\n"
    "element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("g_ZK"),
    py::arg("E_ZK"),
    py::arg("A_ZKK"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau")
  );

  m.def(
    "R_XZKK",
    &astrea::transition::re_lorentz::R_XZKK,
    "Radiative excitation (photoexcitation) transition rates using Lorentz line\n"
    "shape.\n"
    "\n"
    ":param x_X: Any vector with shape corresponding to spatial points.\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":param A_ZKK: Spontaneous emission rates in s-1.\n"
    "Must be sorted in ascending order over energies for both axes for each\n"
    "element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau_X: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("x_X"),
    py::arg("g_ZK"),
    py::arg("E_ZK"),
    py::arg("A_ZKK"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau_X")
  );
}


}