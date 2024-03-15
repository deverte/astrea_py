#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void hd_73583_zhang(py::module_& m) {
  m.doc() =
    "HD 73583 spectrum by Zhang+2022.\n"
    "Total energy below 912 A is 16 erg/cm^2/s at R=1 a.u.\n"
    "Flya=18.3 erg/cm^2/s at R=1 a.u.\n"
    "Total energy between 912 and 3000 A should be 332 erg/cm^2/s at R=1 a.u.\n"
    "Flux at 10830 is 14 erg/cm^2/s/A\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::hd_73583_zhang::E_q_lambda_vs_lambda,
    "HD 73583 spectrum by Zhang+2022.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::hd_73583_zhang::F_lambda_vs_lambda,
    "HD 73583 spectrum by Zhang+2022.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}