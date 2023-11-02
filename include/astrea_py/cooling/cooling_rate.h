#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::cooling {


inline void cooling_rate(py::module_& m) {
  m.doc() =
    "Cooling rate.\n"
  ;

  m.def(
    "L_x",
    &astrea::cooling::L_x,
    "Cooling rate.\n"
    "\n"
    ":param n_x_z: Electrons population at point x for element z in 1.\n"
    "Axis 0: Term index.\n"
    "Must be sorted over energies!\n"
    ":param R_x_z: Transitions rates at point x for element z in s-1.\n"
    "Axis 0: Initial term.\n"
    "Axis 1: Final term.\n"
    "Must be sorted over energies!\n"
    ":param E_z: Energies of element z in eV.\n"
    "Axis 0: Term index.\n"
    "Must be sorted!\n"
    ":return: Cooling rate in erg s-1 cm-3.\n",
    py::arg("n_x_z"),
    py::arg("R_x_z"),
    py::arg("E_z")
  );

  m.def(
    "L",
    &astrea::cooling::L,
    "Cooling rate.\n"
    "\n"
    ":param x: Any array with coordinates shape.\n"
    "Axis 0: Coordinate index.\n"
    ":param n_z: Electrons population for element z in 1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Term index.\n"
    "Must be sorted over energies!\n"
    ":param R_x_z: Transitions rates for element z in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    "Must be sorted over energies!\n"
    ":param E_z: Energies of element z in eV.\n"
    "Axis 0: Term index.\n"
    "Must be sorted!\n"
    ":return: Cooling rates in erg s-1 cm-3.\n"
    "Axis 0: Coordinate index.\n",
    py::arg("x"),
    py::arg("n_z"),
    py::arg("R_z"),
    py::arg("E_z")
  );
}


}