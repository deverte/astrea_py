import astrea as aa
import pytest
import numpy as np


def test_n_x_z():
    lte = aa.population.boltzmann_distribution

    g_z = np.array([9.0, 5.0])
    E_z = np.array([0.0, 9.15])
    T_x = 1.0e3

    n = lte.n_x_z(g_z=g_z, E_z=E_z, T_x=T_x)
    assert n == pytest.approx(np.array([1.0, 4.27323816e-47]))


def test_n_x():
    lte = aa.population.boltzmann_distribution

    g = [np.array([9.0, 5.0]), np.array([4.0])]
    E = [np.array([0.0, 9.15]), np.array([0.0])]
    T_x = 1.0e3

    n = lte.n_x(g=g, E=E, T_x=T_x)
    assert n[0] == pytest.approx(np.array([1.0, 4.27323816e-47]))
    assert n[1] == np.array([1.0])