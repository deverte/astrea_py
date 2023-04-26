#pragma once


#include <memory>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <lss/lss.h>


namespace py = pybind11;


namespace lss_py {


class PySpectrum : public lss::Spectrum {
 public:
  using lss::Spectrum::Spectrum;

  double distance() override {
    PYBIND11_OVERRIDE_PURE(
      double,
      lss::Spectrum,
      distance
    );
  }

  void distance(double value) override {
    PYBIND11_OVERRIDE_PURE(
      void,
      lss::Spectrum,
      distance,
      value
    );
  }

  double max_wavelength() override {
    PYBIND11_OVERRIDE_PURE(
      double,
      lss::Spectrum,
      max_wavelength
    );
  }

  double min_wavelength() override {
    PYBIND11_OVERRIDE_PURE(
      double,
      lss::Spectrum,
      min_wavelength
    );
  }

  double spectral_irradiance(double wavelength) override {
    PYBIND11_OVERRIDE_PURE(
      double,
      lss::Spectrum,
      spectral_irradiance,
      wavelength
    );
  }
};


inline void Spectrum(py::module_& m) {
  py::class_<lss::Spectrum, PySpectrum, std::shared_ptr<lss::Spectrum>>
  spectrum(m, "Spectrum");

  spectrum.def(py::init<>());

  spectrum.def_property(
    "distance",
    py::overload_cast<>(&lss::Spectrum::distance),
    py::overload_cast<double>(&lss::Spectrum::distance)
  );

  spectrum.def_property_readonly(
    "max_wavelength",
    &lss::Spectrum::max_wavelength
  );

  spectrum.def_property_readonly(
    "min_wavelength",
    &lss::Spectrum::min_wavelength
  );

  spectrum.def("spectral_irradiance", &lss::Spectrum::spectral_irradiance);
}


}