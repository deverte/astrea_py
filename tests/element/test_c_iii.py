import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    c_iii = aa.element.c_iii

    Lambda_vs_T = c_iii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 5.33e-22
    assert Lambda_vs_T[1][-1] == 5.75e-19


def test_f_vs_T_KK():
    c_iii = aa.element.c_iii

    res = c_iii.f_vs_T_KK()
    ans = [[np.zeros((2, 0))]]

    assert len(res) == len(ans)
    assert len(res[0]) == len(ans[0])
    assert (res[0][0] == ans[0][0]).all()


def test_E_K():
    c_iii = aa.element.c_iii

    assert c_iii.E_K().shape == (1,)

    keys = [v.value for v in [
        c_iii.STRUCTURE.LS_He_2s2_1S,
    ]]
    E = c_iii.E_K()[keys]
    assert E == np.array([0.0])


def test_i():
    c_iii = aa.element.c_iii

    assert c_iii.i() == 2.0


def test_Z():
    c_iii = aa.element.c_iii

    assert c_iii.Z() == 6.0


def test_M():
    c_iii = aa.element.c_iii

    assert c_iii.M() == 12.0


def test_I():
    c_iii = aa.element.c_iii

    assert c_iii.I() == 47.8881366396517


def test_f_KK():
    c_iii = aa.element.c_iii

    assert (c_iii.f_KK() == np.zeros((0, 0))).all()


def test_sigma_vs_nu_K():
    c_iii = aa.element.c_iii

    res = c_iii.sigma_vs_nu_K()
    ans = [np.zeros((2, 0))]

    assert len(res) == len(ans)
    assert (res[0] == ans[0]).all()


def test_g_K():
    c_iii = aa.element.c_iii

    assert c_iii.g_K().shape == (1,)

    keys = [v.value for v in [
        c_iii.STRUCTURE.LS_He_2s2_1S,
    ]]
    g = c_iii.g_K()[keys]
    assert g == np.array([1.0])


def test_STRUCTURE():
    c_iii = aa.element.c_iii

    assert len(c_iii.STRUCTURE.__members__) == 1
    assert c_iii.STRUCTURE.LS_He_2s2_1S.value == 0