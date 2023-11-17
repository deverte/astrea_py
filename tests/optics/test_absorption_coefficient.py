import astrea as aa
import numpy as np
import pytest


def test_alpha_nu_X():
    alpha_nu_X = aa.optics.alpha_nu_X

    n_X = np.array([0.4, 0.6])
    g_K = np.array([9.0, 5.0])
    E_K = np.array([0.0, 9.15])
    A_KK = np.array([[0.0, 1.0e3], [1.0e3, 0.0]])
    nu = 1.957696455240094

    absorption_coefficient = (
        alpha_nu_X(n_X=n_X, g_K=g_K, E_K=E_K, A_KK=A_KK, nu=nu)
    )

    assert np.all(
        absorption_coefficient
        == np.array([1.2567614843378096e-25, 1.8851422265067139e-25])
    )