#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::transition {


inline void rd(py::module_& m) {
  m.doc() =
    "Radiative de-excitation transitions rates.\n"
  ;

  m.def(
    "R",
    &astrea::transition::rd::R,
    "Radiative de-excitation transition rates.\n"
    "\n"
    ":param x: Any vector with shape corresponding to spatial points.\n"
    "Axis 0: Coordinate index.\n"
    ":param A: Spontaneous emission rates in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n"
    ":return: Transition rate in s-1.\n"
    "Axis 0: Coordinate index.\n"
    "Axis 1: Initial term.\n"
    "Axis 2: Final term.\n",
    py::arg("x"),
    py::arg("A")
  );
}


}