#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::optics {


inline void natural_line_width(py::module_& m) {
  m.doc() =
    "Natural line width.\n"
  ;

  m.def(
    "Delta_nu_L",
    &astrea::optics::natural_line_width::Delta_nu_L,
    "Natural (Lorentz) line width.\n"
    "\n"
    ":param A_ji: Spontaneous emission rate in s-1.\n"
    ":return: Line width in s-1.\n",
    py::arg("A_ji")
  );
}


}