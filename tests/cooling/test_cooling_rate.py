import astrea as aa
import numpy as np
import pytest


def test_L():
    L = aa.cooling.L

    x = np.arange(2)
    n_z = [
        np.array([0.4, 0.6]), # x=0
        np.array([0.5, 0.5]), # x=1
    ]
    R_z = [
        np.array([[0.0, 1.0e3], [1.0e3, 0.0]]), # x=0
        np.array([[0.0, 5.0e3], [5.0e3, 0.0]]), # x=1
    ]
    E_z = np.array([0.0, 1.957696455240094])

    cooling = L(x=x, n_z=n_z, R_z=R_z, E_z=E_z)

    assert cooling.shape[0] == 2
    assert cooling[0] == 1.881945310230183e-09
    assert cooling[1] == 7.841438792625764e-09