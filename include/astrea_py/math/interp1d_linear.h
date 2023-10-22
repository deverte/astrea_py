#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void interp1d_linear(py::module_& m) {
  m.def(
    "interp1d_linear_x",
    &astrea::math::interp1d_linear_x,
    "Linear 1D interpolation.\n"
    "\n"
    ":param xs: x points.\n"
    ":param ys: y points.\n"
    ":param x: x point to interpolate.\n"
    ":return: Interpolated y.\n",
    py::arg("xs"),
    py::arg("ys"),
    py::arg("x")
  );

  m.def(
    "interp1d_linear_xs",
    &astrea::math::interp1d_linear_xs,
    "Linear 1D interpolation.\n"
    "\n"
    ":param xs: x points.\n"
    ":param ys: y points.\n"
    ":param x: x points to interpolate.\n"
    ":return: Interpolated y.\n",
    py::arg("xs"),
    py::arg("ys"),
    py::arg("x")
  );
}


}