import os
import platform
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

        profile = None
        if platform.system() == "Linux":
            profile = Path.cwd() / "profiles/linux_x86_64"
        elif platform.system() == "Darwin":
            profile = Path.cwd() / "profiles/mac_x86_64"
        elif platform.system() == "Windows":
            profile = Path.cwd() / "profiles/windows_x86_64"

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
            f"--profile:host={str(profile.resolve())}",
            f"--profile:build={str(profile.resolve())}",
        ])
        subprocess.run([
            "conan",
            "build",
            ".",
            f"--profile:host={str(profile.resolve())}",
            f"--profile:build={str(profile.resolve())}",
        ])

        shutil.move(
            Path.cwd() / 'build/Release/' / self.get_ext_filename(ext.name),
            ext_fullpath
        )


setup(
    ext_modules=[ConanCMakeExtension("astrea_py")],
    cmdclass={"build_ext": ConanCMakeBuild},
)