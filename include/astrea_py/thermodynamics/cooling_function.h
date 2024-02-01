#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::thermodynamics {


inline void cooling_function(py::module_& m) {
  m.doc() =
    "Cooling function.\n"
  ;

  m.def(
    "Lambda",
    &astrea::thermodynamics::cooling_function::Lambda,
    "Cooling function.\n"
    "\n"
    ":param n_K: Electrons population in 1.\n"
    "Must be sorted over energies!\n"
    ":param R_KK: Transitions rates in s-1.\n"
    "Must be sorted over energies!\n"
    ":param E_K: Energies of element z in eV.\n"
    "Must be sorted!\n"
    ":return: Cooling rate in erg s-1 cm-3.\n",
    py::arg("n_K"),
    py::arg("R_KK"),
    py::arg("E_K")
  );

  m.def(
    "Lambda_X",
    &astrea::thermodynamics::cooling_function::Lambda_X,
    "Cooling function.\n"
    "\n"
    ":param x_X: Any array with coordinates shape.\n"
    ":param n_XK: Electrons population in 1.\n"
    "Must be sorted over energies!\n"
    ":param R_XKK: Transitions rates in s-1.\n"
    "Must be sorted over energies!\n"
    ":param E_K: Energies of element z in eV.\n"
    "Must be sorted!\n"
    ":return: Cooling rates in erg s-1 cm-3.\n",
    py::arg("x_X"),
    py::arg("n_XK"),
    py::arg("R_XKK"),
    py::arg("E_K")
  );

  m.def(
    "Lambda_ZX",
    &astrea::thermodynamics::cooling_function::Lambda_ZX,
    "Cooling function.\n"
    "\n"
    ":param x_X: Any array with coordinates shape.\n"
    ":param n_XZK: Electrons population in 1.\n"
    "Must be sorted over energies!\n"
    ":param R_XZKK: Transitions rates in s-1.\n"
    "Must be sorted over energies!\n"
    ":param E_ZK: Energies of elements in eV.\n"
    "Must be sorted!\n"
    ":return: Cooling rates in erg s-1 cm-3.\n",
    py::arg("x_X"),
    py::arg("n_XZK"),
    py::arg("R_XZKK"),
    py::arg("E_ZK")
  );
}


}