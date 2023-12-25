import astrea as aa
import numpy as np
import pytest


def test_P_v_X():
    P = aa.math.maxwell_boltzmann_distribution.P_v_X

    v_X = np.array([0, 1, 5])
    T_X = np.array([1e3, 1e4, 1e5])
    m = 1.0

    P_X = P(v_X=v_X, T_X=T_X, m=m)

    assert P_X == pytest.approx([
        2.5099834856158822,
        0.04443057715576289,
        0.0005884351277770272,
    ])