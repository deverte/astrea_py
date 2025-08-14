import os
import shutil
from pathlib import Path

from setuptools import Extension
from setuptools import setup
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

        build_paths = [
            *(Path.cwd() / 'build/').glob("**/*.so"),
            *(Path.cwd() / 'build/').glob("**/*.pyd"),
        ]
        for build_path in build_paths:
            shutil.move(str(build_path.resolve()), ext_fullpath)


setup(
    ext_modules=[CMakeExtension("astrea")],
    cmdclass={"build_ext": CMakeBuild},
)
