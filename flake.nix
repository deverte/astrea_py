{
  description = "astrea_py";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-23.11";
    astreaPkg.url = "http://gitea.nul/astro/astrea/archive/v0.7.6.tar.gz"; # managed by justfile
  };

  outputs = inputs@{ self, nixpkgs, astreaPkg, ... }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
    astrea = astreaPkg.packages.${system}.default;
    stdenv = pkgs.llvmPackages.stdenv;
    python = pkgs.python311;
    pythonPackages = pkgs.python311Packages;
  in {
    devShells.${system}.default = stdenv.mkDerivation {
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

    packages.${system}.default = pythonPackages.buildPythonPackage {
      name = "astrea_py";
      version = "0.7.6"; # managed by justfile
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
        homepage = "https://gitea.nul/astro/astrea_py";
        licencse = pkgs.lib.licenses.gpl3;
        platforms = pkgs.lib.platforms.linux ++ pkgs.lib.platforms.darwin;
        maintainers = [ pkgs.lib.maintainers.deverte ];
      };
    };
  };
}