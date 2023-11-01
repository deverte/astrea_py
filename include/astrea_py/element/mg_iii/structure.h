#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_iii {


inline void structure(py::module_& m) {
  // Mg III structure from NIST
  // (https://www.nist.gov/pml/atomic-spectra-database).
  py::enum_<astrea::element::mg_iii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_Ne_1S", astrea::element::mg_iii::STRUCTURE::LS_Ne_1S);
}


}