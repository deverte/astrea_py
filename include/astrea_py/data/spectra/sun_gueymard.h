#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void SunGueymard(py::module_& m) {
  py::class_<astrea::SunGueymard, astrea::Spectrum, std::shared_ptr<astrea::SunGueymard>>
  sun_gueymard(m, "SunGueymard");

  sun_gueymard.def(py::init<>());
}


}