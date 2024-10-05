import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    h_ii = aa.element.h_ii

    Lambda_vs_T = h_ii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 6.26e-25
    assert Lambda_vs_T[1][-1] == 1.37e-23


def test_f_vs_T_KK():
    h_ii = aa.element.h_ii

    res = h_ii.f_vs_T_KK()
    ans = [[np.zeros((2, 0))]]

    assert len(res) == len(ans)
    assert len(res[0]) == len(ans[0])
    assert (res[0][0] == ans[0][0]).all()


def test_E_K():
    h_ii = aa.element.h_ii

    assert h_ii.E_K().shape == (1,)

    keys = [v.value for v in [
        h_ii.STRUCTURE.LS_1,
    ]]
    E = h_ii.E_K()[keys]
    assert E == np.array([0.0])


def test_i():
    h_ii = aa.element.h_ii

    assert h_ii.i() == 1.0


def test_Z():
    h_ii = aa.element.h_ii

    assert h_ii.Z() == 1.0


def test_M():
    h_ii = aa.element.h_ii

    assert h_ii.M() == 1.0


def test_I():
    h_ii = aa.element.h_ii

    assert h_ii.I() == 0.0


def test_f_KK():
    h_ii = aa.element.h_ii

    assert (h_ii.f_KK() == np.zeros((0, 0))).all()


def test_A_H_sun():
    h_ii = aa.element.h_ii

    assert h_ii.A_H_sun() == 1.0


def test_n():
    h_ii = aa.element.h_ii

    assert h_ii.n_K().shape == (1,)

    keys = [v.value for v in [
        h_ii.STRUCTURE.LS_1,
    ]]
    n = h_ii.n_K()[keys]
    assert n == np.array([1.0])


def test_g_K():
    h_ii = aa.element.h_ii

    assert h_ii.g_K().shape == (1,)

    keys = [v.value for v in [
        h_ii.STRUCTURE.LS_1,
    ]]
    g = h_ii.g_K()[keys]
    assert g == np.array([1.0])


def test_STRUCTURE():
    h_ii = aa.element.h_ii

    assert len(h_ii.STRUCTURE.__members__) == 1
    assert h_ii.STRUCTURE.LS_1.value == 0