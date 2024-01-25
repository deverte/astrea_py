import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    mg_iii = aa.element.mg_iii

    Lambda_vs_T = mg_iii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 1.99e-24
    assert Lambda_vs_T[1][-1] == 2.09e-18


def test_f_vs_T_KK():
    mg_iii = aa.element.mg_iii

    res = mg_iii.f_vs_T_KK()
    ans = [[np.zeros((2, 0))]]

    assert len(res) == len(ans)
    assert len(res[0]) == len(ans[0])
    assert (res[0][0] == ans[0][0]).all()


def test_E_K():
    mg_iii = aa.element.mg_iii

    assert mg_iii.E_K().shape == (1,)

    keys = [v.value for v in [
        mg_iii.STRUCTURE.LS_Ne_1S,
    ]]
    E = mg_iii.E_K()[keys]
    assert E == np.array([0.0])


def test_i():
    mg_iii = aa.element.mg_iii

    assert mg_iii.i() == 2.0


def test_Z():
    mg_iii = aa.element.mg_iii

    assert mg_iii.Z() == 12.0


def test_M():
    mg_iii = aa.element.mg_iii

    assert mg_iii.M() == 24.304


def test_I():
    mg_iii = aa.element.mg_iii

    assert mg_iii.I() == 65.099544777729


def test_f_KK():
    mg_iii = aa.element.mg_iii

    assert (mg_iii.f_KK() == np.zeros((0, 0))).all()


def test_sigma_vs_nu_K():
    mg_iii = aa.element.mg_iii

    res = mg_iii.sigma_vs_nu_K()
    ans = [np.zeros((2, 0))]

    assert len(res) == len(ans)
    assert (res[0] == ans[0]).all()


def test_g_K():
    mg_iii = aa.element.mg_iii

    assert mg_iii.g_K().shape == (1,)

    keys = [v.value for v in [
        mg_iii.STRUCTURE.LS_Ne_1S,
    ]]
    g = mg_iii.g_K()[keys]
    assert g == np.array([1.0])


def test_STRUCTURE():
    mg_iii = aa.element.mg_iii

    assert len(mg_iii.STRUCTURE.__members__) == 1
    assert mg_iii.STRUCTURE.LS_Ne_1S.value == 0