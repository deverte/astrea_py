cmake_minimum_required(VERSION 3.4...3.18)
project(astrea_py)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(astrea)
find_package(Eigen3)
find_package(pybind11)

if("${Eigen3_INCLUDE_DIRS}" STREQUAL "")
    set(Eigen3_INCLUDE_DIRS $ENV{Eigen3_INCLUDE_DIRS})
endif()

include_directories(${astrea_INCLUDE_DIRS})
include_directories(${Eigen3_INCLUDE_DIRS})

include_directories(include)

pybind11_add_module(astrea src/astrea_py.cxx)
