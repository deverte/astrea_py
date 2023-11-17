import astrea as aa
import numpy as np
import pytest


def test_tau():
    tau = aa.optics.tau

    x_X = np.array([0.1, 0.2])
    n_X = np.array([0.4, 0.6])
    g_K = np.array([9.0, 5.0])
    E_K = np.array([0.0, 9.15])
    A_KK = np.array([[0.0, 1.0e3], [1.0e3, 0.0]])
    nu = 1.957696455240094

    tau = tau(x_X=x_X, n_X=n_X, g_K=g_K, E_K=E_K, A_KK=A_KK, nu=nu)

    assert tau == 1.570951855422262e-26