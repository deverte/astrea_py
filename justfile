project := "astrea"
ver := "0.7.6"

default: configure build

update-version:
  #!/usr/bin/env python3
  import pathlib
  import re

  flake_in = pathlib.Path('flake.nix')
  pattern = '\/archive\/.*\.tar\.gz"; # managed'
  repl = '/archive/v{{ver}}.tar.gz"; # managed'
  flake_in.write_text(re.sub(pattern, repl, flake_in.read_text()))

  flake = pathlib.Path('flake.nix')
  pattern = 'version = ".*"; # managed'
  repl = 'version = "{{ver}}"; # managed'
  flake.write_text(re.sub(pattern, repl, flake.read_text()))

  pyproject = pathlib.Path('pyproject.toml')
  pattern = 'version = ".*"'
  repl = 'version = "{{ver}}"'
  pyproject.write_text(re.sub(pattern, repl, pyproject.read_text()))

  readme = pathlib.Path('README.md')
  pattern = '\/archive\/.*\.tar\.gz'
  repl = '/archive/v{{ver}}.tar.gz'
  readme.write_text(re.sub(pattern, repl, readme.read_text()))

build:
  cd build; \
    cmake --build .; \
    cd ..
  python3 -m build --no-isolation --wheel

configure:
  mkdir build
  cd build; \
    cmake .. -G Ninja; \
    cd ..

test:
  python3 -m pytest

install:
  pip install dist/{{project}}-*.whl

uninstall:
  pip uninstall {{project}} -y

publish:
  python3 -m twine upload --repository astro ./dist/*

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

env:
  python3 -m venv .venv
  .venv/bin/pip3 install -r requirements.txt