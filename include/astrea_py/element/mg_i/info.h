#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_i {


inline void info(py::module_& m) {
  m.def(
    "i",
    &astrea::element::mg_i::i,
    "State of ionization in 1."
  );

  m.def(
    "Z",
    &astrea::element::mg_i::Z,
    "Atomic number in 1."
  );

  m.def(
    "M",
    &astrea::element::mg_i::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def(
    "I",
    &astrea::element::mg_i::I,
    "Ionization energy in eV."
  );

  m.def(
    "A_H_sun",
    &astrea::element::mg_i::A_H_sun,
    "Element solar abundance relative to H."
  );
}


}