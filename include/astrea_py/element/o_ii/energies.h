#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_ii {


inline void energies(py::module_& m) {
  m.def(
    "E_K",
    &astrea::element::o_ii::E_K,
    "O II energies from NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database).\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}