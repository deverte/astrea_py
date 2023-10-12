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

## Example

```python
import astrea as aa
import numpy as np


class Spectrum:
    def __init__(self, module, distance=0.03):
        self.spectrum = module.spectrum()
        self.spectrum[1] = self.spectrum[1] / distance**2


class Element:
    def __init__(self, module, keys):
        int_keys = np.array([k.value for k in keys])
        sort_indices = module.E()[int_keys].argsort()
        sorted_keys = [int_keys[i] for i in sort_indices]

        self.keymap = {
            keys[sort_indices[i]]: i for i in range(len(sort_indices))
        }

        self.E = module.E()[sorted_keys]
        self.g = module.g()[sorted_keys]
        self.A = module.A().T[sorted_keys].T[sorted_keys]
        if "sigma_k" in module.__dict__:
            self.sigma = [module.sigma_k()[k] for k in sorted_keys]
        else:
            self.sigma = []


class Env:
    def __init__(self, elements, spectrum, T, N_e, N_a, Delta_t=6e2):
        self.elements = elements
        self.E = [e.E for e in elements]
        self.g = [e.g for e in elements]
        self.A = [e.A for e in elements]
        self.sigma = [e.sigma for e in elements]

        self.F_lambda = spectrum.spectrum

        self.T = T
        self.N_e = N_e
        self.N_a = N_a
        self.Delta_t = Delta_t

        self.cd = aa.transition.cd_regemorter.R_x
        self.ce = aa.transition.ce_regemorter.R_x
        self.re = aa.transition.re_lorentz.R_x
        self.ri = aa.transition.ri.R_x

        self.nlte = aa.population.balance_equation.n_x_t_plus_Delta_t
        self.lte = aa.population.boltzmann_distribution.n_x

        self.n = []

    def equilibrium(self):
        re = (
            self.re(g=self.g, E=self.E, A=self.A, F_lambda=self.F_lambda)
        )
        rd = self.A
        ri = self.ri(sigma=self.sigma, F_lambda=self.F_lambda)
        rr = [np.zeros_like(R) for R in ri]

        R_x_ik = ri
        R_x_ki = rr

        for i, _ in enumerate(self.T):
            T_x = self.T[i]
            N_e_x = self.N_e[i]
            N_a_x = self.N_a[i]

            ce = self.ce(g=self.g, E=self.E, T_x=T_x, N_e_x=N_e_x)
            cd = self.cd(g=self.g, T_x=T_x, N_e_x=N_e_x)

            R_x_ij = [re[i] + ce[i] for i in range(len(self.elements))]
            R_x_ji = [rd[i] + cd[i] for i in range(len(self.elements))]

            lte = self.lte(self.g, self.E, T_x)
            n_x_t = [N_a_x[i] * lte[i] for i in range(len(lte))]

            nlte = self.nlte(
                n_x_t=n_x_t,
                R_x_ij=R_x_ij,
                R_x_ji=R_x_ji,
                R_x_ik=R_x_ik,
                R_x_ki=R_x_ki,
                Delta_t=self.Delta_t,
            )
            nlte = [ # full population is taken from MHD
                N_a_x[i] * nlte[i] / nlte[i].sum() for i in range(len(nlte))
            ]
            self.n.append(nlte)


size = 100
T = np.geomspace(1e3, 1e4, size)
N_e = np.geomspace(1e7, 1e9, size)
N_a = np.ones((2, size)).T / 2
Delta_t = 6e10
x = np.linspace(-10, 10, size)

o_i_t = aa.element.o_i_mashonkina.TERM
o_ii_t = aa.element.o_ii_mashonkina.TERM

o_i = Element(
    module=aa.element.o_i_mashonkina,
    keys=[
        o_i_t.LS_1s2_2s2_2p4_3P,
        o_i_t.LS_1s2_2s2_2p3_4So_3s_5So,
    ],
)
o_ii = Element(
    module=aa.element.o_ii_mashonkina,
    keys=list(o_ii_t.__members__.values()),
)

spectrum = Spectrum(module=aa.spectrum.kelt_9_fossati, distance=0.03)
elements = [o_i, o_ii]
env = Env(elements, spectrum, T, N_e, N_a, Delta_t=Delta_t)

env.equilibrium()

env.n # result
```


## License

License: [GPL-3](./LICENSE)  
Author: Artem Shepelin (4.shepelin@gmail.com)