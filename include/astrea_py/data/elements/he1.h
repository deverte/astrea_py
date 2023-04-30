#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void He1(py::module_& m) {
  py::class_<astrea::He1, astrea::Element, std::shared_ptr<astrea::He1>> he1(m, "He1");

  he1.def(py::init<>());
}


}