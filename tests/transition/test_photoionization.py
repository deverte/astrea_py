import astrea as aa
import numpy as np
import pytest


def test_R_XZK():
    ri = aa.transition.photoionization
    o_i = aa.element.o_i

    T_X = np.array([1.0e3, 1.0e4])
    keys = [v.value for v in [
        o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_5So,
    ]]
    sigma_vs_nu_ZK = [
        [o_i.sigma_vs_nu_K()[key] for key in keys],
        [np.array([[0.0], [0.0]])],
    ]
    F_lambda_vs_lambda = aa.spectrum.kelt_9_fossati.F_lambda_vs_lambda()
    F_lambda_vs_lambda[1] = F_lambda_vs_lambda[1] / 0.03**2
    tau_X = np.array([0.0, 0.0])

    R = ri.R_XZK(
        x_X=T_X,
        sigma_vs_nu_ZK=sigma_vs_nu_ZK,
        F_lambda_vs_lambda=F_lambda_vs_lambda,
        tau_X=tau_X,
    )
    assert (
        R[0][0] ==
            pytest.approx(np.array([362.1178317114999]), np.array([0.0]))
    )
    assert (R[0][1] == np.array([0.0])).all()