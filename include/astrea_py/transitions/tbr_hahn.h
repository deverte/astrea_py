#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void tbr_hahn_rates(py::module_& m) {
  m.def("tbr_hahn_rates", &astrea::tbr_hahn_rates);
}


}