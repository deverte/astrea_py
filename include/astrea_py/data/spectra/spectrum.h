#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py {


class PySpectrum : public astrea::Spectrum {
 public:
  using astrea::Spectrum::Spectrum;

  double distance() override {
    PYBIND11_OVERRIDE_PURE(
      double,
      astrea::Spectrum,
      distance
    );
  }

  void distance(double value) override {
    PYBIND11_OVERRIDE_PURE(
      void,
      astrea::Spectrum,
      distance,
      value
    );
  }

  double max_wavelength() override {
    PYBIND11_OVERRIDE_PURE(
      double,
      astrea::Spectrum,
      max_wavelength
    );
  }

  double min_wavelength() override {
    PYBIND11_OVERRIDE_PURE(
      double,
      astrea::Spectrum,
      min_wavelength
    );
  }

  double spectral_irradiance(double wavelength) override {
    PYBIND11_OVERRIDE_PURE(
      double,
      astrea::Spectrum,
      spectral_irradiance,
      wavelength
    );
  }
};


inline void Spectrum(py::module_& m) {
  py::class_<astrea::Spectrum, PySpectrum, std::shared_ptr<astrea::Spectrum>>
  spectrum(m, "Spectrum");

  spectrum.def(py::init<>());

  spectrum.def_property(
    "distance",
    py::overload_cast<>(&astrea::Spectrum::distance),
    py::overload_cast<double>(&astrea::Spectrum::distance)
  );

  spectrum.def_property_readonly(
    "max_wavelength",
    &astrea::Spectrum::max_wavelength
  );

  spectrum.def_property_readonly(
    "min_wavelength",
    &astrea::Spectrum::min_wavelength
  );

  spectrum.def("spectral_irradiance", &astrea::Spectrum::spectral_irradiance);
}


}