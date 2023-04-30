#pragma once


#include <memory>
#include <vector>
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


inline void ILevel(py::module_& m) {
  py::class_<astrea::ILevel> ilevel(m, "ILevel");

  ilevel.def_readonly(
    "term",
    &astrea::ILevel::term
  );

  ilevel.def_readonly(
    "energy",
    &astrea::ILevel::energy
  );

  ilevel.def_readonly(
    "ionization_energy",
    &astrea::ILevel::ionization_energy
  );
}


class PyElement : public astrea::Element {
 public:
  using astrea::Element::Element;

  const astrea::IElement& resource() override {
    PYBIND11_OVERRIDE_PURE(
      const astrea::IElement&,
      astrea::Element,
      resource
    );
  }
};


inline void Element(py::module_& m) {
  py::class_<astrea::Element, PyElement, std::shared_ptr<astrea::Element>>
  element(m, "Element");

  element.def(py::init<>());

  element.def_property(
    "all_keys",
    &astrea::Element::all_keys,
    nullptr
  );

  element.def_property_readonly(
    "all_levels",
    &astrea::Element::all_levels
  );

  element.def_property_readonly(
    "atomic_number",
    &astrea::Element::atomic_number
  );

  element.def_property_readonly(
    "ionization_stage",
    &astrea::Element::ionization_stage
  );

  element.def_property(
    "keys",
    py::overload_cast<>(&astrea::Element::keys),
    py::overload_cast<std::vector<std::string>>(&astrea::Element::keys)
  );

  element.def_property(
    "levels",
    &astrea::Element::levels,
    nullptr
  );

  element.def_property_readonly(
    "mass",
    &astrea::Element::mass
  );
}


}