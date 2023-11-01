#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_i {


inline void oscillator_strengths(py::module_& m) {
  m.def(
    "f",
    &astrea::element::mg_i::f,
    "Mg I oscillator strengths by Alexeeva+2018, Lemke+1987, Osorio2015,\n"
    "Green1957, TOPBASE (https://cdsweb.u-strasbg.fr/topbase/xsections.html).\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Oscillator strength in 1.\n"
  );
}


}