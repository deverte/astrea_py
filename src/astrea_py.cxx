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

  astrea_py::cbb_mashonkina_o1_rates(m);
  astrea_py::cbb_regemorter_rates(m);
  astrea_py::ci_mashonkina_o1_seaton_rates(m);
  astrea_py::ci_mashonkina_o1_rates(m);
  astrea_py::pi_mashonkina_o1_rates(m);
  astrea_py::rbb_mashonkina_doppler_o1_rates(m);
  astrea_py::rbb_mashonkina_voigt_o1_rates(m);
  astrea_py::rbb_tasitsiomi_rates(m);
  astrea_py::rr_mashonkina_o1_rate_coefficients(m);
  astrea_py::se_nist_o1_rates(m);
  astrea_py::tbr_mashonkina_o1_seaton_rate_coefficients(m);
  astrea_py::tbr_mashonkina_o1_rate_coefficients(m);
}