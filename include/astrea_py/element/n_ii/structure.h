#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::n_ii {


inline void structure(py::module_& m) {
  // N II structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  py::enum_<astrea::element::n_ii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_He_2s2_2p2_3P", astrea::element::n_ii::STRUCTURE::LS_He_2s2_2p2_3P);
}


}