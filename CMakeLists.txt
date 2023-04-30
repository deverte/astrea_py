cmake_minimum_required(VERSION 3.4...3.18)
project(astrea_py)

find_package(Boost COMPONENTS math REQUIRED)
find_package(Eigen3)
find_package(fm)
find_package(libInterpolate)
find_package(astrea)
find_package(pybind11)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Eigen3_INCLUDE_DIRS})
include_directories(${fm_INCLUDE_DIRS})
include_directories(${libInterpolate_INCLUDE_DIRS})
include_directories(${astrea_INCLUDE_DIRS})

include_directories(include)

pybind11_add_module(astrea_py src/astrea_py.cxx)