#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void maxwell_boltzmann_distribution(py::module_& m) {
  m.def(
    "P_v_X",
    &astrea::math::maxwell_boltzmann_distribution::P_v_X,
    "Maxwell-Boltzmann velocity distribution.\n"
    "\n"
    ":param v_X: Velocities.\n"
    ":param T_X: Temperatures.\n"
    ":param m: Mass.\n"
    ":return: Distribution.\n",
    py::arg("v_X"),
    py::arg("T_X"),
    py::arg("m")
  );
}


}