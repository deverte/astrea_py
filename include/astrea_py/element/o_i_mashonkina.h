#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element {


inline void o_i_mashonkina(py::module_& m) {
  m.doc() =
    "Electrically neutral oxygen data by Mashonkina (private communication).";

  m.def("i", &astrea::element::o_i_mashonkina::i, "State of ionization in 1.");

  m.def("Z", &astrea::element::o_i_mashonkina::Z, "Atomic number in 1.");

  m.def(
    "M",
    &astrea::element::o_i_mashonkina::M,
    "Mass number in 1 (mass in Da)."
  );

  m.def("I", &astrea::element::o_i_mashonkina::I, "Ionization energy in eV.");

  py::enum_<astrea::element::o_i_mashonkina::TERM> TERM(m, "TERM");
  TERM.value("LS_1s2_2s2_2p3_4So_3s_3So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_3s_3So);
  TERM.value("LS_1s2_2s2_2p3_4So_3s_5So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_3s_5So);
  TERM.value("LS_1s2_2s2_2p3_4So_3p_3P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_3p_3P);
  TERM.value("LS_1s2_2s2_2p3_4So_3p_5P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_3p_5P);
  TERM.value("LS_1s2_2s2_2p3_4So_3d_3Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_3d_3Do);
  TERM.value("LS_1s2_2s2_2p3_4So_3d_5Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_3d_5Do);
  TERM.value("LS_1s2_2s2_2p3_4So_4s_3So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4s_3So);
  TERM.value("LS_1s2_2s2_2p3_4So_4s_5So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4s_5So);
  TERM.value("LS_1s2_2s2_2p3_4So_4p_3P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4p_3P);
  TERM.value("LS_1s2_2s2_2p3_4So_4p_5P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4p_5P);
  TERM.value("LS_1s2_2s2_2p3_4So_4d_3Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4d_3Do);
  TERM.value("LS_1s2_2s2_2p3_4So_4d_5Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4d_5Do);
  TERM.value("LS_1s2_2s2_2p3_4So_4f_3F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4f_3F);
  TERM.value("LS_1s2_2s2_2p3_4So_4f_5F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_4f_5F);
  TERM.value("LS_1s2_2s2_2p3_4So_5s_3So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5s_3So);
  TERM.value("LS_1s2_2s2_2p3_4So_5s_5So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5s_5So);
  TERM.value("LS_1s2_2s2_2p3_4So_5p_3P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5p_3P);
  TERM.value("LS_1s2_2s2_2p3_4So_5p_5P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5p_5P);
  TERM.value("LS_1s2_2s2_2p3_4So_5d_3Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5d_3Do);
  TERM.value("LS_1s2_2s2_2p3_4So_5d_5Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5d_5Do);
  TERM.value("LS_1s2_2s2_2p3_4So_5f_3F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5f_3F);
  TERM.value("LS_1s2_2s2_2p3_4So_5f_5F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_5f_5F);
  TERM.value("LS_1s2_2s2_2p3_4So_6s_3So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6s_3So);
  TERM.value("LS_1s2_2s2_2p3_4So_6s_5So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6s_5So);
  TERM.value("LS_1s2_2s2_2p3_4So_6p_3P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6p_3P);
  TERM.value("LS_1s2_2s2_2p3_4So_6p_5P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6p_5P);
  TERM.value("LS_1s2_2s2_2p3_4So_6d_3Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6d_3Do);
  TERM.value("LS_1s2_2s2_2p3_4So_6d_5Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6d_5Do);
  TERM.value("LS_1s2_2s2_2p3_4So_6f_3F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6f_3F);
  TERM.value("LS_1s2_2s2_2p3_4So_6f_5F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_6f_5F);
  TERM.value("LS_1s2_2s2_2p3_4So_7s_3So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7s_3So);
  TERM.value("LS_1s2_2s2_2p3_4So_7s_5So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7s_5So);
  TERM.value("LS_1s2_2s2_2p3_4So_7p_3P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7p_3P);
  TERM.value("LS_1s2_2s2_2p3_4So_7p_5P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7p_5P);
  TERM.value("LS_1s2_2s2_2p3_4So_7d_3Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7d_3Do);
  TERM.value("LS_1s2_2s2_2p3_4So_7d_5Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7d_5Do);
  TERM.value("LS_1s2_2s2_2p3_4So_7f_3F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7f_3F);
  TERM.value("LS_1s2_2s2_2p3_4So_7f_5F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_7f_5F);
  TERM.value("LS_1s2_2s2_2p3_4So_8s_3So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8s_3So);
  TERM.value("LS_1s2_2s2_2p3_4So_8s_5So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8s_5So);
  TERM.value("LS_1s2_2s2_2p3_4So_8p_3P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8p_3P);
  TERM.value("LS_1s2_2s2_2p3_4So_8p_5P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8p_5P);
  TERM.value("LS_1s2_2s2_2p3_4So_8d_3Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8d_3Do);
  TERM.value("LS_1s2_2s2_2p3_4So_8d_5Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8d_5Do);
  TERM.value("LS_1s2_2s2_2p3_4So_8f_3F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8f_3F);
  TERM.value("LS_1s2_2s2_2p3_4So_8f_5F", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_8f_5F);
  TERM.value("LS_1s2_2s2_2p3_4So_9s_3So", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_4So_9s_3So);
  TERM.value("LS_1s2_2s2_2p3_2Do_3s_3Do", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p3_2Do_3s_3Do);
  TERM.value("LS_1s2_2s2_2p4_1S", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p4_1S);
  TERM.value("LS_1s2_2s2_2p4_3P", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p4_3P);
  TERM.value("LS_1s2_2s2_2p4_1D", astrea::element::o_i_mashonkina::TERM::LS_1s2_2s2_2p4_1D);

  m.def("E", &astrea::element::o_i_mashonkina::E, "Terms' energies in eV.");

  m.def(
    "n",
    &astrea::element::o_i_mashonkina::n,
    "Terms' principal quantum numbers in 1."
  );

  m.def(
    "g",
    &astrea::element::o_i_mashonkina::g,
    "Terms' statistical weights in 1."
  );

  m.def(
    "A",
    &astrea::element::o_i_mashonkina::A,
    "Terms' spontaneous emission rates in s-1."
  );

  m.def(
    "sigma_k",
    &astrea::element::o_i_mashonkina::sigma_k,
    "Terms' photoionization cross sections in cm2.\n"
    "Row 0: frequencies in s-1.\n"
    "Row 1: cross sections in cm2."
  );
}


}