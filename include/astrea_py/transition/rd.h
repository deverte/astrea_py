#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void rd(py::module_& m) {
  m.doc() =
    "Radiative de-excitation transitions rates using oscillator strengths.\n"
  ;

  m.def(
    "R_x_z_ji",
    &astrea::transition::rd::R_x_z_ji,
    "Radiative de-excitation transitions rates using oscillator strengths at\n"
    "coordinate x for element z for j->i transition.\n"
    "\n"
    ":param f_z_ij: Oscillator strengths of element z for i->j transition in 1.\n"
    ":param g_z_i: Statistical weight of element z of term i in 1.\n"
    ":param g_z_j: Statistical weight of element z of term j in 1.\n"
    ":param E_z_ij: Energy differenece of element z between terms i and j in eV.\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("f_z_ij"),
    py::arg("g_z_i"),
    py::arg("g_z_j"),
    py::arg("E_z_ij")
  );

  m.def(
    "R_x_z",
    &astrea::transition::rd::R_x_z,
    "Radiative de-excitation transitions rates using oscillator strengths at\n"
    "coordinate x for element z.\n"
    "\n"
    ":param f_z: Oscillator strengths of element z in 1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param g_z: Statistical weights of element z in 1.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_z: Energies of element z in eV.\n"
    "Axis 0: Term.\n"
    "Must be sorted in ascending order!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("f_z"),
    py::arg("g_z"),
    py::arg("E_z")
  );

  m.def(
    "R_x",
    &astrea::transition::rd::R_x,
    "Radiative de-excitation transitions rates using oscillator strengths at\n"
    "coordinate x.\n"
    "\n"
    ":param f: Oscillator strengths in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n",
    py::arg("f"),
    py::arg("g"),
    py::arg("E")
  );

  m.def(
    "R",
    &astrea::transition::rd::R,
    "Radiative de-excitation transitions rates using oscillator strengths.\n"
    "\n"
    ":param x: Any vector with shape corresponding to spatial points.\n"
    "Axis 0: Coordinate index.\n"
    ":param f: Oscillator strengths in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param g: Statistical weights in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E: Energies in eV.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n",
    py::arg("x"),
    py::arg("f"),
    py::arg("g"),
    py::arg("E")
  );
}


}