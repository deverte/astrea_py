#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/c_i/cooling_efficiency.h"
#include "astrea_py/element/c_i/effective_collision_strengths.h"
#include "astrea_py/element/c_i/energies.h"
#include "astrea_py/element/c_i/info.h"
#include "astrea_py/element/c_i/oscillator_strengths.h"
#include "astrea_py/element/c_i/photoionization_cross_sections.h"
#include "astrea_py/element/c_i/statistical_weights.h"
#include "astrea_py/element/c_i/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void c_i_(py::module_& m) {
  m.doc() =
    "C I data by Alexeeva+2015, Zatsarinny+2013, Reid1994, NIST\n"
    "(https://www.nist.gov/pml/atomic-spectra-database), TOPBASE\n"
    "(https://cdsweb.u-strasbg.fr/topbase/xsections.html), Gnat+2011\n"
    "(http://wise-obs.tau.ac.il/~orlyg/ion_by_ion/).\n"
  ;

  astrea_py::element::c_i::cooling_efficiency(m);
  astrea_py::element::c_i::effective_collision_strengths(m);
  astrea_py::element::c_i::energies(m);
  astrea_py::element::c_i::info(m);
  astrea_py::element::c_i::oscillator_strengths(m);
  astrea_py::element::c_i::photoionization_cross_sections(m);
  astrea_py::element::c_i::statistical_weights(m);
  astrea_py::element::c_i::structure(m);
}


}