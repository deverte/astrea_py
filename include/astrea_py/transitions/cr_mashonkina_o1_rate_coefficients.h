#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void cr_mashonkina_o1_rate_coefficients(py::module_& m) {
  m.def(
    "cr_mashonkina_o1_rate_coefficients",
    &astrea::cr_mashonkina_o1_rate_coefficients
  );
}


}