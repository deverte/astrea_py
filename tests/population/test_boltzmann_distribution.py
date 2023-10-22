import astrea as aa
import pytest
import numpy as np


def test_n():
    lte = aa.population.boltzmann_distribution

    T = np.array([1.0e3, 1.0e4])
    g = [np.array([9.0, 5.0]), np.array([4.0])]
    E = [np.array([0.0, 9.15]), np.array([0.0])]

    n = lte.n(T=T, g=g, E=E)
    assert n[0][0] == pytest.approx(np.array([1.0, 4.27323816e-47]))
    assert n[0][1] == np.array([1.0])
    assert n[1][0] == pytest.approx(np.array([0.9999864067109563, 1.3593289043679005e-05]))
    assert n[1][1] == np.array([1.0])