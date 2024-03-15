#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_i {


inline void energies(py::module_& m) {
  m.def(
    "E_K",
    &astrea::element::h_i::E_K,
    "H I energies by Mashonkina+2008.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}