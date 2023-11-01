#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_ii {


inline void principal_quantum_numbers(py::module_& m) {
  m.def(
    "n",
    &astrea::element::fe_ii::n,
    "Fe II principal quantum numbers by Mashonkina+2011.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Principal quantum number in 1.\n"
  );
}


}