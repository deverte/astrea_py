import astrea as aa
import numpy as np
import pytest


def test_P_X():
    P = aa.math.normal_distribution.P_X

    x_X = np.array([-5, -1, 0, 1, 5])
    x_0 = 0
    sigma = np.sqrt(0.2)

    P_X = P(x_X=x_X, x_0=x_0, sigma=sigma)

    assert P_X == pytest.approx([
        0.0,
        0.07322491280963239,
        0.8920620580763854,
        0.07322491280963239,
        0.0,
    ])