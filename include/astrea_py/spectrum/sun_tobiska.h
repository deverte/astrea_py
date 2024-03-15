#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void sun_tobiska(py::module_& m) {
  m.doc() =
    "Solar XUV 9 spectrum by Tobiska1993.\n"
    "tabulated spectra photons/s/cm^2/dlambda.\n"
    "F(10.7)=148\n"
    "Total energy is 4.466 erg/cm^2/s at R=1 a.u.\n"
    "Hydrogen ionization time at R=0.05 a.u. is 3.7 hours\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::sun_tobiska::E_q_lambda_vs_lambda,
    "Solar XUV 9 spectrum by Tobiska1993.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::sun_tobiska::F_lambda_vs_lambda,
    "Solar XUV 9 spectrum by Tobiska1993.\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}