import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    mg_ii = aa.element.mg_ii

    Lambda_vs_T = mg_ii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 3.11e-20
    assert Lambda_vs_T[1][-1] == 6.05e-19


def test_f_vs_T_KK():
    mg_ii = aa.element.mg_ii

    assert len(mg_ii.f_vs_T_KK()) == 43
    f_vs_T_KK_defined = mg_ii.f_vs_T_KK()[mg_ii.STRUCTURE.LS_Ne_3s_2S.value][mg_ii.STRUCTURE.LS_Ne_3p_2Po.value]
    f_vs_T_KK_undefined = mg_ii.f_vs_T_KK()[mg_ii.STRUCTURE.LS_Ne_3s_2S.value][mg_ii.STRUCTURE.LS_Ne_11g_2G.value]
    assert (f_vs_T_KK_defined[0] == np.array([1000.0, 3000.0, 5000.0, 10000.0, 20000.0, 30000.0])).all()
    assert (f_vs_T_KK_defined[1] == np.array([1.51E+1, 1.55E+1, 1.59E+1, 1.69E+1, 1.86E+1, 2.02E+1])).all()
    assert f_vs_T_KK_undefined.shape == (2, 0)


def test_E_K():
    mg_ii = aa.element.mg_ii

    assert mg_ii.E_K().shape == (43,)

    keys = [v.value for v in [
        mg_ii.STRUCTURE.LS_Ne_5s_2S,
    ]]
    E = mg_ii.E_K()[keys]
    assert E == np.array([11.503032903577648])


def test_i():
    mg_ii = aa.element.mg_ii

    assert mg_ii.i() == 1.0


def test_Z():
    mg_ii = aa.element.mg_ii

    assert mg_ii.Z() == 12.0


def test_M():
    mg_ii = aa.element.mg_ii

    assert mg_ii.M() == 24.304


def test_I():
    mg_ii = aa.element.mg_ii

    assert mg_ii.I() == 15.03327604684507


def test_f_KK():
    mg_ii = aa.element.mg_ii

    assert mg_ii.f_KK().shape == (43, 43)

    keys = [v.value for v in [
        mg_ii.STRUCTURE.LS_Ne_3p_2Po,
        mg_ii.STRUCTURE.LS_Ne_5s_2S,
    ]]
    f = mg_ii.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 1.817E-2], [0.0, 0.0]])).all()


def test_sigma_vs_nu_K():
    mg_ii = aa.element.mg_ii

    assert len(mg_ii.sigma_vs_nu_K()) == 43

    keys = [v.value for v in [
        mg_ii.STRUCTURE.LS_Ne_3s_2S,
    ]]
    sigma_vs_nu_K = [mg_ii.sigma_vs_nu_K()[key] for key in keys]
    assert sigma_vs_nu_K[0].shape == (2, 27)
    assert sigma_vs_nu_K[0][0][0] == 9.515160E+15
    assert sigma_vs_nu_K[0][1][0] == 1.570E-19


def test_g_K():
    mg_ii = aa.element.mg_ii

    assert mg_ii.g_K().shape == (43,)

    keys = [v.value for v in [
        mg_ii.STRUCTURE.LS_Ne_10h_Ne_10i,
    ]]
    g = mg_ii.g_K()[keys]
    assert g == np.array([48.0])


def test_STRUCTURE():
    mg_ii = aa.element.mg_ii

    assert len(mg_ii.STRUCTURE.__members__) == 43
    assert mg_ii.STRUCTURE.LS_Ne_3s_2S.value == 0