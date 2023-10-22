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
    "R_x_z_ik",
    &astrea::transition::ri::R_x_z_ik,
    "Radiative ionization (photoionization) transition rate at coordinate x for\n"
    "element z for i->k transition.\n"
    "\n"
    ":param sigma_vs_nu_z_i: Photoionization cross section of element z of term\n"
    "i in cm2.\n"
    "Axis 0: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n",
    py::arg("sigma_vs_nu_z_i"),
    py::arg("F_lambda_vs_lambda")
  );

  m.def(
    "R_x_z",
    &astrea::transition::ri::R_x_z,
    "Radiative ionization (photoionization) transition rates at coordinate x for\n"
    "element z.\n"
    "\n"
    ":param sigma_vs_nu_z: Photoionization cross sections of element z in cm2.\n"
    "Axis 0: Initial term (i-index).\n"
    "Axis 1: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 2: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Term.\n",
    py::arg("sigma_vs_nu_z"),
    py::arg("F_lambda_vs_lambda")
  );

  m.def(
    "R_x",
    &astrea::transition::ri::R_x,
    "Radiative ionization (photoionization) transition rates at coordinate x.\n"
    "\n"
    ":param sigma_vs_nu: Photoionization cross sections in cm2.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term (i-index).\n"
    "Axis 2: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 3: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element for\n"
    "each element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n",
    py::arg("sigma_vs_nu"),
    py::arg("F_lambda_vs_lambda")
  );

  m.def(
    "R",
    &astrea::transition::ri::R,
    "Radiative ionization (photoionization) transition rates at coordinate x.\n"
    "\n"
    ":param x: Any vector with shape corresponding to spatial points.\n"
    "Axis 0: Coordinate index.\n"
    ":param sigma_vs_nu: Photoionization cross sections in cm2.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term (i-index).\n"
    "Axis 2: Bivariate data (row). Row 0: Frequency in s-1. Row 1: Cross section\n"
    "in cm2.\n"
    "Axis 3: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies of the source element for\n"
    "each element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Term.\n",
    py::arg("x"),
    py::arg("sigma_vs_nu"),
    py::arg("F_lambda_vs_lambda")
  );
}


}