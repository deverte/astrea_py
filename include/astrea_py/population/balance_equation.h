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
    "Q_x",
    &astrea::population::balance_equation::Q_x,
    "Builds single transitions rates matrix Q from S.\n"
    "\n"
    ":param S_x: Transitions rates matrix at coordinate x in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n"
    ":return: Single transitions rates matrix at coordinate x in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("S_x")
  );

  m.def(
    "P_x",
    &astrea::population::balance_equation::P_x,
    ":param Q_x: Transition rates matrix in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n"
    ":param Delta_t: Time difference in s.\n"
    ":return: Transition operator at coordinate x in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("Q_x"),
    py::arg("Delta_t")
  );

  m.def(
    "p_x_t_plus_Delta_t",
    &astrea::population::balance_equation::p_x_t_plus_Delta_t,
    "Calculates current electrons populations single vector using previous\n"
    "electrons populations single vector and single transition operator P.\n"
    "\n"
    ":param p_x_t: Previous electrons population at coordinate x in 1.\n"
    "Axis 0: Term.\n"
    ":param P_x: Transition operator in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n"
    ":return: Single electrons population vector at coordinate x in 1.\n"
    "Axis 0: Term.\n",
    py::arg("p_x_t"),
    py::arg("P_x")
  );

  m.def(
    "p_x_t",
    &astrea::population::balance_equation::p_x_t,
    "Builds single electrons population vector p_t from set of n_t vectors.\n"
    "\n"
    ":param n_x_t: Previous electrons population at coordinate x.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    ":return: Single electrons population vector at coordinate x in 1.\n"
    "Axis 0: Term.\n",
    py::arg("n_x_t")
  );

  m.def(
    "S_x",
    &astrea::population::balance_equation::S_x,
    "Builds single transitions rates matrix S from set of R matrices.\n"
    "\n"
    ":param R_x_ij: Excitation transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    ":param R_x_ji: De-excitation transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    ":param R_x_ik: Ionization transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    ":param R_x_ki: Recombination transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Final term.\n"
    ":return: Single transitions rates matrix at coordinate x in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n",
    py::arg("R_x_ij"),
    py::arg("R_x_ji"),
    py::arg("R_x_ik"),
    py::arg("R_x_ki")
  );

  m.def(
    "n_x_t_plus_Delta_t",
    &astrea::population::balance_equation::n_x_t_plus_Delta_t,
    "Calculates NLTE electrons population using balance equation.\n"
    "\n"
    ":param n_x_t: Previous electrons population at coordinate x.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n"
    ":param R_x_ij: Excitation transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    ":param R_x_ji: De-excitation transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    ":param R_x_ik: Ionization transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Initial term.\n"
    ":param R_x_ki: Recombination transitions rates at coordinate x in s-1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Final term.\n"
    ":param Delta_t: Time difference in s.\n"
    ":return: Electrons population at coordinate x in 1.\n"
    "Axis 0: Element index.\n"
    "Axis 1: Term.\n",
    py::arg("n_x_t"),
    py::arg("R_x_ij"),
    py::arg("R_x_ji"),
    py::arg("R_x_ik"),
    py::arg("R_x_ki"),
    py::arg("Delta_t")
  );

  m.def(
    "n_t_plus_Delta_t",
    &astrea::population::balance_equation::n_t_plus_Delta_t,
    "Calculates NLTE electrons population using balance equation across all\n"
    "spatial points.\n"
    "\n"
    ":param x: Any vector with shape corresponding to spatial points.\n"
    "Axis 0: Coordinate index.\n"
    ":param n_t: Previous electrons population.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Term.\n"
    ":param R_ij: Excitation transitions rates.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n"
    ":param R_ji: De-excitation transitions rates.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    "Axis 3: Final term.\n"
    ":param R_ik: Ionization transitions rates.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Initial term.\n"
    ":param R_ki: Recombination transitions rates.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Final term.\n"
    ":param Delta_t: Time difference in s.\n"
    ":return: Electrons population in 1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Element index.\n"
    "Axis 2: Term.\n",
    py::arg("x"),
    py::arg("n_t"),
    py::arg("R_ij"),
    py::arg("R_ji"),
    py::arg("R_ik"),
    py::arg("R_ki"),
    py::arg("Delta_t")
  );
}


}