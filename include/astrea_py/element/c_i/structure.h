#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::c_i {


inline void structure(py::module_& m) {
  // C I structure from NIST (https://www.nist.gov/pml/atomic-spectra-database).
  // Based on Alexeeva+2015 C I model.
  py::enum_<astrea::element::c_i::STRUCTURE> STRUCTURE(m, "STRUCTURE");
  STRUCTURE.value("LS_He_2s2_2p2_3P0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p2_3P0);
  STRUCTURE.value("LS_He_2s2_2p2_3P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p2_3P1);
  STRUCTURE.value("LS_He_2s2_2p2_3P2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p2_3P2);
  STRUCTURE.value("LS_He_2s2_2p2_1D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p2_1D2);
  STRUCTURE.value("LS_He_2s2_2p2_1S0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p2_1S0);
  STRUCTURE.value("LS_He_2s_2p3_5So2", astrea::element::c_i::STRUCTURE::LS_He_2s_2p3_5So2);
  STRUCTURE.value("LS_He_2s2_2p_3s_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3s_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_3s_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3s_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_3s_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3s_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_3s_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3s_1Po1);
  STRUCTURE.value("LS_He_2s_2p3_3Do", astrea::element::c_i::STRUCTURE::LS_He_2s_2p3_3Do);
  STRUCTURE.value("LS_He_2s2_2p_3p_1P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_1P1);
  STRUCTURE.value("LS_He_2s2_2p_3p_3D1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_3D1);
  STRUCTURE.value("LS_He_2s2_2p_3p_3D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_3D2);
  STRUCTURE.value("LS_He_2s2_2p_3p_3D3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_3D3);
  STRUCTURE.value("LS_He_2s2_2p_3p_3S1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_3S1);
  STRUCTURE.value("LS_He_2s2_2p_3p_3P0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_3P0);
  STRUCTURE.value("LS_He_2s2_2p_3p_3P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_3P1);
  STRUCTURE.value("LS_He_2s2_2p_3p_3P2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_3P2);
  STRUCTURE.value("LS_He_2s2_2p_3p_1D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_1D2);
  STRUCTURE.value("LS_He_2s2_2p_3p_1S0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3p_1S0);
  STRUCTURE.value("LS_He_2s_2p3_3Po", astrea::element::c_i::STRUCTURE::LS_He_2s_2p3_3Po);
  STRUCTURE.value("LS_He_2s2_2p_3d_1Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_1Do2);
  STRUCTURE.value("LS_He_2s2_2p_4s_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4s_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_4s_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4s_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_4s_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4s_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Fo2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Fo2);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Fo3);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Fo4", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Fo4);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Do1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Do1);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Do2);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Do3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Do3);
  STRUCTURE.value("LS_He_2s2_2p_4s_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4s_1Po1);
  STRUCTURE.value("LS_He_2s2_2p_3d_1Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_1Fo3);
  STRUCTURE.value("LS_He_2s2_2p_3d_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_1Po1);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_3d_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_3d_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_4p_1P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_1P1);
  STRUCTURE.value("LS_He_2s2_2p_4p_3D1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_3D1);
  STRUCTURE.value("LS_He_2s2_2p_4p_3D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_3D2);
  STRUCTURE.value("LS_He_2s2_2p_4p_3D3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_3D3);
  STRUCTURE.value("LS_He_2s2_2p_4p_3S1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_3S1);
  STRUCTURE.value("LS_He_2s2_2p_4p_3P0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_3P0);
  STRUCTURE.value("LS_He_2s2_2p_4p_3P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_3P1);
  STRUCTURE.value("LS_He_2s2_2p_4p_3P2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_3P2);
  STRUCTURE.value("LS_He_2s2_2p_4p_1D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_1D2);
  STRUCTURE.value("LS_He_2s2_2p_4p_1S0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4p_1S0);
  STRUCTURE.value("LS_He_2s2_2p_4d_1Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_1Do2);
  STRUCTURE.value("LS_He_2s2_2p_5s_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5s_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_5s_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5s_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_5s_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5s_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Fo3);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Fo2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Fo2);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Fo4", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Fo4);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Do1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Do1);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Do2);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Do3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Do3);
  STRUCTURE.value("LS_He_2s2_2p_5s_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5s_1Po1);
  STRUCTURE.value("_10f57", astrea::element::c_i::STRUCTURE::_10f57);
  STRUCTURE.value("LS_He_2s2_2p_4d_1Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_1Fo3);
  STRUCTURE.value("_3f579", astrea::element::c_i::STRUCTURE::_3f579);
  STRUCTURE.value("LS_He_2s2_2p_4d_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_1Po1);
  STRUCTURE.value("_3124f3", astrea::element::c_i::STRUCTURE::_3124f3);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_4d_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_4d_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_5p_1P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_1P1);
  STRUCTURE.value("LS_He_2s2_2p_5p_3D1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_3D1);
  STRUCTURE.value("LS_He_2s2_2p_5p_3D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_3D2);
  STRUCTURE.value("LS_He_2s2_2p_5p_3S1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_3S1);
  STRUCTURE.value("LS_He_2s2_2p_5p_3D3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_3D3);
  STRUCTURE.value("LS_He_2s2_2p_5p_3P", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_3P);
  STRUCTURE.value("LS_He_2s2_2p_5p_1D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_1D2);
  STRUCTURE.value("LS_He_2s2_2p_5p_1S0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5p_1S0);
  STRUCTURE.value("LS_He_2s2_2p_5d_1Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_1Do2);
  STRUCTURE.value("LS_He_2s2_2p_5d_3Fo2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_3Fo2);
  STRUCTURE.value("LS_He_2s2_2p_6s_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6s_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_5d_3Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_3Fo3);
  STRUCTURE.value("LS_He_2s2_2p_6s_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6s_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_5d_3Do1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_3Do1);
  STRUCTURE.value("LS_He_2s2_2p_5d_3Fo4", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_3Fo4);
  STRUCTURE.value("LS_He_2s2_2p_6s_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6s_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_5d_3Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_3Do2);
  STRUCTURE.value("LS_He_2s2_2p_5d_3Do3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_3Do3);
  STRUCTURE.value("LS_He_2s2_2p_6s_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6s_1Po1);
  STRUCTURE.value("_335f7", astrea::element::c_i::STRUCTURE::_335f7);
  STRUCTURE.value("LS_He_2s2_2p_5d_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_1Po1);
  STRUCTURE.value("_315f3", astrea::element::c_i::STRUCTURE::_315f3);
  STRUCTURE.value("LS_He_2s2_2p_5d_3Po", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_5d_3Po);
  STRUCTURE.value("LS_He_2s2_2p_6p_1P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_1P1);
  STRUCTURE.value("LS_He_2s2_2p_6p_3D1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_3D1);
  STRUCTURE.value("LS_He_2s2_2p_6p_3S1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_3S1);
  STRUCTURE.value("LS_He_2s2_2p_6p_3D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_3D2);
  STRUCTURE.value("LS_He_2s2_2p_6p_3D3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_3D3);
  STRUCTURE.value("LS_He_2s2_2p_6p_3P", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_3P);
  STRUCTURE.value("LS_He_2s2_2p_6p_1D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_1D2);
  STRUCTURE.value("LS_He_2s2_2p_6p_1S0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6p_1S0);
  STRUCTURE.value("LS_He_2s2_2p_6d_1Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_1Do2);
  STRUCTURE.value("LS_He_2s2_2p_6d_3Fo2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_3Fo2);
  STRUCTURE.value("LS_He_2s2_2p_7s_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7s_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_6d_3Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_3Fo3);
  STRUCTURE.value("LS_He_2s2_2p_7s_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7s_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_6d_3Do1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_3Do1);
  STRUCTURE.value("LS_He_2s2_2p_7s_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7s_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_6d_3Fo4", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_3Fo4);
  STRUCTURE.value("LS_He_2s2_2p_6d_3Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_3Do2);
  STRUCTURE.value("LS_He_2s2_2p_6d_3Do3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_3Do3);
  STRUCTURE.value("LS_He_2s2_2p_7s_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7s_1Po1);
  STRUCTURE.value("LS_He_2s2_2p_6d_1Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_1Fo3);
  STRUCTURE.value("_336f7", astrea::element::c_i::STRUCTURE::_336f7);
  STRUCTURE.value("LS_He_2s2_2p_6d_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_1Po1);
  STRUCTURE.value("LS_He_2s2_2p_6d_3Po", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_6d_3Po);
  STRUCTURE.value("LS_He_2s2_2p_7p_1P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7p_1P1);
  STRUCTURE.value("LS_He_2s2_2p_7p_3S1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7p_3S1);
  STRUCTURE.value("LS_He_2s2_2p_7p_3D", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7p_3D);
  STRUCTURE.value("LS_He_2s2_2p_7p_3P", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7p_3P);
  STRUCTURE.value("LS_He_2s2_2p_7p_1D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7p_1D2);
  STRUCTURE.value("LS_He_2s2_2p_7p_1S0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7p_1S0);
  STRUCTURE.value("LS_He_2s2_2p_7d_1Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_1Do2);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Fo2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Fo2);
  STRUCTURE.value("LS_He_2s2_2p_8s_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8s_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Fo3);
  STRUCTURE.value("LS_He_2s2_2p_8s_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8s_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Do1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Do1);
  STRUCTURE.value("_127f5", astrea::element::c_i::STRUCTURE::_127f5);
  STRUCTURE.value("LS_He_2s2_2p_8s_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8s_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Fo4", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Fo4);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Do2);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Do3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Do3);
  STRUCTURE.value("LS_He_2s2_2p_8s_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8s_1Po1);
  STRUCTURE.value("LS_He_2s2_2p_7d_1Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_1Fo3);
  STRUCTURE.value("_337f7", astrea::element::c_i::STRUCTURE::_337f7);
  STRUCTURE.value("_37f5", astrea::element::c_i::STRUCTURE::_37f5);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Po2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Po2);
  STRUCTURE.value("LS_He_2s2_2p_7d_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_1Po1);
  STRUCTURE.value("_227f3", astrea::element::c_i::STRUCTURE::_227f3);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_7d_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_7d_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_8p_1P1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8p_1P1);
  STRUCTURE.value("LS_He_2s2_2p_8p_3S1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8p_3S1);
  STRUCTURE.value("LS_He_2s2_2p_8p_3D", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8p_3D);
  STRUCTURE.value("LS_He_2s2_2p_8p_3P2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8p_3P2);
  STRUCTURE.value("LS_He_2s2_2p_8p_1D2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8p_1D2);
  STRUCTURE.value("LS_He_2s2_2p_8p_1S0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8p_1S0);
  STRUCTURE.value("LS_He_2s2_2p_8d_1Do2", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8d_1Do2);
  STRUCTURE.value("LS_He_2s2_2p_9s_3Po0", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_9s_3Po0);
  STRUCTURE.value("LS_He_2s2_2p_9s_3Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_9s_3Po1);
  STRUCTURE.value("LS_He_2s2_2p_8d_3Fo", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8d_3Fo);
  STRUCTURE.value("LS_He_2s2_2p_8d_3Do", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8d_3Do);
  STRUCTURE.value("LS_He_2s2_2p_9s_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_9s_1Po1);
  STRUCTURE.value("LS_He_2s2_2p_8d_1Fo3", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8d_1Fo3);
  STRUCTURE.value("LS_He_2s2_2p_8d_1Po1", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8d_1Po1);
  STRUCTURE.value("LS_He_2s2_2p_8d_3Po", astrea::element::c_i::STRUCTURE::LS_He_2s2_2p_8d_3Po);
  STRUCTURE.value("_SL3", astrea::element::c_i::STRUCTURE::_SL3);
  STRUCTURE.value("_SL1", astrea::element::c_i::STRUCTURE::_SL1);
  STRUCTURE.value("_SL3o", astrea::element::c_i::STRUCTURE::_SL3o);
  STRUCTURE.value("_SL1o", astrea::element::c_i::STRUCTURE::_SL1o);
}


}