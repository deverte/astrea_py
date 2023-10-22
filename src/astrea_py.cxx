#include <pybind11/pybind11.h>

#include <astrea_py/astrea_py.h>


PYBIND11_MODULE(astrea, m) {
  m.doc() =
    "Statistical equilibrium (LTE and NLTE) calculation header-only library."
  ;


  // Element
  auto element = m.def_submodule("element");

  auto o_i_mashonkina = element.def_submodule("o_i_mashonkina");
  astrea_py::element::o_i_mashonkina_(o_i_mashonkina);

  auto o_ii_mashonkina = element.def_submodule("o_ii_mashonkina");
  astrea_py::element::o_ii_mashonkina_(o_ii_mashonkina);


  // Math
  auto math = m.def_submodule("math");

  astrea_py::math::interp1d_linear(math);
  astrea_py::math::interp1d_nearest(math);
  astrea_py::math::trapezoid(math);


  // Population
  auto population = m.def_submodule("population");

  auto balance_equation = population.def_submodule("balance_equation");
  astrea_py::population::balance_equation(balance_equation);

  auto boltzmann_distribution =
    population.def_submodule("boltzmann_distribution");
  astrea_py::population::boltzmann_distribution(boltzmann_distribution);


  // Spectrum
  auto spectrum = m.def_submodule("spectrum");

  auto kelt_9_fossati = spectrum.def_submodule("kelt_9_fossati");
  astrea_py::spectrum::kelt_9_fossati(kelt_9_fossati);


  // Transition
  auto transition = m.def_submodule("transition");

  auto cd = transition.def_submodule("cd");
  astrea_py::transition::cd(cd);

  auto ce_regemorter = transition.def_submodule("ce_regemorter");
  astrea_py::transition::ce_regemorter(ce_regemorter);

  auto ce = transition.def_submodule("ce");
  astrea_py::transition::ce(ce);

  auto rd = transition.def_submodule("rd");
  astrea_py::transition::rd(rd);

  auto re_lorentz = transition.def_submodule("re_lorentz");
  astrea_py::transition::re_lorentz(re_lorentz);

  auto ri = transition.def_submodule("ri");
  astrea_py::transition::ri(ri);
}