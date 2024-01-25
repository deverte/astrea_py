import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    fe_iii = aa.element.fe_iii

    Lambda_vs_T = fe_iii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 1.22e-20
    assert Lambda_vs_T[1][-1] == 2.48e-18


def test_f_vs_T_KK():
    fe_iii = aa.element.fe_iii

    res = fe_iii.f_vs_T_KK()
    ans = [[np.zeros((2, 0))]]

    assert len(res) == len(ans)
    assert len(res[0]) == len(ans[0])
    assert (res[0][0] == ans[0][0]).all()


def test_E_K():
    fe_iii = aa.element.fe_iii

    assert fe_iii.E_K().shape == (1,)

    keys = [v.value for v in [
        fe_iii.STRUCTURE.LS_Ar_3d6_5D,
    ]]
    E = fe_iii.E_K()[keys]
    assert E == np.array([0.0])


def test_i():
    fe_iii = aa.element.fe_iii

    assert fe_iii.i() == 2.0


def test_Z():
    fe_iii = aa.element.fe_iii

    assert fe_iii.Z() == 26.0


def test_M():
    fe_iii = aa.element.fe_iii

    assert fe_iii.M() == 55.845


def test_I():
    fe_iii = aa.element.fe_iii

    assert fe_iii.I() == 30.59894486405585


def test_f_KK():
    fe_iii = aa.element.fe_iii

    assert (fe_iii.f_KK() == np.zeros((0, 0))).all()


def test_sigma_vs_nu_K():
    fe_iii = aa.element.fe_iii

    res = fe_iii.sigma_vs_nu_K()
    ans = [np.zeros((2, 0))]

    assert len(res) == len(ans)
    assert (res[0] == ans[0]).all()


def test_n():
    fe_iii = aa.element.fe_iii

    assert fe_iii.n_K().shape == (1,)

    keys = [v.value for v in [
        fe_iii.STRUCTURE.LS_Ar_3d6_5D,
    ]]
    n = fe_iii.n_K()[keys]
    assert n == np.array([3.0])


def test_g_K():
    fe_iii = aa.element.fe_iii

    assert fe_iii.g_K().shape == (1,)

    keys = [v.value for v in [
        fe_iii.STRUCTURE.LS_Ar_3d6_5D,
    ]]
    g = fe_iii.g_K()[keys]
    assert g == np.array([25.0])


def test_STRUCTURE():
    fe_iii = aa.element.fe_iii

    assert len(fe_iii.STRUCTURE.__members__) == 1
    assert fe_iii.STRUCTURE.LS_Ar_3d6_5D.value == 0