#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_ii_mashonkina {


inline void spontaneous_emission_rates(py::module_& m) {
  m.def(
    "A",
    &astrea::element::o_ii_mashonkina::A,
    "O II spontaneous emission rates from NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database).\n"
    "\n"
    "- Axis 0: Initial term (i-index).\n"
    "- Axis 1: Final term (j-index).\n"
    "  - Spontaneous emission rate in s-1.\n"
  );
}


}