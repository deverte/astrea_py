#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::population {


inline void balance_equation(py::module_& m) {
  m.doc() =
    "NLTE electrons population calculation using balance equation.\n"
  ;

  m.def(
    "Q_KK",
    &astrea::population::balance_equation::Q_KK,
    "Builds single transitions rates matrix Q from S.\n"
    "\n"
    ":param S_KK: Transitions rates matrix in s-1.\n"
    ":return: Single transitions rates matrix in s-1.\n",
    py::arg("S_KK")
  );

  m.def(
    "P_KK",
    &astrea::population::balance_equation::P_KK,
    "Calculates single transition operator using transition rates matrix.\n"
    "\n"
    ":param Q_KK: Transition rates matrix in s-1.\n"
    ":param Delta_t: Time difference in s.\n"
    ":return: Transition operator in s-1.\n",
    py::arg("Q_KK"),
    py::arg("Delta_t")
  );

  m.def(
    "p_t_plus_Delta_t_K",
    &astrea::population::balance_equation::p_t_plus_Delta_t_K,
    "Calculates current electrons populations single vector using previous\n"
    "electrons populations single vector and single transition operator P.\n"
    "\n"
    ":param p_K: Previous electrons population in 1.\n"
    ":param P_KK: Transition operator in s-1.\n"
    ":return: Single electrons population vector in 1.\n",
    py::arg("p_K"),
    py::arg("P_KK")
  );

  m.def(
    "p_K",
    &astrea::population::balance_equation::p_K,
    "Builds single electrons population vector p_t from set of n_t vectors.\n"
    "\n"
    ":param n_ZK: Previous electrons population in 1.\n"
    ":return: Single electrons population vector in 1.\n",
    py::arg("n_ZK")
  );

  m.def(
    "S_KK",
    &astrea::population::balance_equation::S_KK,
    "Builds single transitions rates matrix S from set of R matrices.\n"
    "\n"
    ":param R_ij_ZKK: Excitation transitions rates in s-1.\n"
    ":param R_ji_ZKK: De-excitation transitions rates in s-1.\n"
    ":param R_ik_ZK: Ionization transitions rates in s-1.\n"
    ":param R_ki_ZK: Recombination transitions rates in s-1.\n"
    ":return: Single transitions rates matrix in s-1.\n",
    py::arg("R_ij_ZKK"),
    py::arg("R_ji_ZKK"),
    py::arg("R_ik_ZK"),
    py::arg("R_ki_ZK")
  );

  m.def(
    "n_t_plus_Delta_t_ZK",
    &astrea::population::balance_equation::n_t_plus_Delta_t_ZK,
    "Calculates NLTE electrons population using balance equation.\n"
    "\n"
    ":param n_ZK: Previous electrons population in 1.\n"
    ":param R_ij_ZKK: Excitation transitions rates in s-1.\n"
    ":param R_ji_ZKK: De-excitation transitions rates in s-1.\n"
    ":param R_ik_ZK: Ionization transitions rates in s-1.\n"
    ":param R_ki_ZK: Recombination transitions rates in s-1.\n"
    ":param Delta_t: Time difference in s.\n"
    ":return: Electrons population in 1.\n",
    py::arg("n_ZK"),
    py::arg("R_ij_ZKK"),
    py::arg("R_ji_ZKK"),
    py::arg("R_ik_ZK"),
    py::arg("R_ki_ZK"),
    py::arg("Delta_t")
  );

  m.def(
    "n_t_plus_Delta_t_XZK",
    &astrea::population::balance_equation::n_t_plus_Delta_t_XZK,
    "Calculates NLTE electrons population using balance equation across all\n"
    "spatial points.\n"
    "\n"
    ":param x_X: Any vector with shape corresponding to spatial points.\n"
    ":param n_t_XZK: Previous electrons population.\n"
    ":param R_ij_XZKK: Excitation transitions rates.\n"
    ":param R_ji_XZKK: De-excitation transitions rates.\n"
    ":param R_ik_XZK: Ionization transitions rates.\n"
    ":param R_ki_XZK: Recombination transitions rates.\n"
    ":param Delta_t: Time difference in s.\n"
    ":return: Electrons population in 1.\n",
    py::arg("x_X"),
    py::arg("n_t_XZK"),
    py::arg("R_ij_XZKK"),
    py::arg("R_ji_XZKK"),
    py::arg("R_ik_XZK"),
    py::arg("R_ki_XZK"),
    py::arg("Delta_t")
  );
}


}