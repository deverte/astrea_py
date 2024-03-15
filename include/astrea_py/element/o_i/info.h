#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_i {


inline void info(py::module_& m) {
  m.def(
    "i",
    &astrea::element::o_i::i,
    "State of ionization in 1."
  );

  m.def(
    "Z",
    &astrea::element::o_i::Z,
    "Atomic number in 1."
  );

  m.def(
    "M",
    &astrea::element::o_i::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def(
    "I",
    &astrea::element::o_i::I,
    "Ionization energy in eV."
  );

  m.def(
    "A_H_sun",
    &astrea::element::o_i::A_H_sun,
    "Element solar abundance relative to H."
  );
}


}