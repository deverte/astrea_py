#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_ii {


inline void energies(py::module_& m) {
  m.def(
    "E_K",
    &astrea::element::c_ii::E_K,
    "C II energies by Alexeeva+2015.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}