#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_iii {


inline void energies(py::module_& m) {
  m.def(
    "E",
    &astrea::element::mg_iii::E,
    "Mg III energies from NIST (https://www.nist.gov/pml/atomic-spectra-database).\n"
    "\n"
    "- Axis 0: Term.\n"
    "  - Energy in eV.\n"
  );
}


}