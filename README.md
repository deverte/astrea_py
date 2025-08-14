# astrea_py

![logo](assets/logo.svg)

Python bindings for [astrea](https://github.com/deverte/astrea), library for
statistical equilibrium calculations in cosmic plasma.

## Installation

### Using pip

```sh
pip3 install astrea_py
```

Officially supported Python versions (for other versions, the library can be
built manually):

- CPython 3.13
- CPython 3.12
- CPython 3.11
- CPython 3.10

Officially supported platforms (for other platforms, the library can be built
manually):

- `manylinux_2_34_x86_64` (glibc 2.34)
- `manylinux_2_34_i686` (glibc 2.34)
- `manylinux_2_34_aarch64` (glibc 2.34)
- `manylinux_2_28_x86_64` (glibc 2.28)
- `manylinux_2_28_i686` (glibc 2.28)
- `manylinux_2_28_aarch64` (glibc 2.28)
- `manylinux2014_x86_64` (glibc 2.17)
- `manylinux2014_i686` (glibc 2.17)
- `manylinux2014_aarch64` (glibc 2.17)
- `macosx_14_0_universal2`
- `macosx_10_9_x86_64`
- `win_amd64`
- `win_arm64`

### Using Nix Flake

`flake.nix`:

```nix
{
  inputs = {
    astreapypkgs.url =
      "http://github.com/deverte/astrea_py/archive/refs/tags/v0.8.0.tar.gz";
  };

  outputs = inputs@{ self, astreapypkgs, ... }:
  let
    system = "x86_64-linux";
    astreaPy = astreapypkgs.packages.${system}.default; # default Python
    # astreaPy = astreapypkgs.packages.${system}.python310; # specific Python
  in {
    devShells.${system}.default = pkgs.mkShell {
      buildInputs = [
        astreaPy
      ];
    };
  };
}
```

## Usage

See [tests](./tests) for usage examples.

## License

- License: [GPL-3](./LICENSE)
- Author: [Artem Shepelin](mailto:4.shepelin@gmail.com)
