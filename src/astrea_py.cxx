#include <pybind11/pybind11.h>

#include <astrea_py/astrea_py.h>


PYBIND11_MODULE(astrea, m) {
  m.doc() =
    "Statistical equilibrium (LTE and NLTE) calculation header-only library."
  ;


  // Element
  auto element = m.def_submodule("element");

  auto c_i = element.def_submodule("c_i");
  astrea_py::element::c_i_(c_i);

  auto c_ii = element.def_submodule("c_ii");
  astrea_py::element::c_ii_(c_ii);

  auto c_iii = element.def_submodule("c_iii");
  astrea_py::element::c_iii_(c_iii);

  auto fe_i = element.def_submodule("fe_i");
  astrea_py::element::fe_i_(fe_i);

  auto fe_ii = element.def_submodule("fe_ii");
  astrea_py::element::fe_ii_(fe_ii);

  auto fe_iii = element.def_submodule("fe_iii");
  astrea_py::element::fe_iii_(fe_iii);

  auto h_i = element.def_submodule("h_i");
  astrea_py::element::h_i_(h_i);

  auto h_ii = element.def_submodule("h_ii");
  astrea_py::element::h_ii_(h_ii);

  auto mg_i = element.def_submodule("mg_i");
  astrea_py::element::mg_i_(mg_i);

  auto mg_ii = element.def_submodule("mg_ii");
  astrea_py::element::mg_ii_(mg_ii);

  auto mg_iii = element.def_submodule("mg_iii");
  astrea_py::element::mg_iii_(mg_iii);

  auto n_i = element.def_submodule("n_i");
  astrea_py::element::n_i_(n_i);

  auto n_ii = element.def_submodule("n_ii");
  astrea_py::element::n_ii_(n_ii);

  auto o_i = element.def_submodule("o_i");
  astrea_py::element::o_i_(o_i);

  auto o_ii = element.def_submodule("o_ii");
  astrea_py::element::o_ii_(o_ii);


  // Math
  auto math = m.def_submodule("math");

  auto cauchy_lorentz_distribution =
    math.def_submodule("cauchy_lorentz_distribution");
  astrea_py::math::cauchy_lorentz_distribution(cauchy_lorentz_distribution);

  auto interp1d_linear = math.def_submodule("interp1d_linear");
  astrea_py::math::interp1d_linear(interp1d_linear);

  auto interp1d_log10x = math.def_submodule("interp1d_log10x");
  astrea_py::math::interp1d_log10x(interp1d_log10x);

  auto interp1d_log10xy = math.def_submodule("interp1d_log10xy");
  astrea_py::math::interp1d_log10xy(interp1d_log10xy);

  auto interp1d_log10y = math.def_submodule("interp1d_log10y");
  astrea_py::math::interp1d_log10y(interp1d_log10y);

  auto interp1d_nearest = math.def_submodule("interp1d_nearest");
  astrea_py::math::interp1d_nearest(interp1d_nearest);

  auto maxwell_boltzmann_distribution =
    math.def_submodule("maxwell_boltzmann_distribution");
  astrea_py::math::maxwell_boltzmann_distribution(maxwell_boltzmann_distribution);

  auto normal_distribution = math.def_submodule("normal_distribution");
  astrea_py::math::normal_distribution(normal_distribution);

  auto trapezoid = math.def_submodule("trapezoid");
  astrea_py::math::trapezoid(trapezoid);

  auto voigt_function_tasitsiomi =
    math.def_submodule("voigt_function_tasitsiomi");
  astrea_py::math::voigt_function_tasitsiomi(voigt_function_tasitsiomi);

  auto voigt_function = math.def_submodule("voigt_function");
  astrea_py::math::voigt_function(voigt_function);

  auto voigt_profile = math.def_submodule("voigt_profile");
  astrea_py::math::voigt_profile(voigt_profile);


  // Optics
  auto optics = m.def_submodule("optics");

  auto absorption_coefficient = optics.def_submodule("absorption_coefficient");
  astrea_py::optics::absorption_coefficient(absorption_coefficient);

  auto doppler_line_width = optics.def_submodule("doppler_line_width");
  astrea_py::optics::doppler_line_width(doppler_line_width);

  auto natural_line_width = optics.def_submodule("natural_line_width");
  astrea_py::optics::natural_line_width(natural_line_width);

  auto optical_depth = optics.def_submodule("optical_depth");
  astrea_py::optics::optical_depth(optical_depth);


  // Population
  auto population = m.def_submodule("population");

  auto balance_equation = population.def_submodule("balance_equation");
  astrea_py::population::balance_equation(balance_equation);

  auto boltzmann_distribution =
    population.def_submodule("boltzmann_distribution");
  astrea_py::population::boltzmann_distribution(boltzmann_distribution);

  auto saha_ionization_equation =
    population.def_submodule("saha_ionization_equation");
  astrea_py::population::saha_ionization_equation(saha_ionization_equation);


  // Spectrum
  auto spectrum = m.def_submodule("spectrum");

  auto gj_436_fossati_2 = spectrum.def_submodule("gj_436_fossati_2");
  astrea_py::spectrum::gj_436_fossati_2(gj_436_fossati_2);

  auto gj_436_fossati = spectrum.def_submodule("gj_436_fossati");
  astrea_py::spectrum::gj_436_fossati(gj_436_fossati);

  auto gj_3470_bourrier = spectrum.def_submodule("gj_3470_bourrier");
  astrea_py::spectrum::gj_3470_bourrier(gj_3470_bourrier);

  auto hat_p_11_ben_jaffel = spectrum.def_submodule("hat_p_11_ben_jaffel");
  astrea_py::spectrum::hat_p_11_ben_jaffel(hat_p_11_ben_jaffel);

  auto hd_73583_zhang = spectrum.def_submodule("hd_73583_zhang");
  astrea_py::spectrum::hd_73583_zhang(hd_73583_zhang);

  auto hd_85512_muscles = spectrum.def_submodule("hd_85512_muscles");
  astrea_py::spectrum::hd_85512_muscles(hd_85512_muscles);

  auto hd_189733_fossati = spectrum.def_submodule("hd_189733_fossati");
  astrea_py::spectrum::hd_189733_fossati(hd_189733_fossati);

  auto hd_209458_fossati = spectrum.def_submodule("hd_209458_fossati");
  astrea_py::spectrum::hd_209458_fossati(hd_209458_fossati);

  auto hd_209458_salz = spectrum.def_submodule("hd_209458_salz");
  astrea_py::spectrum::hd_209458_salz(hd_209458_salz);

  auto kelt_9_fossati = spectrum.def_submodule("kelt_9_fossati");
  astrea_py::spectrum::kelt_9_fossati(kelt_9_fossati);

  auto sun_linsky = spectrum.def_submodule("sun_linsky");
  astrea_py::spectrum::sun_linsky(sun_linsky);

  auto sun_tobiska = spectrum.def_submodule("sun_tobiska");
  astrea_py::spectrum::sun_tobiska(sun_tobiska);

  auto wasp_80_salz_fossati = spectrum.def_submodule("wasp_80_salz_fossati");
  astrea_py::spectrum::wasp_80_salz_fossati(wasp_80_salz_fossati);


  // Thermodynamics
  auto thermodynamics = m.def_submodule("thermodynamics");

  auto cooling_function = thermodynamics.def_submodule("cooling_function");
  astrea_py::thermodynamics::cooling_function(cooling_function);

  auto cooling_rate_approximation =
    thermodynamics.def_submodule("cooling_rate_approximation");
  astrea_py::thermodynamics::cooling_rate_approximation(
    cooling_rate_approximation
  );

  auto cooling_rate = thermodynamics.def_submodule("cooling_rate");
  astrea_py::thermodynamics::cooling_rate(cooling_rate);

  auto heating_rate = thermodynamics.def_submodule("heating_rate");
  astrea_py::thermodynamics::heating_rate(heating_rate);


  // Transition
  auto transition = m.def_submodule("transition");

  auto collisional_deexcitation =
    transition.def_submodule("collisional_deexcitation");
  astrea_py::transition::collisional_deexcitation(collisional_deexcitation);

  auto collisional_excitation =
    transition.def_submodule("collisional_excitation");
  astrea_py::transition::collisional_excitation(collisional_excitation);

  auto collisional_ionization =
    transition.def_submodule("collisional_ionization");
  astrea_py::transition::collisional_ionization(collisional_ionization);

  auto photoexcitation_lorentz =
    transition.def_submodule("photoexcitation_lorentz");
  astrea_py::transition::photoexcitation_lorentz(photoexcitation_lorentz);

  auto photoionization = transition.def_submodule("photoionization");
  astrea_py::transition::photoionization(photoionization);

  auto radiative_recombination =
    transition.def_submodule("radiative_recombination");
  astrea_py::transition::radiative_recombination(radiative_recombination);

  auto spontaneous_emission = transition.def_submodule("spontaneous_emission");
  astrea_py::transition::spontaneous_emission(spontaneous_emission);

  auto three_body_recombination =
    transition.def_submodule("three_body_recombination");
  astrea_py::transition::three_body_recombination(three_body_recombination);
}