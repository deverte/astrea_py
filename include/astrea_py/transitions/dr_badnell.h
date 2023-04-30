#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void dr_badnell_rates(py::module_& m) {
  m.def("dr_badnell_rates", &astrea::dr_badnell_rates);
}


}