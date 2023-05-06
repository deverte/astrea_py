#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void nlte_population_full(py::module_& m) {
  m.def("nlte_population_full", &astrea::nlte_population_full);
}

inline void nlte_population_per_elements(py::module_& m) {
  m.def("nlte_population_per_elements", &astrea::nlte_population_per_elements);
}


}