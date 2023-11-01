#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_i {


inline void energies(py::module_& m) {
  m.def(
    "E",
    &astrea::element::c_i::E,
    "C I energies by Alexeeva+2015.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}