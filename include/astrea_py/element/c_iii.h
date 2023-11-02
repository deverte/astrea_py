#pragma once


#include <pybind11/pybind11.h>

#include <astrea/astrea.h>

#include "astrea_py/element/c_iii/cooling_efficiency.h"
#include "astrea_py/element/c_iii/energies.h"
#include "astrea_py/element/c_iii/info.h"
#include "astrea_py/element/c_iii/statistical_weights.h"
#include "astrea_py/element/c_iii/structure.h"


namespace py = pybind11;


namespace astrea_py::element {


inline void c_iii_(py::module_& m) {
  m.doc() =
    "C III data by NIST (https://www.nist.gov/pml/atomic-spectra-database),\n"
    "Gnat+2011 (http://wise-obs.tau.ac.il/~orlyg/ion_by_ion/).\n"
  ;

  astrea_py::element::c_iii::cooling_efficiency(m);
  astrea_py::element::c_iii::energies(m);
  astrea_py::element::c_iii::info(m);
  astrea_py::element::c_iii::statistical_weights(m);
  astrea_py::element::c_iii::structure(m);
}


}