#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_ii {


inline void energies(py::module_& m) {
  m.def(
    "E",
    &astrea::element::mg_ii::E,
    "Mg II energies by Alexeeva+2018.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}