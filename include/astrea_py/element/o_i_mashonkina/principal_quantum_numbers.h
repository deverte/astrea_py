#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i_mashonkina {


inline void principal_quantum_numbers(py::module_& m) {
  m.def(
    "n",
    &astrea::element::o_i_mashonkina::n,
    "O I principal quantum numbers by Przybilla2000, Sitnova2012, and Sitnova2017.\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Principal quantum number in 1.\n"
  );
}


}