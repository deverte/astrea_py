project := "astrea"
version := "0.8.0"


update-version:
  #!/usr/bin/env python3
  import pathlib
  import re

  flake_in = pathlib.Path('.github/workflows/release.yaml')
  pattern = '--branch .* https://github.com/deverte/astrea # managed'
  repl = '--branch v{{version}} https://github.com/deverte/astrea # managed'
  flake_in.write_text(re.sub(pattern, repl, flake_in.read_text()))

  flake_in = pathlib.Path('flake.nix')
  pattern = '\/archive\/refs\/tags\/.*\.tar\.gz"; # managed'
  repl = '/archive/refs/tags/v{{version}}.tar.gz"; # managed'
  flake_in.write_text(re.sub(pattern, repl, flake_in.read_text()))

  flake = pathlib.Path('flake.nix')
  pattern = 'version = ".*"; # managed'
  repl = 'version = "{{version}}"; # managed'
  flake.write_text(re.sub(pattern, repl, flake.read_text()))

  pyproject = pathlib.Path('pyproject.toml')
  pattern = 'version = ".*"'
  repl = 'version = "{{version}}"'
  pyproject.write_text(re.sub(pattern, repl, pyproject.read_text()))

  readme = pathlib.Path('README.md')
  pattern = '\/archive\/refs\/tags\/.*\.tar\.gz'
  repl = '/archive/refs/tags/v{{version}}.tar.gz'
  readme.write_text(re.sub(pattern, repl, readme.read_text()))


configure:
  mkdir -p build
  cd build; \
    cmake .. -G Ninja; \
    cd ..


build:
  cd build; \
    cmake --build .; \
    cd ..
  python3 -m build --no-isolation --wheel


install:
  pip3 install dist/{{project}}-*.whl


uninstall:
  pip3 uninstall {{project}} -y


test:
  python3 -m pytest


dist: \
  (dist_version "3.10") \
  (dist_version "3.11") \
  (dist_version "3.12") \
  (dist_version "3.13")


dist_version python_version:
  nix build .#python{{replace(python_version, ".", "")}}
  mkdir -p dist
  wheel pack result/lib/python{{python_version}}/site-packages --dest-dir dist


publish:
  python3 -m twine upload ./dist/*


clear:
  rm -rf .pytest_cache
  rm -rf src/*.egg-info
  rm -rf build
  rm -rf dist
  rm -rf result
  rm -rf wheelhouse
  rm -f CMakeUserPresets.json
  rm -f compile_commands.json


purge: clear
  rm -rf .cache
  rm -rf .venv
