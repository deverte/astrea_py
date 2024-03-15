#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void kelt_9_fossati(py::module_& m) {
  m.doc() =
    "KELT-9 XUV spectrum by Fossati (private communication)\n"
    "Total energy below 912 A is 4.47 erg/cm^2 at R=1 a.u.\n"
    "Total energy at 1000-3000 A is 1.6e7 erg/cm^2 at R=1 a.u.\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::kelt_9_fossati::E_q_lambda_vs_lambda,
    "KELT-9 XUV spectrum by Fossati (private communication).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::kelt_9_fossati::F_lambda_vs_lambda,
    "KELT-9 XUV spectrum by Fossati (private communication).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}