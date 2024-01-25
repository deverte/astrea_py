#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_ii {


inline void effective_collision_strengths(py::module_& m) {
  m.def(
    "f_vs_T_KK",
    &astrea::element::c_ii::f_vs_T_KK,
    "C II effective collision strengths by Wilson+2005, Alexeeva+2015.\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "- Axis 2: Bivariate data (row).\n"
    "  - Row 0: Temperature in K.\n"
    "  - Row 1: Effective collision strength in 1.\n"
    "- Axis 3: Bivariate pair index (column).\n"
  );
}


}