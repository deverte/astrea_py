#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_i {


inline void effective_collision_strengths(py::module_& m) {
  m.def(
    "f_vs_T",
    &astrea::element::c_i::f_vs_T,
    "C I effective collision strengths by Zatsarinny+2013, Reid1994,\n"
    "Alexeeva+2015.\n"
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