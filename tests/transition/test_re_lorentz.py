import astrea as aa
import numpy as np
import pytest


def test_R():
    re = aa.transition.re_lorentz

    T = np.array([1.0e3, 1.0e4])
    g = [np.array([9.0, 5.0]), np.array([4.0])]
    E = [np.array([0.0, 9.15]), np.array([0.0])]
    A = [np.array([[0.0, 0.0], [2780.00, 0.0]]), np.array([0.0])]
    F_lambda_vs_lambda = aa.spectrum.kelt_9_fossati.F_lambda_vs_lambda()
    F_lambda_vs_lambda[1] = F_lambda_vs_lambda[1] / 0.03**2

    R = re.R(x=T, g=g, E=E, A=A, F_lambda_vs_lambda=F_lambda_vs_lambda)
    assert (
        R[0][0] ==
            pytest.approx(np.array([[0.0, 0.0027102329380521524], [0.0, 0.0]]))
    )
    assert (R[0][1] == np.array([0.0])).all()