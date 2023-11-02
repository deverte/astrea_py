#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/mg_i/cooling_efficiency.h"
#include "astrea_py/element/mg_i/effective_collision_strengths.h"
#include "astrea_py/element/mg_i/energies.h"
#include "astrea_py/element/mg_i/info.h"
#include "astrea_py/element/mg_i/oscillator_strengths.h"
#include "astrea_py/element/mg_i/photoionization_cross_sections.h"
#include "astrea_py/element/mg_i/statistical_weights.h"
#include "astrea_py/element/mg_i/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void mg_i_(py::module_& m) {
  m.doc() =
    "Mg I data by Alexeeva+2018, Merle+2015, Lemke+1987, Osorio2015, Green1957,\n"
    "NIST (https://www.nist.gov/pml/atomic-spectra-database),\n"
    "TOPBASE (https://cdsweb.u-strasbg.fr/topbase/xsections.html), Gnat+2011\n"
    "(http://wise-obs.tau.ac.il/~orlyg/ion_by_ion/).\n"
  ;

  astrea_py::element::mg_i::cooling_efficiency(m);
  astrea_py::element::mg_i::effective_collision_strengths(m);
  astrea_py::element::mg_i::energies(m);
  astrea_py::element::mg_i::info(m);
  astrea_py::element::mg_i::oscillator_strengths(m);
  astrea_py::element::mg_i::photoionization_cross_sections(m);
  astrea_py::element::mg_i::statistical_weights(m);
  astrea_py::element::mg_i::structure(m);
}


}