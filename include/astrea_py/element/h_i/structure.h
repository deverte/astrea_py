#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_i {


inline void structure(py::module_& m) {
  // H I structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  // Based on Mashonkina+2008 H I model.
  py::enum_<astrea::element::h_i::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_1", astrea::element::h_i::STRUCTURE::LS_1);
  STRUCTURE.value("LS_2", astrea::element::h_i::STRUCTURE::LS_2);
  STRUCTURE.value("LS_3", astrea::element::h_i::STRUCTURE::LS_3);
  STRUCTURE.value("LS_4", astrea::element::h_i::STRUCTURE::LS_4);
  STRUCTURE.value("LS_5", astrea::element::h_i::STRUCTURE::LS_5);
  STRUCTURE.value("LS_6", astrea::element::h_i::STRUCTURE::LS_6);
  STRUCTURE.value("LS_7", astrea::element::h_i::STRUCTURE::LS_7);
  STRUCTURE.value("LS_8", astrea::element::h_i::STRUCTURE::LS_8);
  STRUCTURE.value("LS_9", astrea::element::h_i::STRUCTURE::LS_9);
  STRUCTURE.value("LS_10", astrea::element::h_i::STRUCTURE::LS_10);
  STRUCTURE.value("LS_11", astrea::element::h_i::STRUCTURE::LS_11);
  STRUCTURE.value("LS_12", astrea::element::h_i::STRUCTURE::LS_12);
  STRUCTURE.value("LS_13", astrea::element::h_i::STRUCTURE::LS_13);
  STRUCTURE.value("LS_14", astrea::element::h_i::STRUCTURE::LS_14);
  STRUCTURE.value("LS_15", astrea::element::h_i::STRUCTURE::LS_15);
  STRUCTURE.value("LS_16", astrea::element::h_i::STRUCTURE::LS_16);
  STRUCTURE.value("LS_17", astrea::element::h_i::STRUCTURE::LS_17);
  STRUCTURE.value("LS_18", astrea::element::h_i::STRUCTURE::LS_18);
  STRUCTURE.value("LS_19", astrea::element::h_i::STRUCTURE::LS_19);
}


}