#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::cooling {


inline void cooling_rate_approximation(py::module_& m) {
  m.doc() =
    "Cooling rate approximation.\n"
  ;

  m.def(
    "L_X",
    &astrea::cooling::cooling_rate_approximation::L_X,
    "Cooling rate approximation.\n"
    "\n"
    ":param Lambda_vs_T: Cooling efficiency.\n"
    "Axis 0: Bivariate data (row).\n"
    "  0: Temperature in K.\n"
    "  1: Cooling efficiency in erg s-1 cm3.\n"
    "Axis 1: Bivariate pair index (column).\n"
    ":param T_X: Temperatures in K.\n"
    ":param N_e_X: Electron number densities in cm-3.\n"
    ":param N_A_X: Element number densities in cm-3.\n"
    ":return: Cooling rates in erg s-1 cm-3.\n",
    py::arg("Lambda_vs_T"),
    py::arg("T_X"),
    py::arg("N_e_X"),
    py::arg("N_A_X")
  );
}


}