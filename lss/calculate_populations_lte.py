import numpy as np

from lss.lss_py import lte_boltzmann_population


def calculate_populations_lte(
    elements,
    temperatures = None,
):
    populations_lte = np.zeros(
        (len(temperatures), sum([len(el.keys) for el in elements]))
    )
    for i, _ in enumerate(temperatures):
        populations_lte[i] = lte_boltzmann_population(
            elements,
            temperatures[i],
        )
    return populations_lte