#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void kelt_9_fossati(py::module_& m) {
  m.doc() =
    "Kelt 9 spectrum by Fossati (private communication)\n"
  ;

  m.def(
    "F_lambda_vs_lambda",
    &astrea::spectrum::kelt_9_fossati::F_lambda_vs_lambda,
    "Kelt 9 spectrum by Fossati (private communication).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Wavelength in nm.\n"
    "  - 1: Spectral irradiance in W m-2 nm-1.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}