#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i {


inline void photoionization_cross_sections(py::module_& m) {
  m.def(
    "sigma_vs_nu_K",
    &astrea::element::o_i::sigma_vs_nu_K,
    "O I photoionization cross sections by Sitnova2012, Sitnova2017, TOPBASE\n"
    "(https://cdsweb.u-strasbg.fr/topbase/xsections.html).\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Bivariate data (row)\n"
    "  - Row 0: Frequency in s-1.\n"
    "  - Row 1: Cross section in cm2.\n"
    "- Axis 2: Bivariate pair index (column).\n"
  );
}


}