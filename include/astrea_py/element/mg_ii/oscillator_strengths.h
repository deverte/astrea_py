#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_ii {


inline void oscillator_strengths(py::module_& m) {
  m.def(
    "f_KK",
    &astrea::element::mg_ii::f_KK,
    "Mg II oscillator strengths by Alexeeva+2018, TOPBASE\n"
    "(https://cdsweb.u-strasbg.fr/topbase/xsections.html).\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Oscillator strength in 1.\n"
  );
}


}