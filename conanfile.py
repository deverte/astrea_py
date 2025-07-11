import tomllib

from conan import ConanFile
from conan.tools.cmake import CMake
from conan.tools.cmake import CMakeToolchain
from conan.tools.cmake import cmake_layout


with open("pyproject.toml", "rb") as f:
    pyproject = tomllib.load(f)
    version = pyproject["project"]["version"]


class AstreaPy(ConanFile):
    name = "astrea_py"
    version = version
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "src/*", "include/*"
    generators = "CMakeDeps"

    def requirements(self):
        self.requires("eigen/3.4.0", force=True)
        self.requires(f"astrea/{version}")
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