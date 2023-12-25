import astrea as aa
import numpy as np
import pytest


def test_Delta_nu_D_X():
    Delta_nu_D_X = aa.optics.doppler_line_width.Delta_nu_D_X

    T_X = np.array([1e4, 1e5])
    m_i = 16.0
    nu_ij = 1.957696455240094

    doppler_line_width = Delta_nu_D_X(T_X=T_X, m_i=m_i, nu_ij=nu_ij)

    assert doppler_line_width == pytest.approx(np.array([
        2.0976010423816606e-05, 6.633196916269431e-05,
    ]))