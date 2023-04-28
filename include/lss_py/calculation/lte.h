#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <lss/lss.h>


namespace py = pybind11;


namespace lss_py {


inline void lte_boltzmann_population(py::module_& m) {
  m.def("lte_boltzmann_population", &lss::lte_boltzmann_population);
}


inline void lte_boltzmann_saha_population(py::module_& m) {
  m.def("lte_boltzmann_saha_population", &lss::lte_boltzmann_saha_population);
}


}