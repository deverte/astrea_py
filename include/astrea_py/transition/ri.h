#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void ri(py::module_& m) {
  m.doc() = "Radiative ionization transition.";

  m.def(
    "R_x_z_ik",
    &astrea::transition::ri::R_x_z_ik,
    "Radiative ionization (photoionization) transition rate at coordinate x for\n"
    "element z for i->k transition.\n"
    "\n"
    ":param sigma_z_k: Photoionization cross section of element z of term k in cm2.\n"
    ":param F_lambda: Spectrum. Row 0: wavelengths in nm. Row 1: spectral flux\n"
    "density in W m-2 nm-1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("sigma_z_k"),
    py::arg("F_lambda")
  );

  m.def(
    "R_x_z",
    &astrea::transition::ri::R_x_z,
    "Radiative ionization (photoionization) transition rates at coordinate x for\n"
    "element z.\n"
    "\n"
    ":param sigma_z: Photoionization cross sections of element z in cm2. Must be\n"
    "sorted in ascending order over energies of the source element.\n"
    ":param F_lambda: Spectrum. Row 0: wavelengths in nm. Row 1: spectral flux\n"
    "density in W m-2 nm-1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("sigma_z"),
    py::arg("F_lambda")
  );

  m.def(
    "R_x",
    &astrea::transition::ri::R_x,
    "Radiative ionization (photoionization) transition rates at coordinate x.\n"
    "\n"
    ":param sigma: Photoionization cross sections in cm2. Must be\n"
    "sorted in ascending order over energies of the source element for each\n"
    "element.\n"
    ":param F_lambda: Spectrum. Row 0: wavelengths in nm. Row 1: spectral flux\n"
    "density in W m-2 nm-1.\n"
    ":return: Transition rate in s-1.\n",
    py::arg("sigma"),
    py::arg("F_lambda")
  );
}


}