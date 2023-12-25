import astrea as aa
import numpy as np
import pytest


def test_V_E():
    V = aa.math.voigt_profile.V_E
    H = aa.math.voigt_function.H_X

    x_X = np.array([-2.0, 0.0, 5.0])
    x_0 = 0.0
    sigma = 1.0
    gamma = 1.0

    u_X = (x_X - x_0) / (np.sqrt(2.0) * sigma)
    a = gamma / (np.sqrt(2.0) * sigma)

    H_E = H(u_X=u_X, a=a)
    V_X = V(H_E=H_E, sigma=sigma)

    assert V_X == pytest.approx([
        0.08451998127993238,
        0.2075786538200644,
        0.013753301120958551,
    ])