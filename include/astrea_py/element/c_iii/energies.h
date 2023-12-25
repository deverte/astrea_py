#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_iii {


inline void energies(py::module_& m) {
  m.def(
    "E_K",
    &astrea::element::c_iii::E_K,
    "C III energies from NIST (https://www.nist.gov/pml/atomic-spectra-database).\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}