import numpy as np

from . import lss_py


def calculate_populations_lte(
    elements,
    temperatures = None,
    electron_temperatures = None,
    electron_number_densities = None,
):
    populations_lte = np.zeros(
        (len(temperatures), sum([len(el.keys) for el in elements]))
    )
    for i, _ in enumerate(temperatures):
        populations_lte[i] = lss_py.lte_population(
            elements,
            temperatures[i],
            electron_temperatures[i],
            electron_number_densities[i],
        )
    return populations_lte