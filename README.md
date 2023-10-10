# astrea_py

![logo](assets/logo.svg)

Python bindings for [astrea](https://gitea.zarux.ru/astro/astrea), library for
statistical equilibrium calculations in plasma. Supports the following detailed
balance pairs: collisional bound-bound transitions, collisional
ionization-three-body recombination, radiative bound-bound transitions,
photoionization-radiative recombination-dielectronic recombination, charge
transfer ionization-recombination, and spontaneous emission.

## Installation

```sh
# Using pip
pip3 install git+https://gitea.zarux.ru/astro/astrea_py

# Using poetry
poetry add git+https://gitea.zarux.ru/astro/astrea_py
```

On linux also can be installed already compiled binaries:

```sh
# Using pip
pip3 install --index-url https://gitea.zarux.ru/api/packages/astro/pypi/simple astrea

# Using poetry
# Add source
poetry source add astro https://gitea.zarux.ru/api/packages/astro/pypi/simple
# Install
poetry add astrea
```

## License

License: [GPL-3](./LICENSE)  
Author: Artem Shepelin (4.shepelin@gmail.com)