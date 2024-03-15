#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void hd_85512_muscles(py::module_& m) {
  m.doc() =
    "HD 85512 spectrum by MUSCLES survey.\n"
    "K6 star, Total energy below 912 A is 107 erg/cm^2/s at R=1 a.u.\n"
    "should be divided by 35 (!) fo Fxuv=3.05 erg/cm^2/s at R=1 a.u.\n"
    "Rescaled to Fxuv=3.05 the spectra has Fvuv=61 erg/cm^2/s and\n"
    "Flya=6.4 erg/cm^2/s\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::hd_85512_muscles::E_q_lambda_vs_lambda,
    "HD 85512 spectrum by MUSCLES survey.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::hd_85512_muscles::F_lambda_vs_lambda,
    "HD 85512 spectrum by MUSCLES survey.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}