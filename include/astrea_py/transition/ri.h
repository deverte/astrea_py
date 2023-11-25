#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void ri(py::module_& m) {
  m.doc() =
    "Radiative ionization transition.\n"
  ;

  m.def(
    "R_ik",
    &astrea::transition::ri::R_ik,
    "Radiative ionization (photoionization) transition rate.\n"
    "\n"
    ":param sigma_vs_nu: Photoionization cross section.\n"
    "Axis 0: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("sigma_vs_nu"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau")
  );

  m.def(
    "R_K",
    &astrea::transition::ri::R_K,
    "Radiative ionization (photoionization) transition rates.\n"
    "\n"
    ":param sigma_vs_nu_K: Photoionization cross sections.\n"
    "Axis 0: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("sigma_vs_nu_K"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau")
  );

  m.def(
    "R_ZK",
    &astrea::transition::ri::R_ZK,
    "Radiative ionization (photoionization) transition rates.\n"
    "\n"
    ":param sigma_vs_nu_ZK: Photoionization cross sections.\n"
    "Axis 0: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("sigma_vs_nu_ZK"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau")
  );

  m.def(
    "R_XZK",
    &astrea::transition::ri::R_XZK,
    "Radiative ionization (photoionization) transition rates.\n"
    "\n"
    ":param x_X: Any vector with shape corresponding to spatial points.\n"
    ":param sigma_vs_nu_ZK: Photoionization cross sections in cm2.\n"
    "Axis 0: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param tau_X: Optical depth in 1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("x_X"),
    py::arg("sigma_vs_nu_ZK"),
    py::arg("F_lambda_vs_lambda"),
    py::arg("tau_X")
  );
}


}