#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_iii {


inline void principal_quantum_numbers(py::module_& m) {
  m.def(
    "n_K",
    &astrea::element::fe_iii::n_K,
    "Fe III principal quantum numbers from NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database).\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Principal quantum number in 1.\n"
  );
}


}