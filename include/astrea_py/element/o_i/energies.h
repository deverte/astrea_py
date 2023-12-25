#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i {


inline void energies(py::module_& m) {
  m.def(
    "E_K",
    &astrea::element::o_i::E_K,
    "O I energies by Przybilla2000, Sitnova2012, Sitnova2017.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}