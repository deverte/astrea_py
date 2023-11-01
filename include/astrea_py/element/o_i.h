#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/o_i/collision_rate_coefficients.h"
#include "astrea_py/element/o_i/energies.h"
#include "astrea_py/element/o_i/info.h"
#include "astrea_py/element/o_i/oscillator_strengths.h"
#include "astrea_py/element/o_i/photoionization_cross_sections.h"
#include "astrea_py/element/o_i/principal_quantum_numbers.h"
#include "astrea_py/element/o_i/statistical_weights.h"
#include "astrea_py/element/o_i/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void o_i_(py::module_& m) {
  m.doc() =
    "O I data by Barklem2007, Przybilla2000, Sitnova2012, Sitnova+2013,\n"
    "Sitnova2017, NIST (https://www.nist.gov/pml/atomic-spectra-database), TOPBASE\n"
    "(https://cdsweb.u-strasbg.fr/topbase/xsections.html), Mashonkina\n"
    "(private communication).\n"
  ;

  astrea_py::element::o_i::collision_rate_coefficients(m);
  astrea_py::element::o_i::energies(m);
  astrea_py::element::o_i::info(m);
  astrea_py::element::o_i::oscillator_strengths(m);
  astrea_py::element::o_i::photoionization_cross_sections(m);
  astrea_py::element::o_i::principal_quantum_numbers(m);
  astrea_py::element::o_i::statistical_weights(m);
  astrea_py::element::o_i::structure(m);
}


}