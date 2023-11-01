#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_ii {


inline void structure(py::module_& m) {
  // C II structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  // Based on Alexeeva+2015 C II model.
  py::enum_<astrea::element::c_ii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_He_2s2_2p_2Po", astrea::element::c_ii::STRUCTURE::LS_He_2s2_2p_2Po);
  STRUCTURE.value("LS_He_2s_2p2_4P2", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p2_4P2);
  STRUCTURE.value("LS_He_2s_2p2_4P4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p2_4P4);
  STRUCTURE.value("LS_He_2s_2p2_4P6", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p2_4P6);
  STRUCTURE.value("LS_He_2s_2p2_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p2_2D);
  STRUCTURE.value("LS_He_2s_2p2_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p2_2S);
  STRUCTURE.value("LS_He_2s_2p2_2P2", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p2_2P2);
  STRUCTURE.value("LS_He_2s_2p2_2P4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p2_2P4);
  STRUCTURE.value("LS_He_2s2_3s_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s2_3s_2S);
  STRUCTURE.value("LS_He_2s2_3p_2Po", astrea::element::c_ii::STRUCTURE::LS_He_2s2_3p_2Po);
  STRUCTURE.value("LS_He_2p3_4So4", astrea::element::c_ii::STRUCTURE::LS_He_2p3_4So4);
  STRUCTURE.value("LS_He_2s2_3d_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s2_3d_2D);
  STRUCTURE.value("LS_He_2p3_2Do", astrea::element::c_ii::STRUCTURE::LS_He_2p3_2Do);
  STRUCTURE.value("LS_He_2s2_4s_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s2_4s_2S);
  STRUCTURE.value("LS_He_2s2_4p_2Po2", astrea::element::c_ii::STRUCTURE::LS_He_2s2_4p_2Po2);
  STRUCTURE.value("LS_He_2s2_4p_2Po4", astrea::element::c_ii::STRUCTURE::LS_He_2s2_4p_2Po4);
  STRUCTURE.value("LS_He_2s_2p_3Po_3s_4Po2", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3s_4Po2);
  STRUCTURE.value("LS_He_2s_2p_3Po_3s_4Po4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3s_4Po4);
  STRUCTURE.value("LS_He_2s_2p_3Po_3s_4Po6", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3s_4Po6);
  STRUCTURE.value("LS_He_2s2_4d_2D4", astrea::element::c_ii::STRUCTURE::LS_He_2s2_4d_2D4);
  STRUCTURE.value("LS_He_2s2_4d_2D6", astrea::element::c_ii::STRUCTURE::LS_He_2s2_4d_2D6);
  STRUCTURE.value("LS_He_2p3_2Po2", astrea::element::c_ii::STRUCTURE::LS_He_2p3_2Po2);
  STRUCTURE.value("LS_He_2p3_2Po4", astrea::element::c_ii::STRUCTURE::LS_He_2p3_2Po4);
  STRUCTURE.value("LS_He_2s2_4f_2Fo", astrea::element::c_ii::STRUCTURE::LS_He_2s2_4f_2Fo);
  STRUCTURE.value("LS_He_2s2_5s_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s2_5s_2S);
  STRUCTURE.value("LS_He_2s2_5p_2Po2", astrea::element::c_ii::STRUCTURE::LS_He_2s2_5p_2Po2);
  STRUCTURE.value("LS_He_2s2_5p_2Po4", astrea::element::c_ii::STRUCTURE::LS_He_2s2_5p_2Po4);
  STRUCTURE.value("LS_He_2s_2p_3Po_3s_2Po2", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3s_2Po2);
  STRUCTURE.value("LS_He_2s_2p_3Po_3s_2Po4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3s_2Po4);
  STRUCTURE.value("LS_He_2s2_5d_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s2_5d_2D);
  STRUCTURE.value("LS_He_2s2_5f_2Fo", astrea::element::c_ii::STRUCTURE::LS_He_2s2_5f_2Fo);
  STRUCTURE.value("LS_He_2s2_5g_2G", astrea::element::c_ii::STRUCTURE::LS_He_2s2_5g_2G);
  STRUCTURE.value("LS_He_2s2_6s_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s2_6s_2S);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4D2", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4D2);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4D4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4D4);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4D6", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4D6);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4D8", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4D8);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_2P2", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_2P2);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_2P4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_2P4);
  STRUCTURE.value("LS_He_2s2_6p_2Po", astrea::element::c_ii::STRUCTURE::LS_He_2s2_6p_2Po);
  STRUCTURE.value("LS_He_2s2_6d_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s2_6d_2D);
  STRUCTURE.value("LS_He_2s2_6f_2Fo", astrea::element::c_ii::STRUCTURE::LS_He_2s2_6f_2Fo);
  STRUCTURE.value("LS_He_2s2_6g_2G", astrea::element::c_ii::STRUCTURE::LS_He_2s2_6g_2G);
  STRUCTURE.value("LS_He_2s2_6h_2Ho", astrea::element::c_ii::STRUCTURE::LS_He_2s2_6h_2Ho);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4S", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4S);
  STRUCTURE.value("LS_He_2s2_7s_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s2_7s_2S);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4P2", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4P2);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4P4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4P4);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_4P6", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_4P6);
  STRUCTURE.value("LS_He_2s2_7p_2Po", astrea::element::c_ii::STRUCTURE::LS_He_2s2_7p_2Po);
  STRUCTURE.value("LS_He_2s2_7d_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s2_7d_2D);
  STRUCTURE.value("LS_He_2s2_7f_2Fo", astrea::element::c_ii::STRUCTURE::LS_He_2s2_7f_2Fo);
  STRUCTURE.value("LS_He_2s2_7g_He_2s2_7i", astrea::element::c_ii::STRUCTURE::LS_He_2s2_7g_He_2s2_7i);
  STRUCTURE.value("LS_He_2s2_8s_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s2_8s_2S);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_2D4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_2D4);
  STRUCTURE.value("LS_He_2s_2p_3Po_3p_2D6", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3p_2D6);
  STRUCTURE.value("LS_He_2s2_8p_2Po", astrea::element::c_ii::STRUCTURE::LS_He_2s2_8p_2Po);
  STRUCTURE.value("LS_He_2s2_8d_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s2_8d_2D);
  STRUCTURE.value("LS_He_2s2_8f_2Fo", astrea::element::c_ii::STRUCTURE::LS_He_2s2_8f_2Fo);
  STRUCTURE.value("LS_He_2s2_8g_He_2s2_8k", astrea::element::c_ii::STRUCTURE::LS_He_2s2_8g_He_2s2_8k);
  STRUCTURE.value("LS_He_2s2_11d_He_2s2_11k", astrea::element::c_ii::STRUCTURE::LS_He_2s2_11d_He_2s2_11k);
  STRUCTURE.value("LS_He_2s2_9s_2S", astrea::element::c_ii::STRUCTURE::LS_He_2s2_9s_2S);
  STRUCTURE.value("LS_He_2s2_9p_2Po", astrea::element::c_ii::STRUCTURE::LS_He_2s2_9p_2Po);
  STRUCTURE.value("LS_He_2s2_9d_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s2_9d_2D);
  STRUCTURE.value("LS_He_2s2_9f_2Fo", astrea::element::c_ii::STRUCTURE::LS_He_2s2_9f_2Fo);
  STRUCTURE.value("LS_He_2s2_9g_He_2s2_9l", astrea::element::c_ii::STRUCTURE::LS_He_2s2_9g_He_2s2_9l);
  STRUCTURE.value("LS_He_2s2_10p_2Po", astrea::element::c_ii::STRUCTURE::LS_He_2s2_10p_2Po);
  STRUCTURE.value("LS_He_2s2_10d_2D", astrea::element::c_ii::STRUCTURE::LS_He_2s2_10d_2D);
  STRUCTURE.value("LS_He_2s2_10f_2Fo", astrea::element::c_ii::STRUCTURE::LS_He_2s2_10f_2Fo);
  STRUCTURE.value("LS_He_2s2_12d_He_2s2_12k", astrea::element::c_ii::STRUCTURE::LS_He_2s2_12d_He_2s2_12k);
  STRUCTURE.value("LS_He_2s2_13f_He_2s2_13k", astrea::element::c_ii::STRUCTURE::LS_He_2s2_13f_He_2s2_13k);
  STRUCTURE.value("LS_He_2s_2p_3Po_3d_4Fo4", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3d_4Fo4);
  STRUCTURE.value("LS_He_2s_2p_3Po_3d_4Fo6", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3d_4Fo6);
  STRUCTURE.value("LS_He_2s_2p_3Po_3d_4Fo8", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3d_4Fo8);
  STRUCTURE.value("LS_He_2s_2p_3Po_3d_4Fo10", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3d_4Fo10);
  STRUCTURE.value("LS_He_2s_2p_3Po_3d_4Do2_4Do4_4Do6", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3d_4Do2_4Do4_4Do6);
  STRUCTURE.value("LS_He_2s_2p_3Po_3d_4Do8", astrea::element::c_ii::STRUCTURE::LS_He_2s_2p_3Po_3d_4Do8);
}


}