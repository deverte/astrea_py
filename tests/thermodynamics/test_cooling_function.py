import astrea as aa
import numpy as np
import pytest


def test_Lambda_ZX():
    Lambda_ZX = aa.thermodynamics.cooling_function.Lambda_ZX

    x_X = np.arange(2)
    n_XZK = [
        [
            np.array([0.4, 0.6]),
        ],
        [
            np.array([0.5, 0.5]),
        ],
    ]
    R_XZKK = [
        [
            np.array([[0.0, 1.0e3], [1.0e3, 0.0]]),
        ],
        [
            np.array([[0.0, 5.0e3], [5.0e3, 0.0]]),
        ],
    ]
    E_ZK = [np.array([0.0, 1.957696455240094])]

    res_ZX = Lambda_ZX(x_X=x_X, n_XZK=n_XZK, R_XZKK=R_XZKK, E_ZK=E_ZK)

    assert len(res_ZX) == 1
    assert res_ZX[0].shape[0] == 2
    assert res_ZX[0][0] == -6.273151034100607e-10
    assert res_ZX[0][1] == 0.0