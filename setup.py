import os
import shutil
import subprocess
from pathlib import Path

from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext


class CMakeExtension(Extension):
    def __init__(self, name: str, sourcedir: str = "") -> None:
        super().__init__(name, sources=[])
        self.sourcedir = os.fspath(Path(sourcedir).resolve())


class CMakeBuild(build_ext):
    def build_extension(self, ext: CMakeExtension) -> None:
        ext_fullpath = Path.cwd() / self.get_ext_fullpath(ext.name)
        extdir = ext_fullpath.parent
        if not extdir.exists():
            extdir.mkdir(parents=True)

        subprocess.run(["conan", "install", ".", "--build=missing"])
        subprocess.run(["conan", "build", "."])

        shutil.move(
            Path.cwd() / 'build/Release/' / self.get_ext_filename(ext.name),
            ext_fullpath
        )


setup(
    ext_modules=[CMakeExtension("astrea_py")],
    cmdclass={"build_ext": CMakeBuild},
)