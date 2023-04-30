#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void O1Mashonkina(py::module_& m) {
  py::class_<
    astrea::O1Mashonkina,
    astrea::Element,
    std::shared_ptr<astrea::O1Mashonkina>
  >
  o1_inasan(m, "O1Mashonkina");

  o1_inasan.def(py::init<>());
}


}