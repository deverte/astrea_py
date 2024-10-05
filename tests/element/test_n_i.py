import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    n_i = aa.element.n_i

    Lambda_vs_T = n_i.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 2.88e-21
    assert Lambda_vs_T[1][-1] == 3.51e-18


def test_f_vs_T_KK():
    n_i = aa.element.n_i

    assert len(n_i.f_vs_T_KK()) == 59
    f_vs_T_KK_defined = n_i.f_vs_T_KK()[n_i.STRUCTURE.LS_He_2s2_2p3_4So.value][n_i.STRUCTURE.LS_He_2s2_2p3_2Do.value]
    f_vs_T_KK_undefined = n_i.f_vs_T_KK()[n_i.STRUCTURE.LS_He_2s2_2p3_4So.value][n_i.STRUCTURE._k12o.value]
    assert (f_vs_T_KK_defined[0] == np.array([5000.0, 8000.0, 11000.0, 14000.0, 17000.0, 20000.0, 23000.0, 26000.0, 29000.0, 32000.0, 35000.0, 38000.0, 41000.0, 44000.0, 47000.0])).all()
    assert (f_vs_T_KK_defined[1] == np.array([4.142e-11, 3.902e-10, 1.081e-09, 1.925e-09, 2.78e-09, 3.577e-09, 4.289e-09, 4.91e-09, 5.447e-09, 5.906e-09, 6.298e-09, 6.631e-09, 6.914e-09, 7.152e-09, 7.353e-09])).all()
    assert f_vs_T_KK_undefined.shape == (2, 0)


def test_E_K():
    n_i = aa.element.n_i

    assert n_i.E_K().shape == (59,)

    keys = [v.value for v in [
        n_i.STRUCTURE.LS_He_2s_2p4_4P,
    ]]
    E = n_i.E_K()[keys]
    assert E == np.array([10.927031077820594])


def test_i():
    n_i = aa.element.n_i

    assert n_i.i() == 0.0


def test_Z():
    n_i = aa.element.n_i

    assert n_i.Z() == 7.0


def test_M():
    n_i = aa.element.n_i

    assert n_i.M() == 14.0


def test_I():
    n_i = aa.element.n_i

    assert n_i.I() == 14.534134552992018


def test_f_KK():
    n_i = aa.element.n_i

    assert n_i.f_KK().shape == (59, 59)

    keys = [v.value for v in [
        n_i.STRUCTURE.LS_He_2s2_2p3_4So,
        n_i.STRUCTURE.LS_He_2s2_2p2_3P_12s_2P,
    ]]
    f = n_i.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 0.114E-01], [0.0, 0.0]])).all()


def test_sigma_vs_nu_K():
    n_i = aa.element.n_i

    assert len(n_i.sigma_vs_nu_K()) == 59

    keys = [v.value for v in [
        n_i.STRUCTURE.LS_He_2s2_2p2_3P_4s_2P,
    ]]
    sigma_vs_nu_K = [n_i.sigma_vs_nu_K()[key] for key in keys]
    assert sigma_vs_nu_K[0].shape == (2, 550)
    assert sigma_vs_nu_K[0][0][0] == 0.390620E+15
    assert sigma_vs_nu_K[0][1][0] == 0.390000E-17


def test_n():
    n_i = aa.element.n_i

    assert n_i.n_K().shape == (59,)

    keys = [v.value for v in [
        n_i.STRUCTURE._k11o,
    ]]
    n = n_i.n_K()[keys]
    assert n == np.array([11.0])


def test_g_K():
    n_i = aa.element.n_i

    assert n_i.g_K().shape == (59,)

    keys = [v.value for v in [
        n_i.STRUCTURE.LS_He_2s2_2p2_3P_4f_D,
    ]]
    g = n_i.g_K()[keys]
    assert g == np.array([136.0])


def test_STRUCTURE():
    n_i = aa.element.n_i

    assert len(n_i.STRUCTURE.__members__) == 59
    assert n_i.STRUCTURE.LS_He_2s2_2p3_4So.value == 0