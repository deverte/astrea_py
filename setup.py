import os
import shutil
import subprocess
from pathlib import Path

from setuptools import Extension
from setuptools import setup
from setuptools.command.build_ext import build_ext


class ConanCMakeExtension(Extension):
    def __init__(self, name: str, sourcedir: str = "") -> None:
        super().__init__(name, sources=[])
        self.sourcedir = os.fspath(Path(sourcedir).resolve())


class ConanCMakeBuild(build_ext):
    def build_extension(self, ext: ConanCMakeExtension) -> None:
        ext_fullpath = Path.cwd() / self.get_ext_fullpath(ext.name)
        extdir = ext_fullpath.parent
        if not extdir.exists():
            extdir.mkdir(parents=True)

        subprocess.run([
            "conan",
            "profile",
            "detect",
        ])
        subprocess.run([
            "conan",
            "config",
            "install",
            "./remotes.json",
        ])
        subprocess.run([
            "conan",
            "install",
            ".",
            "--build=missing",
        ])
        subprocess.run([
            "conan",
            "build",
            ".",
        ])

        build_paths = [
            *(Path.cwd() / 'build/Release/').glob("*.so"),
            *(Path.cwd() / 'build/Release/').glob("*.pyd"),
        ]
        for build_path in build_paths:
            shutil.move(str(build_path.resolve()), ext_fullpath)


setup(
    ext_modules=[ConanCMakeExtension("astrea")],
    cmdclass={"build_ext": ConanCMakeBuild},
)