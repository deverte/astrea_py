#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/h_i/cooling_efficiency.h"
#include "astrea_py/element/h_i/effective_collision_strengths.h"
#include "astrea_py/element/h_i/energies.h"
#include "astrea_py/element/h_i/info.h"
#include "astrea_py/element/h_i/oscillator_strengths_doppler.h"
#include "astrea_py/element/h_i/oscillator_strengths_stark.h"
#include "astrea_py/element/h_i/principal_quantum_numbers.h"
#include "astrea_py/element/h_i/statistical_weights.h"
#include "astrea_py/element/h_i/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void h_i_(py::module_& m) {
  m.doc() =
    "H I data by Mashonkina+2008, Przybilla+2004, NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database).\n"
  ;

  astrea_py::element::h_i::cooling_efficiency(m);
  astrea_py::element::h_i::effective_collision_strengths(m);
  astrea_py::element::h_i::energies(m);
  astrea_py::element::h_i::info(m);
  astrea_py::element::h_i::oscillator_strengths_doppler(m);
  astrea_py::element::h_i::oscillator_strengths_stark(m);
  astrea_py::element::h_i::principal_quantum_numbers(m);
  astrea_py::element::h_i::statistical_weights(m);
  astrea_py::element::h_i::structure(m);
}


}