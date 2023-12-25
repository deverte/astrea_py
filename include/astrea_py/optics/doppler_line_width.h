#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::optics {


inline void doppler_line_width(py::module_& m) {
  m.doc() =
    "Doppler line width.\n"
  ;

  m.def(
    "Delta_nu_D_X",
    &astrea::optics::doppler_line_width::Delta_nu_D_X,
    "Doppler line widths.\n"
    "\n"
    ":param T_X: Temperatures in K.\n"
    ":param m_i: Mass in Da.\n"
    ":param nu_ij: Line center frequency in s-1.\n"
    ":return: Line width in s-1.\n",
    py::arg("T_X"),
    py::arg("m_i"),
    py::arg("nu_ij")
  );
}


}