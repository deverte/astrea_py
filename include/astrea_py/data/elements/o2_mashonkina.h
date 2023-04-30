#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void O2Mashonkina(py::module_& m) {
  py::class_<
    astrea::O2Mashonkina,
    astrea::Element,
    std::shared_ptr<astrea::O2Mashonkina>
  >
  o2_inasan(m, "O2Mashonkina");

  o2_inasan.def(py::init<>());
}


}