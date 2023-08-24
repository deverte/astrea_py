#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void rd_nist_o1_rates(py::module_& m) {
  m.def("rd_nist_o1_rates", &astrea::rd_nist_o1_rates);
}


}