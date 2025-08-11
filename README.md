# astrea_py

![logo](assets/logo.svg)

Python bindings for [astrea](https://github.com/deverte/astrea), library for
statistical equilibrium calculations in cosmic plasma.

## Installation

### Using pip

```sh
pip3 install astrea_py
```

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
    astreaPy = astreapypkgs.packages.${system}.default; // default Python
    // astreaPy = astreapypkgs.packages.${system}.python310; // specific Python
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
