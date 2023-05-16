#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void BlackBodyPlanck(py::module_& m) {
  py::class_<
    astrea::BlackBodyPlanck,
    astrea::Spectrum,
    std::shared_ptr<astrea::BlackBodyPlanck>
  >
  black_body_planck(m, "BlackBodyPlanck");

  black_body_planck.def(py::init<>());

  black_body_planck.def_property(
    "temperature",
    py::overload_cast<>(&astrea::BlackBodyPlanck::temperature, py::const_),
    py::overload_cast<double>(&astrea::BlackBodyPlanck::temperature)
  );

  black_body_planck.def_property(
    "total_area",
    py::overload_cast<>(&astrea::BlackBodyPlanck::total_area, py::const_),
    py::overload_cast<double>(&astrea::BlackBodyPlanck::total_area)
  );
}


}