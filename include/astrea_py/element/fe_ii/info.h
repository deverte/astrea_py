#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_ii {


inline void info(py::module_& m) {
  m.def(
    "i",
    &astrea::element::fe_ii::i,
    "State of ionization in 1."
  );

  m.def(
    "Z",
    &astrea::element::fe_ii::Z,
    "Atomic number in 1."
  );

  m.def(
    "M",
    &astrea::element::fe_ii::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def(
    "I",
    &astrea::element::fe_ii::I,
    "Ionization energy in eV."
  );

  m.def(
    "A_H_sun",
    &astrea::element::fe_ii::A_H_sun,
    "Element solar abundance relative to H."
  );
}


}