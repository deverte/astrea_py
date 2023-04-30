#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void lte_boltzmann_population(py::module_& m) {
  m.def("lte_boltzmann_population", &astrea::lte_boltzmann_population);
}


inline void lte_boltzmann_saha_population(py::module_& m) {
  m.def("lte_boltzmann_saha_population", &astrea::lte_boltzmann_saha_population);
}


}