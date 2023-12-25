import astrea as aa
import numpy as np
import pytest


def test_alpha_nu_XE():
    alpha_nu_XE = aa.optics.absorption_coefficient.alpha_nu_XE

    n_X = np.array([0.4, 0.6])
    g_i = 9.0
    g_j = 5.0
    A_ji = 1.0e3
    nu_ij = 1.957696455240094
    H_E = [0.5, 0.5]

    absorption_coefficient = (
        alpha_nu_XE(n_X=n_X, g_j=g_j, g_i=g_i, nu_ij=nu_ij, A_ji=A_ji, H_E=H_E)
    )

    assert absorption_coefficient == pytest.approx(np.array([
        [69301543.56389154, 69301543.56389154],
        [103952315.34583731, 103952315.34583731],
    ]))