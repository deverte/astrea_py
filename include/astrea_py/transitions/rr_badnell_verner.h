#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void rr_badnell_verner_rates(py::module_& m) {
  m.def("rr_badnell_verner_rates", &astrea::rr_badnell_verner_rates);
}


}