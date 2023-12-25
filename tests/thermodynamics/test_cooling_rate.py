import astrea as aa
import numpy as np
import pytest


def test_L_X():
    L_X = aa.thermodynamics.cooling_rate.L_X

    x_X = np.arange(2)
    n_XK = [
        np.array([0.4, 0.6]),
        np.array([0.5, 0.5]),
    ]
    R_XKK = [
        np.array([[0.0, 1.0e3], [1.0e3, 0.0]]),
        np.array([[0.0, 5.0e3], [5.0e3, 0.0]]),
    ]
    E_K = np.array([0.0, 1.957696455240094])

    cooling = L_X(x_X=x_X, n_XK=n_XK, R_XKK=R_XKK, E_K=E_K)

    assert cooling.shape[0] == 2
    assert cooling[0] == 1.881945310230183e-09
    assert cooling[1] == 7.841438792625764e-09