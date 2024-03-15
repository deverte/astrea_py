#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void hd_209458_salz(py::module_& m) {
  m.doc() =
    "HD 209458 XUV spectrum by Salz+2016.\n"
    "Total energy below 912 A is 3 erg/cm^2/s at R=1 a.u.\n"
    "Flya=21 erg/cm^2/s at R=1 a.u.\n"
    "Total energy between 912 and 3000 A should be 50000 erg/cm^2/s at R=1 a.u.\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::hd_209458_salz::E_q_lambda_vs_lambda,
    "HD 209458 XUV spectrum by Salz+2016.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::hd_209458_salz::F_lambda_vs_lambda,
    "HD 209458 XUV spectrum by Salz+2016.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}