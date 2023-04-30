#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void He2(py::module_& m) {
  py::class_<astrea::He2, astrea::Element, std::shared_ptr<astrea::He2>> he2(m, "He2");

  he2.def(py::init<>());
}


}