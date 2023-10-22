#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_ii_mashonkina {


inline void energies(py::module_& m) {
  m.def(
    "E",
    &astrea::element::o_ii_mashonkina::E,
    "O II energies by Przybilla2000, Sitnova2012, and Sitnova2017.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}