import astrea as aa
import numpy as np
import pytest


def test_R():
    ri = aa.transition.ri
    o_i = aa.element.o_i_mashonkina

    T = np.array([1.0e3, 1.0e4])
    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_5So,
    ]]
    sigma_vs_nu = [[o_i.sigma_vs_nu()[key] for key in keys], [np.array([[0.0], [0.0]])]]
    F_lambda_vs_lambda = aa.spectrum.kelt_9_fossati.F_lambda_vs_lambda()
    F_lambda_vs_lambda[1] = F_lambda_vs_lambda[1] / 0.03**2

    R = ri.R(x=T, sigma_vs_nu=sigma_vs_nu, F_lambda_vs_lambda=F_lambda_vs_lambda)
    assert (
        R[0][0] ==
            pytest.approx(np.array([362.1178317114999]), np.array([0.0]))
    )
    assert (R[0][1] == np.array([0.0])).all()