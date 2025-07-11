#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_ii {


inline void principal_quantum_numbers(py::module_& m) {
  m.def(
    "n_K",
    &astrea::element::h_ii::n_K,
    "H II principal quantum numbers by Mashonkina+2008.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Principal quantum number in 1.\n"
  );
}


}