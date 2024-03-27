# astrea_py

![logo](assets/logo.svg)

Python bindings for [astrea](http://gitea.nul/astro/astrea), library for
statistical equilibrium calculations in cosmic plasma.

## Installation

Method 1 - precompiled binaries (Linux):

```sh
# Using pip
pip3 install --index-url http://gitea.nul/api/packages/astro/pypi/simple astrea

# Using poetry
# Add source
poetry source add --priority=explicit \
  astro http://gitea.nul/api/packages/astro/pypi/simple
# Install
poetry add --source=astro astrea
```

Method 2 - Nix package (`flake.nix`) (since v0.7.3):

```
{
  inputs = {
    astreaPyPkg.url = "http://gitea.nul/astro/astrea_py/archive/v0.7.5.tar.gz";
  };

  outputs = inputs@{ self, astreaPyPkg, ... }:
  let
    system = "x86_64-linux";
    astreaPy = astreaPyPkg.packages.${system}.default;
  in {
    devShells.${system}.default = pkgs.mkShell {
      buildInputs = [
        astreaPy
      ];
    };
  };
}
```

Method 3 - compile from sources using Conan:

```sh
git clone http://gitea.nul/astro/astrea_py
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
git clone http://gitea.nul/astro/astrea_py
cd astrea_py; \
  just configure; \
  just build;
```

## License

- License: [GPL-3](./LICENSE)
- Author: [Artem Shepelin](mailto:4.shepelin@gmail.com)