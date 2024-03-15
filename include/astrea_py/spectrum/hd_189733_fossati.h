#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void hd_189733_fossati(py::module_& m) {
  m.doc() =
    "HD 189733 XUV spectrum by Fossati (private communication).\n"
    "Total energy in XUV is 25.2 erg/cm^2/s at R=1 a.u.\n"
    "In VUV 1072 erg/cm^2/s at R=1 a.u.\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::hd_189733_fossati::E_q_lambda_vs_lambda,
    "HD 189733 XUV spectrum by Fossati (private communication).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::hd_189733_fossati::F_lambda_vs_lambda,
    "HD 189733 XUV spectrum by Fossati (private communication).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}