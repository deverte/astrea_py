#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void sun_linsky(py::module_& m) {
  m.doc() =
    "Solar EUV spectrum by Linsky+2013.\n"
    "tabulated spectra photons/s/cm^2/Angtrem\n"
    "very low activity\n"
    "Total energy from 4 A to 912 A is 2.164 erg/cm^2/s at R=1 a.u.\n"
    "Total energy from 912 A to 1100 A (Carbon ionization) is\n"
    "0.4 erg/cm^2/s at R=1 a.u.\n"
    "Total energy from 912 A to 1550 A (Si and Fe ionization) is\n"
    "8.6 erg/cm^2/s at R=1 a.u.\n"
    "Hydrogen ionization time at R=0.05 a.u. is 5.78 hours.\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::sun_linsky::E_q_lambda_vs_lambda,
    "Solar EUV spectrum by Linsky+2013.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::sun_linsky::F_lambda_vs_lambda,
    "Solar EUV spectrum by Linsky+2013.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}