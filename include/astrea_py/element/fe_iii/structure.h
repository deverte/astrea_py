#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_iii {


inline void structure(py::module_& m) {
  // Fe III structure from NIST
  // (https://www.nist.gov/pml/atomic-spectra-database).
  py::enum_<astrea::element::fe_iii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_Ar_3d6_5D", astrea::element::fe_iii::STRUCTURE::LS_Ar_3d6_5D);
}


}