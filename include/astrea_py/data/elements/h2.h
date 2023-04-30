#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void H2(py::module_& m) {
  py::class_<astrea::H2, astrea::Element, std::shared_ptr<astrea::H2>> h2(m, "H2");

  h2.def(py::init<>());
}


}