#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_iii {


inline void info(py::module_& m) {
  m.def(
    "i",
    &astrea::element::c_iii::i,
    "State of ionization in 1."
  );

  m.def(
    "Z",
    &astrea::element::c_iii::Z,
    "Atomic number in 1."
  );

  m.def(
    "M",
    &astrea::element::c_iii::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def(
    "I",
    &astrea::element::c_iii::I,
    "Ionization energy in eV."
  );

  m.def(
    "A_H_sun",
    &astrea::element::c_iii::A_H_sun,
    "Element solar abundance relative to H."
  );
}


}