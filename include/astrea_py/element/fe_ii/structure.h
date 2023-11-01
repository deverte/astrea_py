#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_ii {


inline void structure(py::module_& m) {
  // Fe II structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  // Based on Mashonkina+2011 Fe II model.
  py::enum_<astrea::element::fe_ii::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_Ar_3d6_5D_4s_a6D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4s_a6D);
  STRUCTURE.value("LS_Ar_3d7_a4F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_a4F);
  STRUCTURE.value("LS_Ar_3d6_5D_4s_a4D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4s_a4D);
  STRUCTURE.value("LS_Ar_3d7_a4P", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_a4P);
  STRUCTURE.value("LS_Ar_3d7_a2G", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_a2G);
  STRUCTURE.value("LS_Ar_3d7_a2P", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_a2P);
  STRUCTURE.value("LS_Ar_3d7_a2H", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_a2H);
  STRUCTURE.value("LS_Ar_3d7_a2D2", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_a2D2);
  STRUCTURE.value("LS_Ar_3d6_3P2_4s_b4P", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4s_b4P);
  STRUCTURE.value("LS_Ar_3d6_3H_4s_a4H", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4s_a4H);
  STRUCTURE.value("LS_Ar_3d6_3F2_4s_b4F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4s_b4F);
  STRUCTURE.value("LS_Ar_3d5_4s2_a6S", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_4s2_a6S);
  STRUCTURE.value("LS_Ar_3d6_3G_4s_a4G", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4s_a4G);
  STRUCTURE.value("LS_Ar_3d6_3P2_4s_b2P", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4s_b2P);
  STRUCTURE.value("LS_Ar_3d6_3H_4s_b2H", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4s_b2H);
  STRUCTURE.value("LS_Ar_3d6_3F2_4s_a2F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4s_a2F);
  STRUCTURE.value("LS_Ar_3d6_3G_4s_b2G", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4s_b2G);
  STRUCTURE.value("LS_Ar_3d6_3D_4s_b4D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4s_b4D);
  STRUCTURE.value("LS_Ar_3d7_b2F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_b2F);
  STRUCTURE.value("LS_Ar_3d6_1I_4s_a2I", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1I_4s_a2I);
  STRUCTURE.value("LS_Ar_3d6_1G2_4s_c2G", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1G2_4s_c2G);
  STRUCTURE.value("LS_Ar_3d6_3D_4s_b2D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4s_b2D);
  STRUCTURE.value("LS_Ar_3d6_1S2_4s_a2S", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1S2_4s_a2S);
  STRUCTURE.value("LS_Ar_3d6_1D2_4s_c2D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1D2_4s_c2D);
  STRUCTURE.value("LS_Ar_3d6_5D_4p_z6Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4p_z6Do);
  STRUCTURE.value("LS_Ar_3d6_5D_4p_z6Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4p_z6Fo);
  STRUCTURE.value("LS_Ar_3d6_5D_4p_z6Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4p_z6Po);
  STRUCTURE.value("LS_Ar_3d6_5D_4p_z4Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4p_z4Fo);
  STRUCTURE.value("LS_Ar_3d6_5D_4p_z4Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4p_z4Do);
  STRUCTURE.value("LS_Ar_3d6_1F_4s_c2F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1F_4s_c2F);
  STRUCTURE.value("LS_Ar_3d6_5D_4p_z4Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_4p_z4Po);
  STRUCTURE.value("LS_Ar_3d7_d2D1", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d7_d2D1);
  STRUCTURE.value("LS_Ar_3d6_3P1_4s_c4P", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P1_4s_c4P);
  STRUCTURE.value("LS_Ar_3d6_3F1_4s_c4F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F1_4s_c4F);
  STRUCTURE.value("LS_Ar_3d5_6S_4s_4p_3Po_z8Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_6S_4s_4p_3Po_z8Po);
  STRUCTURE.value("LS_Ar_3d5_4s2_b4G", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_4s2_b4G);
  STRUCTURE.value("LS_Ar_3d6_3P1_4s_c2P", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P1_4s_c2P);
  STRUCTURE.value("LS_Ar_3d6_3F1_4s_d2F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F1_4s_d2F);
  STRUCTURE.value("LS_Ar_3d5_4s2_d4P", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_4s2_d4P);
  STRUCTURE.value("LS_Ar_3d6_1G1_4s_d2G", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1G1_4s_d2G);
  STRUCTURE.value("LS_Ar_3d6_3P2_4p_z4So", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4p_z4So);
  STRUCTURE.value("LS_Ar_3d5_4s2_c4D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_4s2_c4D);
  STRUCTURE.value("LS_Ar_3d6_3P2_4p_y4Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4p_y4Po);
  STRUCTURE.value("LS_Ar_3d6_3H_4p_z4Go", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4p_z4Go);
  STRUCTURE.value("LS_Ar_3d6_3H_4p_z4Ho", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4p_z4Ho);
  STRUCTURE.value("LS_Ar_3d6_3H_4p_z4Io", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4p_z4Io);
  STRUCTURE.value("LS_Ar_3d6_3P2_4p_z2Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4p_z2Do);
  STRUCTURE.value("LS_Ar_3d5_6S_4s_4p_3Po_y6Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_6S_4s_4p_3Po_y6Po);
  STRUCTURE.value("LS_Ar_3d6_3F2_4p_y4Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4p_y4Fo);
  STRUCTURE.value("LS_Ar_3d6_3H_4p_z2Go", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4p_z2Go);
  STRUCTURE.value("LS_Ar_3d6_3P2_4p_y4Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4p_y4Do);
  STRUCTURE.value("LS_Ar_3d6_3H_4p_z2Io", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4p_z2Io);
  STRUCTURE.value("LS_Ar_3d6_3F2_4p_x4Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4p_x4Do);
  STRUCTURE.value("LS_Ar_3d6_3F2_4p_y4Go", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4p_y4Go);
  STRUCTURE.value("LS_Ar_3d6_3F2_4p_z2Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4p_z2Fo);
  STRUCTURE.value("LS_Ar_3d6_3P2_4p_z2Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4p_z2Po);
  STRUCTURE.value("LS_Ar_3d6_3F2_4p_y2Go", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4p_y2Go);
  STRUCTURE.value("LS_Ar_3d6_3H_4p_z2Ho", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3H_4p_z2Ho);
  STRUCTURE.value("LS_Ar_3d6_3G_4p_x4Go", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4p_x4Go);
  STRUCTURE.value("LS_Ar_3d6_3P2_4p_z2So", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3P2_4p_z2So);
  STRUCTURE.value("LS_Ar_3d6_3G_4p_x4Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4p_x4Fo);
  STRUCTURE.value("LS_Ar_3d6_3G_4p_y4Ho", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4p_y4Ho);
  STRUCTURE.value("LS_Ar_3d6_3F2_4p_y2Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3F2_4p_y2Do);
  STRUCTURE.value("LS_Ar_3d6_3G_4p_y2Ho", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4p_y2Ho);
  STRUCTURE.value("LS_Ar_3d5_6S_4s_4p_3Po_x4Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_6S_4s_4p_3Po_x4Po);
  STRUCTURE.value("LS_Ar_3d6_3G_4p_y2Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4p_y2Fo);
  STRUCTURE.value("LS_Ar_3d6_3G_4p_x2Go", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_4p_x2Go);
  STRUCTURE.value("LS_Ar_3d6_1I_4p_z2Ko", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1I_4p_z2Ko);
  STRUCTURE.value("LS_Ar_3d6_3D_4p_w4Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4p_w4Po);
  STRUCTURE.value("LS_Ar_3d6_1G2_4p_x2Ho", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1G2_4p_x2Ho);
  STRUCTURE.value("LS_Ar_3d6_3D_4p_w4Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4p_w4Fo);
  STRUCTURE.value("LS_Ar_3d6_3D_4p_w4Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4p_w4Do);
  STRUCTURE.value("LS_Ar_3d6_1G2_4p_x2Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1G2_4p_x2Fo);
  STRUCTURE.value("LS_Ar_3d6_1G2_4p_w2Go", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1G2_4p_w2Go);
  STRUCTURE.value("LS_Ar_3d6_3D_4p_y2Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4p_y2Po);
  STRUCTURE.value("LS_Ar_3d5_4s2_4F", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_4s2_4F);
  STRUCTURE.value("LS_Ar_3d6_1I_4p_w2Ho", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1I_4p_w2Ho);
  STRUCTURE.value("LS_Ar_3d6_1I_4p_y2Io", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1I_4p_y2Io);
  STRUCTURE.value("LS_Ar_3d6_3D_4p_x2Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4p_x2Do);
  STRUCTURE.value("LS_Ar_3d6_3D_4p_w2Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3D_4p_w2Fo);
  STRUCTURE.value("LS_Ar_3d6_1S2_4p_x2Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1S2_4p_x2Po);
  STRUCTURE.value("LS_Ar_3d5_4s2_2H", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_4s2_2H);
  STRUCTURE.value("LS_Ar_3d6_1D2_4p_v2Fo", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1D2_4p_v2Fo);
  STRUCTURE.value("LS_Ar_3d6_5D_5s_e6D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_5s_e6D);
  STRUCTURE.value("LS_Ar_3d6_3G_5s_e2G", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_3G_5s_e2G);
  STRUCTURE.value("LS_Ar_3d6_1D2_4p_w2Do", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1D2_4p_w2Do);
  STRUCTURE.value("LS_Ar_3d6_1D2_4p_w2Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_1D2_4p_w2Po);
  STRUCTURE.value("LS_Ar_3d5_6S_4s_4p_1Po_x6Po", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d5_6S_4s_4p_1Po_x6Po);
  STRUCTURE.value("LS_Ar_3d6_5D_5s_e4D", astrea::element::fe_ii::STRUCTURE::LS_Ar_3d6_5D_5s_e4D);
}


}