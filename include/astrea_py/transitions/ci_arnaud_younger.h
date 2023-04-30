#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void ci_arnaud_younger_rates(py::module_& m) {
  m.def("ci_arnaud_younger_rates", &astrea::ci_arnaud_younger_rates);
}


}