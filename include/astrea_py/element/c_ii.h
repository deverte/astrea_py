#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/c_ii/effective_collision_strengths.h"
#include "astrea_py/element/c_ii/energies.h"
#include "astrea_py/element/c_ii/info.h"
#include "astrea_py/element/c_ii/oscillator_strengths.h"
#include "astrea_py/element/c_ii/photoionization_cross_sections.h"
#include "astrea_py/element/c_ii/statistical_weights.h"
#include "astrea_py/element/c_ii/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void c_ii_(py::module_& m) {
  m.doc() =
    "C II data by Alexeeva+2015, Wilson+2005, NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database), TOPBASE\n"
    "(https://cdsweb.u-strasbg.fr/topbase/xsections.html).\n"
  ;

  astrea_py::element::c_ii::effective_collision_strengths(m);
  astrea_py::element::c_ii::energies(m);
  astrea_py::element::c_ii::info(m);
  astrea_py::element::c_ii::oscillator_strengths(m);
  astrea_py::element::c_ii::photoionization_cross_sections(m);
  astrea_py::element::c_ii::statistical_weights(m);
  astrea_py::element::c_ii::structure(m);
}


}