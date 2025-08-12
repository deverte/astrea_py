{
  description = "astrea_py";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-25.05";
    astreapkgs.url =
      "https://github.com/deverte/astrea/archive/refs/tags/v0.8.0.tar.gz"; # managed by justfile
  };

  outputs = inputs@{ self, nixpkgs, astreapkgs, ... }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
    astrea = astreapkgs.packages.${system}.default;

    defaultPythonPackages = pkgs.python313Packages;

    buildAstreaPyPackage = pythonPackages: pythonPackages.buildPythonPackage {
      name = "astrea_py";
      version = "0.8.0"; # managed by justfile
      src = ./.;
      nativeBuildInputs = [
        pkgs.cmake
        pkgs.just
        pkgs.ninja
        pkgs.stdenv
      ];
      buildInputs = [
        astrea
        pkgs.eigen
        pythonPackages.build
        pythonPackages.pybind11
      ];
      propagatedBuildInputs = [
        pythonPackages.numpy
      ];
      configurePhase = ''
        export Eigen3_INCLUDE_DIRS="${pkgs.eigen}/include/eigen3"
        just configure
      '';
      buildPhase = ''
        just build
      '';
      meta = {
        homepage = "https://github.com/deverte/astrea_py";
        license = pkgs.lib.licenses.gpl3;
        platforms = pkgs.lib.platforms.linux ++ pkgs.lib.platforms.darwin;
        maintainers = [ pkgs.lib.maintainers.deverte ];
      };
    };
  in {
    devShells.${system}.default = pkgs.mkShell {
      name = "astrea_py";
      venvDir = ".venv";
      nativeBuildInputs = [
        pkgs.cmake
        pkgs.just
        pkgs.ninja
        defaultPythonPackages.python-lsp-server
        defaultPythonPackages.pytest
        defaultPythonPackages.twine
        defaultPythonPackages.virtualenv
        defaultPythonPackages.venvShellHook
      ];
      buildInputs = [
        astrea
        pkgs.eigen
        defaultPythonPackages.build
        defaultPythonPackages.numpy
        defaultPythonPackages.pybind11
        defaultPythonPackages.wheel
      ];
      shellHook = ''
        export Eigen3_INCLUDE_DIRS="${pkgs.eigen}/include/eigen3"
        runHook venvShellHook
      '';
    };

    packages.${system} = {
      default = buildAstreaPyPackage defaultPythonPackages;
      "python310" = buildAstreaPyPackage pkgs.python310Packages;
      "python311" = buildAstreaPyPackage pkgs.python311Packages;
      "python312" = buildAstreaPyPackage pkgs.python312Packages;
      "python313" = buildAstreaPyPackage pkgs.python313Packages;
    };
  };
}
