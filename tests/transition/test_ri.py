import astrea as aa
import numpy as np
import pytest


def test_R_x_z_ik():
    ri = aa.transition.ri
    o_i = aa.element.o_i_mashonkina

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_5So,
    ]]
    sigma_k = [o_i.sigma_k()[key] for key in keys][0]
    F_lambda = aa.spectrum.kelt_9_fossati.spectrum()
    F_lambda[1] = F_lambda[1] / 0.03**2

    R = ri.R_x_z_ik(sigma_z_k=sigma_k, F_lambda=F_lambda)
    assert R == 357.10869236099074


def test_R_x_z():
    ri = aa.transition.ri
    o_i = aa.element.o_i_mashonkina

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_5So,
    ]]
    sigma_k = [o_i.sigma_k()[key] for key in keys]
    F_lambda = aa.spectrum.kelt_9_fossati.spectrum()
    F_lambda[1] = F_lambda[1] / 0.03**2

    R = ri.R_x_z(sigma_z=sigma_k, F_lambda=F_lambda)
    assert (
        R == pytest.approx(np.array([357.10869236099074]))
    )


def test_R_x():
    ri = aa.transition.ri
    o_i = aa.element.o_i_mashonkina

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_5So,
    ]]
    sigma = [[o_i.sigma_k()[key] for key in keys], [np.array([[0.0], [0.0]])]]
    F_lambda = aa.spectrum.kelt_9_fossati.spectrum()
    F_lambda[1] = F_lambda[1] / 0.03**2

    R = ri.R_x(sigma=sigma, F_lambda=F_lambda)
    assert (
        R[0] ==
            pytest.approx(np.array([357.10869236099074]), np.array([0.0]))
    )
    assert (R[1] == np.array([0.0])).all()