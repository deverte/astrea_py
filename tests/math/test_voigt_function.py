import astrea as aa
import numpy as np
import pytest


def test_H_X():
    H = aa.math.voigt_function.H_X

    x_X = np.array([-2.0, 0.0, 5.0])
    x_0 = 0.0
    sigma = 1.0
    gamma = 1.0

    u_X = (x_X - x_0) / (np.sqrt(2.0) * sigma)
    a = gamma / (np.sqrt(2.0) * sigma)

    H_X = H(u_X=u_X, a=a, Y=int(1e2))
    V_X = H_X / (np.sqrt(2 * np.pi) * sigma)

    assert V_X == pytest.approx([
        0.08450579582571084,
        0.20757468539689405,
        0.013752976917653268,
    ])