#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void se_nist_o1_rates(py::module_& m) {
  m.def("se_nist_o1_rates", &astrea::se_nist_o1_rates);
}


}