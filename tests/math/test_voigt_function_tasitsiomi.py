import astrea as aa
import numpy as np
import pytest


def test_H_X():
    H = aa.math.voigt_function_tasitsiomi.H_X
    H_a = aa.math.voigt_function.H_X

    x_X = np.array([-2.0, 0.0, 5.0])
    x_0 = 0.0
    sigma = 1.0e4
    gamma = 1.0

    u_X = (x_X - x_0) / (np.sqrt(2.0) * sigma)
    a = gamma / (np.sqrt(2.0) * sigma)

    H_X = H(u_X=u_X, a=a)
    V_X = H_X / (np.sqrt(2 * np.pi) * sigma)

    H_a_X = H_a(u_X=u_X, a=a)
    V_a_X = H_a_X / (np.sqrt(2 * np.pi) * sigma)

    assert V_X == pytest.approx(V_a_X, abs=1e-4)