{
  description = "astrea_py";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-23.11";
    astreapkg.url = "https://gitea.zarux.ru/astro/astrea/archive/e01acc5018803c8f7364b55c2e8949fc8d901992.tar.gz";
  };

  outputs = inputs@{ self, nixpkgs, astreapkg, ... }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
    astrea = astreapkg.defaultPackage.${system}.overrideAttrs (prev: rec {
      patches = [
        ./patches/astrea/fe_ii_effective_collision_strength.patch
        ./patches/astrea/interp1d_linear.patch
        ./patches/astrea/saha_ionization_equation.patch
      ];
    });
    stdenv = pkgs.llvmPackages.stdenv;
    python = pkgs.python311;
    pythonPackages = pkgs.python311Packages;
  in {
    devShell.${system} = stdenv.mkDerivation {
      name = "astrea_py";
      venvDir = ".venv";
      nativeBuildInputs = [
        pkgs.cmake
        pkgs.just
        pkgs.ninja
        pythonPackages.python-lsp-server
        pythonPackages.pytest
        pythonPackages.twine
        pythonPackages.virtualenv
        pythonPackages.venvShellHook
      ];
      buildInputs = [
        astrea
        pkgs.eigen
        pythonPackages.build
        pythonPackages.numpy
        pythonPackages.pybind11
        pythonPackages.wheel
      ];
      shellHook = ''
        export Eigen3_INCLUDE_DIRS="${pkgs.eigen}/include/eigen3"
        runHook venvShellHook
      '';
    };

    defaultPackage.${system} = pythonPackages.buildPythonPackage {
      name = "astrea_py";
      version = "0.7.3"; # managed by justfile
      src = ./.;
      nativeBuildInputs = [
        stdenv
        pkgs.cmake
        pkgs.just
        pkgs.ninja
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
        homepage = "https://gitea.zarux.ru/astro/astrea_py";
        licencse = pkgs.lib.licenses.gpl3;
        platforms = pkgs.lib.platforms.linux ++ pkgs.lib.platforms.darwin;
        maintainers = [ pkgs.lib.maintainers.deverte ];
      };
    };
  };
}