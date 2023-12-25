#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void spontaneous_emission(py::module_& m) {
  m.doc() =
    "Spontaneous emission transitions rates using oscillator strengths.\n"
  ;

  m.def(
    "R_ji",
    &astrea::transition::spontaneous_emission::R_ji,
    "Spontaneous emission transitions rates using oscillator strengths.\n"
    "\n"
    ":param f_ij: Oscillator strengths in 1.\n"
    ":param g_i: Statistical weight of term i in 1.\n"
    ":param g_j: Statistical weight of term j in 1.\n"
    ":param E_ij: Energy differenece between terms i and j in eV.\n"
    ":return: Transitions rate in s-1.\n",
    py::arg("f_ij"),
    py::arg("g_i"),
    py::arg("g_j"),
    py::arg("E_ij")
  );

  m.def(
    "R_KK",
    &astrea::transition::spontaneous_emission::R_KK,
    "Spontaneous emission transitions rates using oscillator strengths.\n"
    "\n"
    ":param f_KK: Oscillator strengths in 1.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param g_K: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies!\n"
    ":param E_K: Energies in eV.\n"
    "Must be sorted in ascending order!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("f_KK"),
    py::arg("g_K"),
    py::arg("E_K")
  );

  m.def(
    "R_ZKK",
    &astrea::transition::spontaneous_emission::R_ZKK,
    "Spontaneous emission transitions rates using oscillator strengths.\n"
    "\n"
    ":param f_ZKK: Oscillator strengths in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("f_ZKK"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );

  m.def(
    "R_XZKK",
    &astrea::transition::spontaneous_emission::R_XZKK,
    "Spontaneous emission transitions rates using oscillator strengths.\n"
    "\n"
    ":param x_X: Any vector with shape corresponding to spatial points.\n"
    ":param f_ZKK: Oscillator strengths in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param g_ZK: Statistical weights in 1.\n"
    "Must be sorted in ascending order over energies per element!\n"
    ":param E_ZK: Energies in eV.\n"
    "Must be sorted in ascending order per element!\n"
    ":return: Transitions rates in s-1.\n",
    py::arg("x_X"),
    py::arg("f_ZKK"),
    py::arg("g_ZK"),
    py::arg("E_ZK")
  );
}


}