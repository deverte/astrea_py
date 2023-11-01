#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_ii {


inline void structure(py::module_& m) {
  // O II structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  py::enum_<astrea::element::o_ii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_He_2s2_2p3_4S", astrea::element::o_ii::STRUCTURE::LS_He_2s2_2p3_4S);
}


}