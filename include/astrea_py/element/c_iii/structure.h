#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_iii {


inline void structure(py::module_& m) {
  // C III structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  py::enum_<astrea::element::c_iii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_He_2s2_1S", astrea::element::c_iii::STRUCTURE::LS_He_2s2_1S);
}


}