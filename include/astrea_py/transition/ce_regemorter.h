#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void ce_regemorter(py::module_& m) {
  m.doc() =
    "Collisional excitation transitions rates using Regemorter formula.\n"
  ;

  m.def(
    "R_x_z_ij",
    &astrea::transition::ce_regemorter::R_x_z_ij,
    "Collisional excitation transitions rate using Regemorter formula at\n"
    "coordinate x for element z for i->j transition.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":param g_z_i: Statistical weight of element z of term i in 1.\n"
    ":param E_z_ij: Energy differenece of element z between terms i and j in eV.\n"
    ":param f_vs_T_z_ij: Effective collision strengths of element z for i->j\n"
    "transition.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1:\n"
    "Effective collision strength in 1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("T_x"),
    py::arg("N_e_x"),
    py::arg("g_z_i"),
    py::arg("E_z_ij"),
    py::arg("f_vs_T_z_ij")
  );

  m.def(
    "R_x_z",
    &astrea::transition::ce_regemorter::R_x_z,
    "Collisional excitation transitions rates using Regemorter formula at\n"
    "coordinate x for element z.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":param g_z: Statistical weights of element z in 1.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_z: Energies of element z in eV.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order!\n"
    ":param f_vs_T_z: Effective collision strengths of element z.\n"
    "Axis 0: Initial term (i-index).\n"
    "Axis 1: Final term (j-index).\n"
    "Axis 2: Bivariate data (row). Row 0: Temperature in K. Row 1: Effective\n"
    "collision strength in 1.\n"
    "Axis 3: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("T_x"),
    py::arg("N_e_x"),
    py::arg("g_z"),
    py::arg("E_z"),
    py::arg("f_vs_T_z")
  );

  m.def(
    "R_x",
    &astrea::transition::ce_regemorter::R_x,
    "Collisional excitation transitions rates using Regemorter formula at\n"
    "coordinate x.\n"
    "\n"
    ":param T_x: Temperature in K.\n"
    ":param N_e_x: Electron number density  at coordinate x in cm-3.\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":param f_vs_T: Effective collision strengths.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term (i-index).\n"
    "Axis 2: Final term (j-index).\n"
    "Axis 3: Bivariate data (row). Row 0: Temperature in K. Row 1: Effective\n"
    "collision strength in 1.\n"
    "Axis 4: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n",
    py::arg("T_x"),
    py::arg("N_e_x"),
    py::arg("g"),
    py::arg("E"),
    py::arg("f_vs_T")
  );

  m.def(
    "R",
    &astrea::transition::ce_regemorter::R,
    "Collisional excitation transitions rates using Regemorter formula.\n"
    "\n"
    ":param T: Temperature in K.\n"
    "Axis 0: Coordinate index.\n"
    ":param N_e: Electron number densities in cm-3.\n"
    "Axis 0: Coordinate index.\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":param f_vs_T: Effective collision strengths.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term (i-index).\n"
    "Axis 2: Final term (j-index).\n"
    "Axis 3: Bivariate data (row). Row 0: Temperature in K. Row 1: Effective\n"
    "collision strength in 1.\n"
    "Axis 4: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("g"),
    py::arg("E"),
    py::arg("f_vs_T")
  );
}


}