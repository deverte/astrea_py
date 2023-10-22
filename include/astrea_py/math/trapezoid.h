#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void trapezoid(py::module_& m) {
  m.def(
    "trapezoid_dx",
    &astrea::math::trapezoid_dx,
    "Trapezoidal integration.\n"
    "\n"
    ":param y: Input array.\n"
    ":param dx: Spacing between sample points.\n"
    ":return: Definite integral.\n",
    py::arg("y"),
    py::arg("dx")
  );

  m.def(
    "trapezoid_x",
    &astrea::math::trapezoid_x,
    "Trapezoidal integration.\n"
    "\n"
    ":param y: Input array.\n"
    ":param x: Sample points corresponding to y values.\n"
    ":return: Definite integral.\n",
    py::arg("y"),
    py::arg("x")
  );
}


}