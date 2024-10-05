#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::n_i {


inline void energies(py::module_& m) {
  m.def(
    "E_K",
    &astrea::element::n_i::E_K,
    "N I energies by Kurucz2014, Mashonkina2024.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}