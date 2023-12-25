import astrea as aa
import numpy as np
import pytest


def test_P_X():
    P = aa.math.cauchy_lorentz_distribution.P_X

    x_X = np.array([-5, -1, 0, 1, 5])
    x_0 = 0
    gamma = 0.5

    P_X = P(x_X=x_X, x_0=x_0, gamma=gamma)

    assert P_X == pytest.approx([
        0.00630316606304536,
        0.12732395447351627,
        0.6366197723675814,
        0.12732395447351627,
        0.00630316606304536,
    ])