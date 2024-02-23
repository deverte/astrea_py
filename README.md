# astrea_py

![logo](assets/logo.svg)

Python bindings for [astrea](https://gitea.zarux.ru/astro/astrea), library for
statistical equilibrium calculations in cosmic plasma.

## Installation

Method 1 - precompiled binaries (Linux):

```sh
# Using pip
pip3 install --index-url https://gitea.zarux.ru/api/packages/astro/pypi/simple astrea

# Using poetry
# Add source
poetry source add --priority=explicit astro https://gitea.zarux.ru/api/packages/astro/pypi/simple
# Install
poetry add --source=astro astrea
```

Method 2 - Nix package (`flake.nix`) (since v0.7.3):

```
{
  inputs = {
    astreapypkg.url = "https://gitea.zarux.ru/astro/astrea_py/archive/<hash>.tar.gz";
  };

  outputs = inputs@{ self, astreapypkg, ... }:
  let
    system = "x86_64-linux";
    astreapy = astreapypkg.defaultPackage.${system};
  in {
    devShell.${system} = pkgs.mkShell {
      buildInputs = [
        astreapy
      ];
    };
  };
}
```

Method 3 - compile from sources using Conan:

```sh
git clone https://gitea.zarux.ru/astro/astrea_py
cd astrea_py; \
  conan profile detect; \
  conan config install ./remotes.json; \
  conan install . --build=missing; \
  conan build .; \
  python3 -m build --no-isolation --wheel
```

Method 4 - compile from sources:

Manually install dependencies (must be visible in `CMAKE_PREFIX_PATH`):

- Astrea
- Eigen
- pybind11

Continue with the following commands:

```sh
git clone https://gitea.zarux.ru/astro/astrea_py
cd astrea_py; \
  just configure; \
  just build;
```

## Examples

See [examples](./tests/examples).

## License

- License: [GPL-3](./LICENSE)
- Author: [Artem Shepelin](mailto:4.shepelin@gmail.com)