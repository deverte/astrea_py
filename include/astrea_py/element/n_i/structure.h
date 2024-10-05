#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::n_i {


inline void structure(py::module_& m) {
  // N I structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  // Based on Mashonkina2024 N I model.
  py::enum_<astrea::element::n_i::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_He_2s2_2p3_4So", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p3_4So);
  STRUCTURE.value("LS_He_2s2_2p3_2Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p3_2Do);
  STRUCTURE.value("LS_He_2s2_2p3_2Po", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p3_2Po);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3s_4P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3s_2P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3s_2P);
  STRUCTURE.value("LS_He_2s_2p4_4P", astrea::element::n_i::STRUCTURE::LS_He_2s_2p4_4P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3p_2So", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3p_2So);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3p_4Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3p_4Do);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3p_4Po", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3p_4Po);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3p_4So", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3p_4So);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3p_2Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3p_2Do);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3p_2Po", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3p_2Po);
  STRUCTURE.value("LS_He_2s2_2p2_1D_3s_2D", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_1D_3s_2D);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4s_4P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4s_2P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4s_2P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3d_2P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3d_2P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3d_4D", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3d_4D);
  STRUCTURE.value("LS_He_2s2_2p2_3P_3d_2D", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_3d_2D);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4p_2So", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4p_2So);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4p_4Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4p_4Do);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4p_4Po", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4p_4Po);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4p_2Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4p_2Do);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4p_4So", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4p_4So);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4p_2Po", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4p_2Po);
  STRUCTURE.value("LS_He_2s2_2p2_3P_5s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_5s_4P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_5s_2P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_5s_2P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4d_4F", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4d_4F);
  STRUCTURE.value("LS_He_2s2_2p2_3P_4f_D", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_4f_D);
  STRUCTURE.value("LS_He_2s2_2p2_1D_3p_2Fo", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_1D_3p_2Fo);
  STRUCTURE.value("LS_He_2s2_2p2_3P_5p_2So", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_5p_2So);
  STRUCTURE.value("LS_He_2s2_2p2_3P_5p_4Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_5p_4Do);
  STRUCTURE.value("LS_He_2s2_2p2_3P_5p_4So", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_5p_4So);
  STRUCTURE.value("LS_He_2s2_2p2_3P_5p_2Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_5p_2Do);
  STRUCTURE.value("LS_He_2s2_2p2_1D_3p_2Po", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_1D_3p_2Po);
  STRUCTURE.value("LS_He_2s2_2p2_3P_6s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_6s_4P);
  STRUCTURE.value("LS_He_2s2_2p2_3P_5d_2F", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_5d_2F);
  STRUCTURE.value("LS_He_2s2_2p2_3P2_5f", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P2_5f);
  STRUCTURE.value("LS_He_2s2_2p2_3P_6p_4Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_6p_4Do);
  STRUCTURE.value("_k2o", astrea::element::n_i::STRUCTURE::_k2o);
  STRUCTURE.value("LS_He_2s2_2p2_3P_7s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_7s_4P);
  STRUCTURE.value("LS_He_2s2_2p2_3Po_6f", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3Po_6f);
  STRUCTURE.value("LS_He_2s2_2p2_3P_7p_4Do", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_7p_4Do);
  STRUCTURE.value("_k1e", astrea::element::n_i::STRUCTURE::_k1e);
  STRUCTURE.value("_k3o", astrea::element::n_i::STRUCTURE::_k3o);
  STRUCTURE.value("LS_He_2s2_2p2_3P_8s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_8s_4P);
  STRUCTURE.value("_k4o", astrea::element::n_i::STRUCTURE::_k4o);
  STRUCTURE.value("_k5o", astrea::element::n_i::STRUCTURE::_k5o);
  STRUCTURE.value("_k6o", astrea::element::n_i::STRUCTURE::_k6o);
  STRUCTURE.value("LS_He_2s2_2p2_3P_9s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_9s_4P);
  STRUCTURE.value("_k7o", astrea::element::n_i::STRUCTURE::_k7o);
  STRUCTURE.value("_k8o", astrea::element::n_i::STRUCTURE::_k8o);
  STRUCTURE.value("LS_He_2s2_2p2_3P_10s_4P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_10s_4P);
  STRUCTURE.value("_k9o", astrea::element::n_i::STRUCTURE::_k9o);
  STRUCTURE.value("LS_He_2s2_2p2_3P_10s_2P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_10s_2P);
  STRUCTURE.value("_k10o", astrea::element::n_i::STRUCTURE::_k10o);
  STRUCTURE.value("LS_He_2s2_2p2_3P_11s_2P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_11s_2P);
  STRUCTURE.value("_k11o", astrea::element::n_i::STRUCTURE::_k11o);
  STRUCTURE.value("LS_He_2s2_2p2_3P_12s_2P", astrea::element::n_i::STRUCTURE::LS_He_2s2_2p2_3P_12s_2P);
  STRUCTURE.value("_k12o", astrea::element::n_i::STRUCTURE::_k12o);
}


}