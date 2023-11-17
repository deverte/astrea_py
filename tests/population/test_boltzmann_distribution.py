import astrea as aa
import pytest
import numpy as np


def test_n_XZK():
    lte = aa.population.boltzmann_distribution

    T_X = np.array([1.0e3, 1.0e4])
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    n_XZK = lte.n_XZK(T_X=T_X, g_ZK=g_ZK, E_ZK=E_ZK)
    assert n_XZK[0][0] == pytest.approx(np.array([1.0, 4.27323816e-47]))
    assert n_XZK[0][1] == np.array([1.0])
    assert n_XZK[1][0] == pytest.approx(np.array([0.9999864067109563, 1.3593289043679005e-05]))
    assert n_XZK[1][1] == np.array([1.0])