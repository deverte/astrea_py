#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::o_ii_mashonkina {


inline void info(py::module_& m) {
  m.def(
    "i",
    &astrea::element::o_ii_mashonkina::i,
    "State of ionization in 1."
  );

  m.def(
    "Z",
    &astrea::element::o_ii_mashonkina::Z,
    "Atomic number in 1."
  );

  m.def(
    "M",
    &astrea::element::o_ii_mashonkina::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def(
    "I",
    &astrea::element::o_ii_mashonkina::I,
    "Ionization energy in eV."
  );
}


}