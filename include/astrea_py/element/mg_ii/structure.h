#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_ii {


inline void structure(py::module_& m) {
  // Mg II structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  // Based on Alexeeva+2018 Mg II model.
  py::enum_<astrea::element::mg_ii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_Ne_3s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_3s_2S);
  STRUCTURE.value("LS_Ne_3p_2Po", astrea::element::mg_ii::STRUCTURE::LS_Ne_3p_2Po);
  STRUCTURE.value("LS_Ne_4s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_4s_2S);
  STRUCTURE.value("LS_Ne_3d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_3d_2D);
  STRUCTURE.value("LS_Ne_4p_2Po2", astrea::element::mg_ii::STRUCTURE::LS_Ne_4p_2Po2);
  STRUCTURE.value("LS_Ne_4p_2Po4", astrea::element::mg_ii::STRUCTURE::LS_Ne_4p_2Po4);
  STRUCTURE.value("LS_Ne_5s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_5s_2S);
  STRUCTURE.value("LS_Ne_4d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_4d_2D);
  STRUCTURE.value("LS_Ne_4f_2Fo", astrea::element::mg_ii::STRUCTURE::LS_Ne_4f_2Fo);
  STRUCTURE.value("LS_Ne_5p_2Po", astrea::element::mg_ii::STRUCTURE::LS_Ne_5p_2Po);
  STRUCTURE.value("LS_Ne_6s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_6s_2S);
  STRUCTURE.value("LS_Ne_5d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_5d_2D);
  STRUCTURE.value("LS_Ne_5f_2Fo", astrea::element::mg_ii::STRUCTURE::LS_Ne_5f_2Fo);
  STRUCTURE.value("LS_Ne_5g_2G", astrea::element::mg_ii::STRUCTURE::LS_Ne_5g_2G);
  STRUCTURE.value("LS_Ne_6p_2Po", astrea::element::mg_ii::STRUCTURE::LS_Ne_6p_2Po);
  STRUCTURE.value("LS_Ne_7s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_7s_2S);
  STRUCTURE.value("LS_Ne_6d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_6d_2D);
  STRUCTURE.value("LS_Ne_6f_2Fo", astrea::element::mg_ii::STRUCTURE::LS_Ne_6f_2Fo);
  STRUCTURE.value("LS_Ne_6g_2G", astrea::element::mg_ii::STRUCTURE::LS_Ne_6g_2G);
  STRUCTURE.value("LS_Ne_6h_2Ho", astrea::element::mg_ii::STRUCTURE::LS_Ne_6h_2Ho);
  STRUCTURE.value("LS_Ne_7p_2Po", astrea::element::mg_ii::STRUCTURE::LS_Ne_7p_2Po);
  STRUCTURE.value("LS_Ne_8s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_8s_2S);
  STRUCTURE.value("LS_Ne_7d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_7d_2D);
  STRUCTURE.value("LS_Ne_7f_2Fo", astrea::element::mg_ii::STRUCTURE::LS_Ne_7f_2Fo);
  STRUCTURE.value("LS_Ne_7g_2G", astrea::element::mg_ii::STRUCTURE::LS_Ne_7g_2G);
  STRUCTURE.value("LS_Ne_7h_Ne_7i", astrea::element::mg_ii::STRUCTURE::LS_Ne_7h_Ne_7i);
  STRUCTURE.value("LS_Ne_8p_2Po", astrea::element::mg_ii::STRUCTURE::LS_Ne_8p_2Po);
  STRUCTURE.value("LS_Ne_9s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_9s_2S);
  STRUCTURE.value("LS_Ne_8d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_8d_2D);
  STRUCTURE.value("LS_Ne_8f_2Fo", astrea::element::mg_ii::STRUCTURE::LS_Ne_8f_2Fo);
  STRUCTURE.value("LS_Ne_8g_2G", astrea::element::mg_ii::STRUCTURE::LS_Ne_8g_2G);
  STRUCTURE.value("LS_Ne_8h_Ne_8i", astrea::element::mg_ii::STRUCTURE::LS_Ne_8h_Ne_8i);
  STRUCTURE.value("LS_Ne_9p_2Po", astrea::element::mg_ii::STRUCTURE::LS_Ne_9p_2Po);
  STRUCTURE.value("LS_Ne_10s_2S", astrea::element::mg_ii::STRUCTURE::LS_Ne_10s_2S);
  STRUCTURE.value("LS_Ne_9d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_9d_2D);
  STRUCTURE.value("LS_Ne_9f_2Fo", astrea::element::mg_ii::STRUCTURE::LS_Ne_9f_2Fo);
  STRUCTURE.value("LS_Ne_9g_Ne_9i", astrea::element::mg_ii::STRUCTURE::LS_Ne_9g_Ne_9i);
  STRUCTURE.value("LS_Ne_10p_2Po", astrea::element::mg_ii::STRUCTURE::LS_Ne_10p_2Po);
  STRUCTURE.value("LS_Ne_10d_2D", astrea::element::mg_ii::STRUCTURE::LS_Ne_10d_2D);
  STRUCTURE.value("LS_Ne_10f_2Fo", astrea::element::mg_ii::STRUCTURE::LS_Ne_10f_2Fo);
  STRUCTURE.value("LS_Ne_10g_2G", astrea::element::mg_ii::STRUCTURE::LS_Ne_10g_2G);
  STRUCTURE.value("LS_Ne_10h_Ne_10i", astrea::element::mg_ii::STRUCTURE::LS_Ne_10h_Ne_10i);
  STRUCTURE.value("LS_Ne_11g_2G", astrea::element::mg_ii::STRUCTURE::LS_Ne_11g_2G);
}


}