#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::cooling {


inline void heating_rate(py::module_& m) {
  m.doc() =
    "Heating rate.\n"
  ;

  m.def(
    "H",
    &astrea::cooling::heating_rate::H,
    "Heating rate.\n"
    "\n"
    ":param n_K: Electrons population in 1.\n"
    "Must be sorted over energies!\n"
    ":param R_KK: Transitions rates in s-1.\n"
    "Must be sorted over energies!\n"
    ":param E_K: Energies of element z in eV.\n"
    "Must be sorted!\n"
    ":return: Heating rate in erg s-1 cm-3.\n",
    py::arg("n_K"),
    py::arg("R_KK"),
    py::arg("E_K")
  );

  m.def(
    "H_X",
    &astrea::cooling::heating_rate::H_X,
    "Heating rate.\n"
    "\n"
    ":param x_X: Any array with coordinates shape.\n"
    ":param n_XK: Electrons population in 1.\n"
    "Must be sorted over energies!\n"
    ":param R_XKK: Transitions rates in s-1.\n"
    "Must be sorted over energies!\n"
    ":param E_K: Energies of element z in eV.\n"
    "Must be sorted!\n"
    ":return: Heating rates in erg s-1 cm-3.\n",
    py::arg("x_X"),
    py::arg("n_XK"),
    py::arg("R_XKK"),
    py::arg("E_K")
  );
}


}