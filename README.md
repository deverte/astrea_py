# astrea_py

Python bindings for [astrea](https://gitea.zarux.ru/astro/astrea), library for
statistical equilibrium calculations in plasma. Supports the following detailed
balance pairs: collisional bound-bound transitions, collisional
ionization-three-body recombination, radiative bound-bound transitions,
photoionization-radiative recombination-dielectronic recombination, charge
transfer ionization-recombination, and spontaneous emission.

## Installation

### On Linux X86-64 Python 3.10

```sh
pip install --index-url https://gitea.zarux.ru/api/packages/astro/pypi/simple astrea-py
```

### Other

Install build dependencies, add Conan repo

```sh
pip install conan
conan profile detect
conan remote add astro https://gitea.zarux.ru/api/packages/astro/conan
```

Install Conan dependencies (optionally):

```sh
conan install --remote=astro --requires=astrea/<VERSION> -s:h compiler.cppstd=17 --build=missing
```

Install:

```sh
pip install git+https://gitea.zarux.ru/astro/astrea_py
```

## License

License: GPL-3  
Author: Artem Shepelin (4.shepelin@gmail.com)