#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::n_i {


inline void principal_quantum_numbers(py::module_& m) {
  m.def(
    "n_K",
    &astrea::element::n_i::n_K,
    "N I principal quantum numbers by Mashonkina+2024.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Principal quantum number in 1.\n"
  );
}


}