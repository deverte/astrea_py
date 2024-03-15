{
  description = "astrea_py";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-23.11";
    astreaPkg.url = "http://gitea.nul/astro/astrea/archive/v0.7.4.tar.gz"; # managed
  };

  outputs = inputs@{ self, nixpkgs, astreaPkg, ... }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
    astrea = astreaPkg.packages.${system}.default.overrideAttrs (prev: rec {
      patches = [
        ./patches/astrea/gj_436_fossati_2.patch
        ./patches/astrea/gj_436_fossati.patch
        ./patches/astrea/gj_3470_bourrier.patch
        ./patches/astrea/hat_p_11_ben_jaffel.patch
        ./patches/astrea/hd_73583_zhang.patch
        ./patches/astrea/hd_85512_muscles.patch
        ./patches/astrea/hd_189733_fossati.patch
        ./patches/astrea/hd_209458_fossati.patch
        ./patches/astrea/hd_209458_salz.patch
        ./patches/astrea/kelt_9_fossati.patch
        ./patches/astrea/oscillator_strengths_doppler.patch
        ./patches/astrea/oscillator_strengths_stark.patch
        ./patches/astrea/sun_linsky.patch
        ./patches/astrea/sun_tobiska.patch
        ./patches/astrea/wasp_80_salz_fossati.patch
      ];
    });
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
      version = "0.7.4"; # managed
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