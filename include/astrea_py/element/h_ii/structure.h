#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_ii {


inline void structure(py::module_& m) {
  // H II structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  py::enum_<astrea::element::h_ii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_1", astrea::element::h_ii::STRUCTURE::LS_1);
}


}