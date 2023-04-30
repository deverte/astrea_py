#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void nlte_population(py::module_& m) {
  m.def("nlte_population", &astrea::nlte_population);
}


}