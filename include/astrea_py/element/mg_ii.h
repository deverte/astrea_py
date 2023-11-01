#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/mg_ii/effective_collision_strengths.h"
#include "astrea_py/element/mg_ii/energies.h"
#include "astrea_py/element/mg_ii/info.h"
#include "astrea_py/element/mg_ii/oscillator_strengths.h"
#include "astrea_py/element/mg_ii/photoionization_cross_sections.h"
#include "astrea_py/element/mg_ii/statistical_weights.h"
#include "astrea_py/element/mg_ii/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void mg_ii_(py::module_& m) {
  m.doc() =
    "Mg II data by Alexeeva+2018, Sigutts+1995, NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database), TOPBASE\n"
    "(https://cdsweb.u-strasbg.fr/topbase/xsections.html).\n"
  ;

  astrea_py::element::mg_ii::effective_collision_strengths(m);
  astrea_py::element::mg_ii::energies(m);
  astrea_py::element::mg_ii::info(m);
  astrea_py::element::mg_ii::oscillator_strengths(m);
  astrea_py::element::mg_ii::photoionization_cross_sections(m);
  astrea_py::element::mg_ii::statistical_weights(m);
  astrea_py::element::mg_ii::structure(m);
}


}