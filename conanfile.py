import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout


version = os.environ['version']
project = os.environ['project']


class LssPy(ConanFile):
    name = project
    version = version
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    exports_sources = "CMakeLists.txt", "src/*", "include/*"

    def requirements(self):
        self.requires("boost/1.81.0", override=True)
        self.requires("eigen/3.4.0", override=True)
        self.requires("libinterpolate/2.6.2")
        self.requires(f"lss/{version}")
        self.requires("pybind11/2.10.1")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
