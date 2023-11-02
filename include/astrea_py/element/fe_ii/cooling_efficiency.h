#pragma once


#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

#include <astrea/astrea.h>


namespace py = pybind11;


namespace astrea_py::element::fe_ii {


inline void cooling_efficiency(py::module_& m) {
  m.def(
    "Lambda_vs_T",
    &astrea::element::fe_ii::Lambda_vs_T,
    "Fe II cooling efficiency by Gnat+2011"
    "(http://wise-obs.tau.ac.il/~orlyg/ion_by_ion/).\n"
    "\n"
    "- Axis 0: Bivariate data (row).\n"
    "  - 0: Temperature in K.\n"
    "  - 1: Cooling efficiency in erg s-1 cm3.\n"
    "- Axis 1: Bivariate pair index (column).\n"
  );
}


}