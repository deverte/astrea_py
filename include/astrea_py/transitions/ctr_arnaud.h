#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void ctr_arnaud_rates(py::module_& m) {
  m.def("ctr_arnaud_rates", &astrea::ctr_arnaud_rates);
}


}