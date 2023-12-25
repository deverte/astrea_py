#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void collisional_ionization(py::module_& m) {
  m.doc() =
    "Collisional ionization transition.\n"
  ;

  m.def(
    "R_ik",
    &astrea::transition::collisional_ionization::R_ik,
    "Collisional ionization transition rate.\n"
    "\n"
    ":param sigma_vs_v: Collisional ionization cross section.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Cross\n"
    "section in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param f_vs_v: Velocities distribution.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Velocities\n"
    "distribution in km-1 s.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param v_ij: Velocity corresponding to line center in km s-1.\n"
    ":param N_e: Electrons number density in cm-3.\n"
    ":return: Transition rates in s-1.\n",
    py::arg("sigma_vs_v"),
    py::arg("f_vs_v"),
    py::arg("v_ij"),
    py::arg("N_e")
  );

  m.def(
    "R_K",
    &astrea::transition::collisional_ionization::R_K,
    "Collisional ionization transition rates.\n"
    "\n"
    ":param sigma_vs_v_K: Collisional ionization cross section.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Cross\n"
    "section in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param f_vs_v: Velocities distribution.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Velocities\n"
    "distribution in km-1 s.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param v_K: Velocities corresponding to line centers in km s-1.\n"
    ":param N_e: Electrons number density in cm-3.\n"
    ":return: Transition rates in s-1.\n",
    py::arg("sigma_vs_v_K"),
    py::arg("f_vs_v"),
    py::arg("v_K"),
    py::arg("N_e")
  );

  m.def(
    "R_ZK",
    &astrea::transition::collisional_ionization::R_ZK,
    "Collisional ionization transition rate.\n"
    "\n"
    ":param sigma_vs_v_ZK: Collisional ionization cross section.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Cross\n"
    "section in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param f_vs_v: Velocities distribution.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Velocities\n"
    "distribution in km-1 s.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param v_ZK: Velocities corresponding to line centers in km s-1.\n"
    ":param N_e: Electrons number density in cm-3.\n"
    ":return: Transition rates in s-1.\n",
    py::arg("sigma_vs_v_ZK"),
    py::arg("f_vs_v"),
    py::arg("v_ZK"),
    py::arg("N_e")
  );

  m.def(
    "R_XZK",
    &astrea::transition::collisional_ionization::R_XZK,
    "Collisional ionization transition rate.\n"
    "\n"
    ":param sigma_vs_v_ZK: Collisional ionization cross section.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Cross\n"
    "section in cm2.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param f_vs_v: Velocities distribution.\n"
    "Axis 0: Bivariate data (row). Row 0: Velocities in km s-1. Row 1: Velocities\n"
    "distribution in km-1 s.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over velocities.\n"
    ":param v_ZK: Velocities corresponding to line centers in km s-1.\n"
    ":param N_e_X: Electrons number densities in cm-3.\n"
    ":return: Transition rates in s-1.\n",
    py::arg("sigma_vs_v_ZK"),
    py::arg("f_vs_v"),
    py::arg("v_ZK"),
    py::arg("N_e_X")
  );
}


}