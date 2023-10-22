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
    "R_x_z_ij",
    &astrea::transition::ce::R_x_z_ij,
    "Collisional excitation transitions rate at coordinate x for element z for\n"
    "i->j transition.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":param C_vs_T_z_ij: Collision rate coefficient of element z for i->j\n"
    "transition.\n"
    "Axis 0: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 1: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("T_x"),
    py::arg("N_e_x"),
    py::arg("C_vs_T_z_ij")
  );

  m.def(
    "R_x_z",
    &astrea::transition::ce::R_x_z,
    "Collisional excitation transitions rate at coordinate x for element z.\n"
    "\n"
    ":param T_x: Temperature at coordinate x in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":param C_vs_T_z: Collision rate coefficient of element z.\n"
    "Axis 0: Initial term (i-index).\n"
    "Axis 1: Final term (j-index).\n"
    "Axis 2: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 3: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("T_x"),
    py::arg("N_e_x"),
    py::arg("C_vs_T_z")
  );

  m.def(
    "R_x",
    &astrea::transition::ce::R_x,
    "Collisional excitation transitions rate at coordinate x.\n"
    "\n"
    ":param T_x: Temperature in K.\n"
    ":param N_e_x: Electron number density at coordinate x in cm-3.\n"
    ":param C_vs_T: Collision rate coefficients.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term (i-index).\n"
    "Axis 2: Final term (j-index).\n"
    "Axis 3: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 4: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n",
    py::arg("T_x"),
    py::arg("N_e_x"),
    py::arg("C_vs_T")
  );

  m.def(
    "R",
    &astrea::transition::ce::R,
    "Collisional excitation transitions rates.\n"
    "\n"
    ":param T: Temperatures in K. Axis 0: Coordinate index.\n"
    ":param N_e: Electron number densities in cm-3.\n"
    "Axis 0: Coordinate index.\n"
    ":param C_vs_T: Collision rate coefficients.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term (i-index).\n"
    "Axis 2: Final term (j-index).\n"
    "Axis 3: Bivariate data (row). Row 0: Temperature in K. Row 1: Collision rate\n"
    "coefficient in cm3 s-1.\n"
    "Axis 4: Bivariate pair index (column).\n"
    "Must be sorted in ascending order over energies!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n",
    py::arg("T"),
    py::arg("N_e"),
    py::arg("C_vs_T")
  );
}


}