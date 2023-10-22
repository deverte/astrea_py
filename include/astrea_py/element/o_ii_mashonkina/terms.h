#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_ii_mashonkina {


inline void terms(py::module_& m) {
  // O II terms from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  py::enum_<astrea::element::o_ii_mashonkina::TERM> TERM(m, "TERM");
  TERM.value("LS_1s2_2s2_2p3_4S", astrea::element::o_ii_mashonkina::TERM::LS_1s2_2s2_2p3_4S);
}


}