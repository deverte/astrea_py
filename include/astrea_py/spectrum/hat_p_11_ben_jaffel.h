#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void hat_p_11_ben_jaffel(py::module_& m) {
  m.doc() =
    "HAT-P-11 spectrum by Ben-Jaffel+2022.\n"
    "Total energy below 912 A is 15 erg/cm^2/s at R=1 a.u.\n"
    "Flya=6.5 erg/cm^2/s at R=1 a.u.\n"
    "Total energy between 1000 and 3000 A is 950 erg/cm^2/s at R=1 a.u.\n"
    "Flux at 10830 is 20 erg/cm^2/s/A  at R=1 a.u.\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::hat_p_11_ben_jaffel::E_q_lambda_vs_lambda,
    "HAT-P-11 spectrum by Ben-Jaffel+2022.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::hat_p_11_ben_jaffel::F_lambda_vs_lambda,
    "HAT-P-11 spectrum by Ben-Jaffel+2022.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}