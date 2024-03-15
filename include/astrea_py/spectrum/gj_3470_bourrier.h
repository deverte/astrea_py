#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void gj_3470_bourrier(py::module_& m) {
  m.doc() =
    "GJ 3470 XUV spectrum by Bourrier+2018 (<1200 A), Salz+2016 (>1200 A).\n"
    "Total energy below 912 A is 4.91 erg/cm^2 at R=1 a.u.\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::gj_3470_bourrier::E_q_lambda_vs_lambda,
    "GJ 3470 XUV spectrum by Bourrier+2018 (<1200 A), Salz+2016 (>1200 A).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::gj_3470_bourrier::F_lambda_vs_lambda,
    "GJ 3470 XUV spectrum by Bourrier+2018 (<1200 A), Salz+2016 (>1200 A).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}