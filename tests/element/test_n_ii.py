import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    n_ii = aa.element.n_ii

    Lambda_vs_T = n_ii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 9.82e-21
    assert Lambda_vs_T[1][-1] == 1.39e-18


def test_f_vs_T_KK():
    n_ii = aa.element.n_ii

    res = n_ii.f_vs_T_KK()
    ans = [[np.zeros((2, 0))]]

    assert len(res) == len(ans)
    assert len(res[0]) == len(ans[0])
    assert (res[0][0] == ans[0][0]).all()


def test_i():
    n_ii = aa.element.n_ii

    assert n_ii.i() == 1.0


def test_Z():
    n_ii = aa.element.n_ii

    assert n_ii.Z() == 7.0


def test_M():
    n_ii = aa.element.n_ii

    assert n_ii.M() == 14.0


def test_I():
    n_ii = aa.element.n_ii

    assert n_ii.I() == 29.569395818476977


def test_f_KK():
    n_ii = aa.element.n_ii

    assert (n_ii.f_KK() == np.zeros((0, 0))).all()


def test_sigma_vs_nu_K():
    n_ii = aa.element.n_ii

    res = n_ii.sigma_vs_nu_K()
    ans = [np.zeros((2, 0))]

    assert len(res) == len(ans)
    assert (res[0] == ans[0]).all()


def test_STRUCTURE():
    n_ii = aa.element.n_ii

    assert len(n_ii.STRUCTURE.__members__) == 1
    assert n_ii.STRUCTURE.LS_He_2s2_2p2_3P.value == 0


def test_E_K():
    n_ii = aa.element.n_ii

    assert n_ii.E_K().shape == (1,)

    keys = [v.value for v in [
        n_ii.STRUCTURE.LS_He_2s2_2p2_3P,
    ]]
    E = n_ii.E_K()[keys]
    assert E == np.array([0.0])


def test_n():
    n_ii = aa.element.n_ii

    assert n_ii.n_K().shape == (1,)

    keys = [v.value for v in [
        n_ii.STRUCTURE.LS_He_2s2_2p2_3P,
    ]]
    n = n_ii.n_K()[keys]
    assert n == np.array([2.0])


def test_g_K():
    n_ii = aa.element.n_ii

    assert n_ii.g_K().shape == (1,)

    keys = [v.value for v in [
        n_ii.STRUCTURE.LS_He_2s2_2p2_3P,
    ]]
    g = n_ii.g_K()[keys]
    assert g == np.array([9.0])