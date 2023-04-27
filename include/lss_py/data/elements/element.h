#pragma once


#include <memory>
#include <vector>
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <lss/lss.h>


namespace py = pybind11;


namespace lss_py {


inline void ILevel(py::module_& m) {
  py::class_<lss::ILevel> ilevel(m, "ILevel");

  ilevel.def_readonly(
    "term",
    &lss::ILevel::term
  );

  // ilevel.def_readonly(
  //   "limit_term",
  //   &lss::ILevel::limit_term
  // );

  // ilevel.def_readonly(
  //   "ground_state_term",
  //   &lss::ILevel::ground_state_term
  // );

  // ilevel.def_readonly(
  //   "principal_quantum_number",
  //   &lss::ILevel::principal_quantum_number
  // );

  // ilevel.def_readonly(
  //   "statistical_weight",
  //   &lss::ILevel::statistical_weight
  // );

  ilevel.def_readonly(
    "energy",
    &lss::ILevel::energy
  );

  ilevel.def_readonly(
    "ionization_energy",
    &lss::ILevel::ionization_energy
  );

  // ilevel.def_readonly(
  //   "ionization_stage",
  //   &lss::ILevel::ionization_stage
  // );
}


class PyElement : public lss::Element {
 public:
  using lss::Element::Element;

  const lss::IElement& resource() override {
    PYBIND11_OVERRIDE_PURE(
      const lss::IElement&,
      lss::Element,
      resource
    );
  }
};


inline void Element(py::module_& m) {
  py::class_<lss::Element, PyElement, std::shared_ptr<lss::Element>>
  element(m, "Element");

  element.def(py::init<>());

  element.def_property(
    "all_keys",
    &lss::Element::all_keys,
    nullptr
  );

  element.def_property_readonly(
    "all_levels",
    &lss::Element::all_levels
  );

  element.def_property_readonly(
    "atomic_number",
    &lss::Element::atomic_number
  );

  element.def_property_readonly(
    "ionization_stage",
    &lss::Element::ionization_stage
  );

  element.def_property(
    "keys",
    py::overload_cast<>(&lss::Element::keys),
    py::overload_cast<std::vector<std::string>>(&lss::Element::keys)
  );

  element.def_property(
    "levels",
    &lss::Element::levels,
    nullptr
  );

  element.def_property_readonly(
    "mass",
    &lss::Element::mass
  );
}


}