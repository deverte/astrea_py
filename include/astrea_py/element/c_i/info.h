#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_i {


inline void info(py::module_& m) {
  m.def(
    "i",
    &astrea::element::c_i::i,
    "State of ionization in 1."
  );

  m.def(
    "Z",
    &astrea::element::c_i::Z,
    "Atomic number in 1."
  );

  m.def(
    "M",
    &astrea::element::c_i::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def(
    "I",
    &astrea::element::c_i::I,
    "Ionization energy in eV."
  );
}


}