# astrea_py

![logo](assets/logo.svg)

Python bindings for [astrea](https://gitea.zarux.ru/astro/astrea), library for
statistical equilibrium calculations in cosmic plasma.

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
poetry source add --priority=explicit astro https://gitea.zarux.ru/api/packages/astro/pypi/simple
# Install
poetry add --source=astro astrea
```

## Examples

See [examples](./tests/examples).

## License

License: [GPL-3](./LICENSE)  
Author: Artem Shepelin (4.shepelin@gmail.com)