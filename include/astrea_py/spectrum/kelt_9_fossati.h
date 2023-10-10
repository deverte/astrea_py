#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::spectrum {


inline void kelt_9_fossati(py::module_& m) {
  m.doc() = "Kelt 9 spectrum using Fossati data.";

  m.def(
    "spectrum",
    &astrea::spectrum::kelt_9_fossati::spectrum,
    "KELT-9 spectrum at 1 au.\n"
    "Row 0: wavelengths in nm.\n"
    "Row 1: spectral_irradiance in W m-2 nm-1.\n"
  );
}


}