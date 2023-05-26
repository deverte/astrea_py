#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void pi_mashonkina_o1_rates(py::module_& m) {
  m.def("pi_mashonkina_o1_rates", &astrea::pi_mashonkina_o1_rates);
}


}