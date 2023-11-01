#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::mg_i {


inline void structure(py::module_& m) {
  // Mg I structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  // Based on Alexeeva+2018 Mg I model.
  py::enum_<astrea::element::mg_i::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_Ne_3s2_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s2_1S);
  STRUCTURE.value("LS_Ne_3s_2S_3p_3Po0", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_3p_3Po0);
  STRUCTURE.value("LS_Ne_3s_2S_3p_3Po1", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_3p_3Po1);
  STRUCTURE.value("LS_Ne_3s_2S_3p_3Po2", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_3p_3Po2);
  STRUCTURE.value("LS_Ne_3s_2S_3p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_3p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_4s_3S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_4s_3S);
  STRUCTURE.value("LS_Ne_3s_2S_4s_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_4s_1S);
  STRUCTURE.value("LS_Ne_3s_2S_3d_1D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_3d_1D);
  STRUCTURE.value("LS_Ne_3s_2S_4p_3Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_4p_3Po);
  STRUCTURE.value("LS_Ne_3s_2S_3d_3D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_3d_3D);
  STRUCTURE.value("LS_Ne_3s_2S_4p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_4p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_5s_3S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5s_3S);
  STRUCTURE.value("LS_Ne_3s_2S_5s_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5s_1S);
  STRUCTURE.value("LS_Ne_3s_2S_4d_1D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_4d_1D);
  STRUCTURE.value("LS_Ne_3s_2S_4d_3D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_4d_3D);
  STRUCTURE.value("LS_Ne_3s_2S_5p_3Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5p_3Po);
  STRUCTURE.value("LS_Ne_3s_2S_4f", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_4f);
  STRUCTURE.value("LS_Ne_3s_2S_5p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_6s_3S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6s_3S);
  STRUCTURE.value("LS_Ne_3s_2S_6s_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6s_1S);
  STRUCTURE.value("LS_Ne_3s_2S_5d_1D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5d_1D);
  STRUCTURE.value("LS_Ne_3s_2S_5d_3D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5d_3D);
  STRUCTURE.value("LS_Ne_3s_2S_6p_3Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6p_3Po);
  STRUCTURE.value("LS_Ne_3s_2S_5f", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5f);
  STRUCTURE.value("LS_Ne_3s_2S_6p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_5g", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_5g);
  STRUCTURE.value("LS_Ne_3p2_3P", astrea::element::mg_i::STRUCTURE::LS_Ne_3p2_3P);
  STRUCTURE.value("LS_Ne_3s_2S_7s_3S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7s_3S);
  STRUCTURE.value("LS_Ne_3s_2S_7s_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7s_1S);
  STRUCTURE.value("LS_Ne_3s_2S_6d_1D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6d_1D);
  STRUCTURE.value("LS_Ne_3s_2S_6d_3D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6d_3D);
  STRUCTURE.value("LS_Ne_3s_2S_7p_3Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7p_3Po);
  STRUCTURE.value("LS_Ne_3s_2S_6f", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6f);
  STRUCTURE.value("LS_Ne_3s_2S_7p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_6g", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6g);
  STRUCTURE.value("LS_Ne_3s_2S_6h_Ho", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_6h_Ho);
  STRUCTURE.value("LS_Ne_3s_2S_8s_3S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8s_3S);
  STRUCTURE.value("LS_Ne_3s_2S_7d_1D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7d_1D);
  STRUCTURE.value("LS_Ne_3s_2S_8s_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8s_1S);
  STRUCTURE.value("LS_Ne_3s_2S_7d_3D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7d_3D);
  STRUCTURE.value("LS_Ne_3s_2S_8p_3Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8p_3Po);
  STRUCTURE.value("LS_Ne_3s_2S_7f", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7f);
  STRUCTURE.value("LS_Ne_3s_2S_8p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_7g", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7g);
  STRUCTURE.value("LS_Ne_3s_2S_7h_Ho", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7h_Ho);
  STRUCTURE.value("LS_Ne_3s_2S_7i_I", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_7i_I);
  STRUCTURE.value("LS_Ne_3s_2S_9s_3S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9s_3S);
  STRUCTURE.value("LS_Ne_3s_2S_8d_1D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8d_1D);
  STRUCTURE.value("LS_Ne_3s_2S_9s_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9s_1S);
  STRUCTURE.value("LS_Ne_3s_2S_8d_3D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8d_3D);
  STRUCTURE.value("LS_Ne_3s_2S_9p_3Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9p_3Po);
  STRUCTURE.value("LS_Ne_3s_2S_8f", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8f);
  STRUCTURE.value("LS_Ne_3s_2S_9p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_8g", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8g);
  STRUCTURE.value("LS_Ne_3s_2S_8h_Ho", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8h_Ho);
  STRUCTURE.value("LS_Ne_3s_2S_8i", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8i);
  STRUCTURE.value("LS_Ne_3s_2S_8k", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_8k);
  STRUCTURE.value("LS_Ne_3s_2S_10s_3S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_10s_3S);
  STRUCTURE.value("LS_Ne_3s_2S_9d_1D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9d_1D);
  STRUCTURE.value("LS_Ne_3s_2S_10s_1S", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_10s_1S);
  STRUCTURE.value("LS_Ne_3s_2S_9d_3D", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9d_3D);
  STRUCTURE.value("LS_Ne_3s_2S_9f", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9f);
  STRUCTURE.value("LS_Ne_3s_2S_10p_1Po", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_10p_1Po);
  STRUCTURE.value("LS_Ne_3s_2S_9g", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9g);
  STRUCTURE.value("LS_Ne_3s_2S_9h_Ho", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9h_Ho);
  STRUCTURE.value("LS_Ne_3s_2S_9i_I", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9i_I);
  STRUCTURE.value("LS_Ne_3s_2S_9k_Ko", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9k_Ko);
  STRUCTURE.value("LS_Ne_3s_2S_9l_L", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_9l_L);
  STRUCTURE.value("LS_Ne_3s_2S_10d_Ne_3s_2S_15f", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_10d_Ne_3s_2S_15f);
  STRUCTURE.value("LS_Ne_3s_2S_16p_Ne_3s_2S_59p", astrea::element::mg_i::STRUCTURE::LS_Ne_3s_2S_16p_Ne_3s_2S_59p);
}


}