#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i_mashonkina {


inline void collision_rate_coefficients(py::module_& m) {
  m.def(
    "C_vs_T",
    &astrea::element::o_i_mashonkina::C_vs_T,
    "O I collision rate coefficients by Barklem2007 and Sitnova+2013.\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "- Axis 2: Bivariate data (row).\n"
    "  - Row 0: Temperature in K.\n"
    "  - Row 1: Collision rate coefficient in cm3 s-1.\n"
    "- Axis 3: Bivariate pair index (column).\n"
  );
}


}