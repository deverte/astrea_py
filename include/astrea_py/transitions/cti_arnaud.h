#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void cti_arnaud_rates(py::module_& m) {
  m.def("cti_arnaud_rates", &astrea::cti_arnaud_rates);
}


}