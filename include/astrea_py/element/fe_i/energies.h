#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_i {


inline void energies(py::module_& m) {
  m.def(
    "E",
    &astrea::element::fe_i::E,
    "Fe I energies by Mashonkina+2011.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}