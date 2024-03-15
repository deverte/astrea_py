#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::h_ii {


inline void info(py::module_& m) {
  m.def(
    "i",
    &astrea::element::h_ii::i,
    "State of ionization in 1."
  );

  m.def(
    "Z",
    &astrea::element::h_ii::Z,
    "Atomic number in 1."
  );

  m.def(
    "M",
    &astrea::element::h_ii::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def(
    "I",
    &astrea::element::h_ii::I,
    "Ionization energy in eV."
  );

  m.def(
    "A_H_sun",
    &astrea::element::h_ii::A_H_sun,
    "Element solar abundance relative to H."
  );
}


}