#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::math {


inline void voigt_profile(py::module_& m) {
  m.def(
    "V_E",
    &astrea::math::voigt_profile::V_E,
    "Voigt profile.\n"
    "\n"
    ":param H_E: Voigt function.\n"
    ":param sigma: Standard deviation.\n"
    ":return: Distribution.\n",
    py::arg("H_E"),
    py::arg("sigma")
  );
}


}