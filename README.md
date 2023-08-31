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
pip install git+https://gitea.zarux.ru/astro/astrea_py
```

## Documentation

Library has the following main parts: **Data** ([Elements](#elements),
[Spectrum](#spectrum)) and [Statistical Equilibrium](#statistical-equilibrium).

> This guide describes only main use cases.
> Detailed description of functions' arguments and classes' fields can be found
> in [astrea](https://gitea.zarux.ru/astro/astrea) header files.

### Statistical Equilibrium

Two approximations are available for calculating populations of electron levels:
LTE (local thermodynamical equilibrium) and NLTE (non-local themodynamical
equilibrium).

#### LTE

LTE can be calculated using only Boltzmann distribution (with manually set
elements population), or Boltzmann distribution and Saha ionization equation.
Resulting population has the `numpy.ndarray` type.

Further it will be assumed that [Elements](#elements) and [Spectrum](#spectrum)
are initialized and the library is included (`import astrea`).

```python
temperature = 1.0e4 # kelvin
elements_population = np.array([
    # Size must be equal to elements number
])
electrons_population = astrea.lte_boltzmann_population(
    elements,
    elements_population,
    temperature,
)

temperature = 1.0e4 # kelvin
electron_temperature = 1.0e4 # kelvin
electron_number_density = 1.0e5 # centimeter^{-3}
electrons_population = astrea.lte_boltzmann_saha_population(
    elements,
    temperature
    electron_temperature,
    electron_number_density,
)
```

#### NLTE

NLTE calculation of current electron population
**with automatic calculation of elements population** requires rates matrix that
can be composed using [Transitions](#transitions), time step, and previus
electron population.

```python
import numpy as np

electrons_population_1 = np.array([
    # Size must be equal to sum of all elements' keys
])
delta_time = 1.0e-2 # second
rates_matrix = # See Transitions section
electrons_population_2 = astrea.nlte_population_full(
    population_1,
    delta_time,
    rates_matrix,
)
```

NLTE also can be calculated **with manually set of elements population**.

```python
import numpy as np

elements_population = np.array([
    # Size must be equal to elements number
])
electrons_population_1 = np.array([
    # Size must be equal to sum of all elements' keys
])
delta_time = 1.0e-2 # second
rates_matrix = # See Transitions section
electrons_population_2 = astrea.nlte_population_per_elements(
    elements,
    elements_population
    electrons_population_1,
    delta_time,
    rates_matrix,
)
```

##### Transitions

Here will be used the following abbreviations: **CD** - collisional
de-excitation, **CE** - collisional excitation, **CI** - collisonal ionization,
**CR** - collisional recombination, **RD** - radiative de-excitation, **RE** -
radiative excitation (photoexcitation), **RI** - radiative ionization
(photoionization), **RR** - radiative recombination.

Final rates matrix is a sum of per-process rate matrix:

```python
ci = astrea.ci_hahn_rates(
    elements,
    electron_temperature,
    electron_number_density,
)
tbr = astrea.tbr_hahn_rates(
    elements,
    electron_temperature,
    electron_number_density,
)
# ...

rates_matrix = ci + tbr # + ...
```

The following transitions rates functions are available:

- `astrea.cd_regemorter_rates`
- `astrea.ce_regemorter_rates`
- `astrea.ci_mashonkina_o1_rate_coefficients`
- `astrea.cr_mashonkina_o1_rate_coefficients`
- `astrea.rd_nist_o1_rates`
- `astrea.re_lorentz_rates`
- `astrea.ri_mashonkina_o1_rates`
- `astrea.rr_mashonkina_o1_rate_coefficients`

### Elements

Elements typically passed to statistical equilibrium functions as a `list`.

```python
o1_mashonkina = astrea.O1Mashonkina()
o1_mashonkina.keys = ["12P3P4", "12P1D4"] # Select only two levels
o2_mashonkina = astrea.O2Mashonkina()
o2_mashonkina.keys = o2_mashonkina.all_keys() # Select all levels
elements = [
    o1_mashonkina,
    o2_mashonkina,
]
```

The following elements are available:

- `astrea.H1`
- `astrea.H2`
- `astrea.He1`
- `astrea.He2`
- `astrea.O1Mashonkina`
- `astrea.O2Mashonkina`

### Spectrum

Spectrum typically passed to statistical equilibrium functions as an object.

```python
spectrum = astrea.SunGueymard()
```

The following syntetic spectra are available:

- `astrea.BlackBodyPlanck` (`temperature` and `total_area` must be specified)

The following observed spectra are available:

- `astrea.Kelt9Fossati`
- `astrea.SunGueymard`

## License

License: [GPL-3](./LICENSE)  
Author: Artem Shepelin (4.shepelin@gmail.com)