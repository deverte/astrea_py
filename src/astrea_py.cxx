#include <pybind11/pybind11.h>

#include <astrea_py/astrea_py.h>


PYBIND11_MODULE(astrea, m) {
  astrea_py::lte_boltzmann_population(m);
  astrea_py::lte_boltzmann_saha_population(m);
  astrea_py::nlte_population_full(m);
  astrea_py::nlte_population_per_elements(m);

  astrea_py::ILevel(m);
  astrea_py::Element(m);
  astrea_py::H1(m);
  astrea_py::H2(m);
  astrea_py::He1(m);
  astrea_py::He2(m);
  astrea_py::O1Mashonkina(m);
  astrea_py::O2Mashonkina(m);

  astrea_py::Spectrum(m);
  astrea_py::BlackBodyPlanck(m);
  astrea_py::Kelt9Fossati(m);
  astrea_py::SunGueymard(m);

  astrea_py::cd_regemorter_rates(m);
  astrea_py::ce_regemorter_rates(m);
  astrea_py::rd_nist_o1_rates(m);
  astrea_py::re_lorentz_rates(m);
}