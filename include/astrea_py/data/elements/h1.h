#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void H1(py::module_& m) {
  py::class_<astrea::H1, astrea::Element, std::shared_ptr<astrea::H1>> h1(m, "H1");

  h1.def(py::init<>());
}


}