import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    o_i = aa.element.o_i

    Lambda_vs_T = o_i.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 1.12e-21
    assert Lambda_vs_T[1][-1] == 3.79e-18


def test_f_vs_T_KK():
    o_i = aa.element.o_i

    assert len(o_i.f_vs_T_KK()) == 51
    f_vs_T_KK_defined = o_i.f_vs_T_KK()[o_i.STRUCTURE.LS_He_2s2_2p4_1D.value][o_i.STRUCTURE.LS_He_2s2_2p4_1S.value]
    f_vs_T_KK_undefined = o_i.f_vs_T_KK()[o_i.STRUCTURE.LS_He_2s2_2p4_3P.value][o_i.STRUCTURE.LS_He_2s2_2p3_4So_9s_3So.value]
    assert (f_vs_T_KK_defined[0] == np.array([1000.0, 3000.0, 5000.0, 8000.0, 12000.0, 20000.0, 50000.0, 100000.0])).all()
    assert (f_vs_T_KK_defined[1] == np.array([5.551e-02, 7.164e-02, 8.830e-02, 1.068e-01, 1.247e-01, 1.494e-01, 2.135e-01, 2.798e-01])).all()
    assert f_vs_T_KK_undefined.shape == (2, 0)


def test_E_K():
    o_i = aa.element.o_i

    assert o_i.E_K().shape == (51,)

    keys = [v.value for v in [
        o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_3So,
    ]]
    E = o_i.E_K()[keys]
    assert E == np.array([9.511695728174285])


def test_i():
    o_i = aa.element.o_i

    assert o_i.i() == 0.0


def test_Z():
    o_i = aa.element.o_i

    assert o_i.Z() == 8.0


def test_M():
    o_i = aa.element.o_i

    assert o_i.M() == 16.0


def test_I():
    o_i = aa.element.o_i

    assert o_i.I() == 13.618055


def test_f_KK():
    o_i = aa.element.o_i

    assert o_i.f_KK().shape == (51, 51)

    keys = [v.value for v in [
        o_i.STRUCTURE.LS_He_2s2_2p4_3P,
        o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_3So,
    ]]
    f = o_i.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 0.5111E-1], [0.0, 0.0]])).all()


def test_sigma_vs_nu_K():
    o_i = aa.element.o_i

    assert len(o_i.sigma_vs_nu_K()) == 51

    keys = [v.value for v in [
        o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_3So,
    ]]
    sigma_vs_nu_K = [o_i.sigma_vs_nu_K()[key] for key in keys]
    assert sigma_vs_nu_K[0].shape == (2, 862)
    assert sigma_vs_nu_K[0][0][0] == 9.407321e+14
    assert sigma_vs_nu_K[0][1][0] == 1.098e-20


def test_n():
    o_i = aa.element.o_i

    assert o_i.n_K().shape == (51,)

    keys = [v.value for v in [
        o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_3So,
    ]]
    n = o_i.n_K()[keys]
    assert n == np.array([3.0])


def test_g_K():
    o_i = aa.element.o_i

    assert o_i.g_K().shape == (51,)

    keys = [v.value for v in [
        o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_3So,
    ]]
    g = o_i.g_K()[keys]
    assert g == np.array([3.0])


def test_STRUCTURE():
    o_i = aa.element.o_i

    assert len(o_i.STRUCTURE.__members__) == 51
    assert o_i.STRUCTURE.LS_He_2s2_2p4_3P.value == 0