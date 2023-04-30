#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void rbb_tasitsiomi_rates(py::module_& m) {
  m.def("rbb_tasitsiomi_rates", &astrea::rbb_tasitsiomi_rates);
}


}