#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/n_i/cooling_efficiency.h"
#include "astrea_py/element/n_i/effective_collision_strengths.h"
#include "astrea_py/element/n_i/energies.h"
#include "astrea_py/element/n_i/info.h"
#include "astrea_py/element/n_i/oscillator_strengths.h"
#include "astrea_py/element/n_i/photoionization_cross_sections.h"
#include "astrea_py/element/n_i/principal_quantum_numbers.h"
#include "astrea_py/element/n_i/statistical_weights.h"
#include "astrea_py/element/n_i/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void n_i_(py::module_& m) {
  m.doc() =
    "N I data by Mashonkina+2024, Wang+2014, Kurucz+2014, Regemorter1962,\n"
    "NIST (https://www.nist.gov/pml/atomic-spectra-database),\n"
    "TOPBASE (https://cdsweb.u-strasbg.fr/topbase/xsections.html), Gnat+2011\n"
    "(http://wise-obs.tau.ac.il/~orlyg/ion_by_ion/).\n"
  ;

  astrea_py::element::n_i::cooling_efficiency(m);
  astrea_py::element::n_i::effective_collision_strengths(m);
  astrea_py::element::n_i::energies(m);
  astrea_py::element::n_i::info(m);
  astrea_py::element::n_i::oscillator_strengths(m);
  astrea_py::element::n_i::photoionization_cross_sections(m);
  astrea_py::element::n_i::principal_quantum_numbers(m);
  astrea_py::element::n_i::statistical_weights(m);
  astrea_py::element::n_i::structure(m);
}


}