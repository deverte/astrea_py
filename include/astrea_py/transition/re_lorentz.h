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
    "R_x_z_ij",
    &astrea::transition::re_lorentz::R_x_z_ij,
    "Radiative excitation (photoexcitation) transition rate using Lorentz line\n"
    "shape at coordinate x for element z for i->j transition.\n"
    "\n"
    ":param g_z_i: Statistical weight of element z of term i in 1.\n"
    ":param g_z_j: Statistical weight of element z of term j in 1.\n"
    ":param E_z_ij: Energies differenece of element z between terms i and j in eV.\n"
    ":param A_z_ji: Spontaneous emission rate of element z for j->i transition in\n"
    "s-1.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("g_z_i"),
    py::arg("g_z_j"),
    py::arg("E_z_ij"),
    py::arg("A_z_ji"),
    py::arg("F_lambda_vs_lambda")
  );

  m.def(
    "R_x_z",
    &astrea::transition::re_lorentz::R_x_z,
    "Radiative excitation (photoexcitation) transition rates using Lorentz line\n"
    "shape at coordinate x for element z.\n"
    "\n"
    ":param g_z: Statistical weights of element z in 1.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_z: Energies of element z in eV.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order!\n"
    ":param A_z: Spontaneous emission rates of element z in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n"
    "Must be sorted in ascending order over energies for both axes.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row).\n"
    "Row 0: Wavelength in nm. Row 1: Spectral irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("g_z"),
    py::arg("E_z"),
    py::arg("A_z"),
    py::arg("F_lambda_vs_lambda")
  );

  m.def(
    "R_x",
    &astrea::transition::re_lorentz::R_x,
    "Radiative excitation (photoexcitation) transition rates using Lorentz line\n"
    "shape at coordinate x.\n"
    "\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":param A: Spontaneous emission rates in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    "Must be sorted in ascending order over energies for both axes for each\n"
    "element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n",
    py::arg("g"),
    py::arg("E"),
    py::arg("A"),
    py::arg("F_lambda_vs_lambda")
  );

  m.def(
    "R",
    &astrea::transition::re_lorentz::R,
    "Radiative excitation (photoexcitation) transition rates using Lorentz line\n"
    "shape at coordinate x.\n"
    "\n"
    ":param x: Any vector with shape corresponding to spatial points.\n"
    "Axis 0: Coordinate index.\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":param A: Spontaneous emission rates in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    "Must be sorted in ascending order over energies for both axes for each\n"
    "element.\n"
    ":param F_lambda_vs_lambda: Spectrum.\n"
    "Axis 0: Bivariate data (row). Row 0: Wavelength in nm. Row 1: Spectral\n"
    "irradiance in W m-2 nm-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n",
    py::arg("x"),
    py::arg("g"),
    py::arg("E"),
    py::arg("A"),
    py::arg("F_lambda_vs_lambda")
  );
}


}