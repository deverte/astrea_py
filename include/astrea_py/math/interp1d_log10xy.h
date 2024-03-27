#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void interp1d_log10xy(py::module_& m) {
  m.def(
    "f",
    &astrea::math::interp1d_log10xy::f,
    "Linear 1D interpolation.\n"
    "\n"
    ":param x_Y: x points.\n"
    ":param y_Y: y points.\n"
    ":param x: x point to interpolate.\n"
    ":return: Interpolated y.\n",
    py::arg("x_Y"),
    py::arg("y_Y"),
    py::arg("x")
  );

  m.def(
    "f_X",
    &astrea::math::interp1d_log10xy::f_X,
    "Linear 1D interpolation.\n"
    "\n"
    ":param x_Y: x points.\n"
    ":param y_Y: y points.\n"
    ":param x_X: x points to interpolate.\n"
    ":return: Interpolated y.\n",
    py::arg("x_Y"),
    py::arg("y_Y"),
    py::arg("x_X")
  );
}


}