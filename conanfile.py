import configparser

from conan import ConanFile
from conan.tools.cmake import CMake
from conan.tools.cmake import CMakeToolchain
from conan.tools.cmake import cmake_layout


config = configparser.ConfigParser()
config.read('setup.cfg')

version = config["metadata"]["version"]


class AstreaPy(ConanFile):
    name = "astrea_py"
    version = version
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "src/*", "include/*"
    generators = "CMakeDeps"

    def requirements(self):
        self.requires("boost-math/1.82.0", force=True)
        self.requires("boost-units/1.82.0", force=True)
        self.requires("eigen/3.4.0", force=True)
        self.requires(f"astrea/{version}")
        self.requires("fm/0.1.3", force=True)
        self.requires("ni/0.1.1", force=True)
        self.requires("pybind11/2.10.1")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self, generator="Ninja")
        tc.generate()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()