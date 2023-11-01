#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_ii {


inline void principal_quantum_numbers(py::module_& m) {
  m.def(
    "n",
    &astrea::element::o_ii::n,
    "O II principal quantum numbers from NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database)\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Principal quantum number in 1.\n"
  );
}


}