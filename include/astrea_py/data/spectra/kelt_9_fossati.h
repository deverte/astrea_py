#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void Kelt9Fossati(py::module_& m) {
  py::class_<
    astrea::Kelt9Fossati, astrea::Spectrum, std::shared_ptr<astrea::Kelt9Fossati>
  >
  kelt_9_fossati(m, "Kelt9Fossati");

  kelt_9_fossati.def(py::init<>());
}


}