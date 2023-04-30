#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void cbb_mashonkina_o1_rates(py::module_& m) {
  m.def("cbb_mashonkina_o1_rates", &astrea::cbb_mashonkina_o1_rates);
}


}