#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element {


inline void o_ii_mashonkina(py::module_& m) {
  m.doc() = "1-ionized oxygen data by Mashonkina (private communication).";

  m.def("i", &astrea::element::o_ii_mashonkina::i, "State of ionization in 1.");

  m.def("Z", &astrea::element::o_ii_mashonkina::Z, "Atomic number in 1.");

  m.def(
    "M",
    &astrea::element::o_ii_mashonkina::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def("I", &astrea::element::o_ii_mashonkina::I, "Ionization energy in eV.");

  py::enum_<astrea::element::o_ii_mashonkina::TERM> TERM(m, "TERM");
  TERM.value("LS_1s2_2s2_2p3_4S", astrea::element::o_ii_mashonkina::TERM::LS_1s2_2s2_2p3_4S);

  m.def("E", &astrea::element::o_ii_mashonkina::E, "Terms' energies in eV.");

  m.def(
    "n",
    &astrea::element::o_ii_mashonkina::n,
    "Terms' principal quantum numbers in 1."
  );

  m.def(
    "g",
    &astrea::element::o_ii_mashonkina::g,
    "Terms' statistical weights in 1."
  );

  m.def(
    "A",
    &astrea::element::o_ii_mashonkina::A,
    "Terms' spontaneous emission rates in s-1."
  );
}


}