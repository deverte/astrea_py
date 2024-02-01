#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i {


inline void effective_collision_strengths(py::module_& m) {
  m.def(
    "f_vs_T_KK",
    &astrea::element::o_i::f_vs_T_KK,
    "O I effective collision strengths by Barklem2007, Sitnova+2013 (transformed\n"
    "from collision rate coefficients).\n"
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