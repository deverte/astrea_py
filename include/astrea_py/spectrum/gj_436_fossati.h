#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void gj_436_fossati(py::module_& m) {
  m.doc() =
    "GJ 436 XUV spectrum by Fossati (private communication).\n"
    "Total energy is 0.86 erg/cm^2/s at R=1 a.u.\n"
    "Hydrogen ionization rate at GJ436b orbit 9.5e-6 s^-1 (29.2 hours)\n"
  ;

  m.def(
    "E_q_lambda_vs_lambda",
    &astrea::spectrum::gj_436_fossati::E_q_lambda_vs_lambda,
    "GJ 436 XUV spectrum by Fossati (private communication).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in A.\n"
    "  - 1: Spectral irradiance in s-1 cm-2 A-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::gj_436_fossati::F_lambda_vs_lambda,
    "GJ 436 XUV spectrum by Fossati (private communication).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}