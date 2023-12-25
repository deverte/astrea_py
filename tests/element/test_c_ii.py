import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    c_ii = aa.element.c_ii

    Lambda_vs_T = c_ii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 1.60e-21
    assert Lambda_vs_T[1][-1] == 1.19e-18


def test_f_vs_T():
    c_ii = aa.element.c_ii

    assert len(c_ii.f_vs_T()) == 77
    f_vs_T_defined = c_ii.f_vs_T()[c_ii.STRUCTURE.LS_He_2s2_2p_2Po.value][c_ii.STRUCTURE.LS_He_2s_2p2_4P2.value]
    f_vs_T_undefined = c_ii.f_vs_T()[c_ii.STRUCTURE.LS_He_2s2_2p_2Po.value][c_ii.STRUCTURE.LS_He_2s_2p_3Po_3d_4Do8.value]
    assert (f_vs_T_defined[0] == np.array([1000.0, 1780.0, 3160.0, 5620.0, 10000.0, 17780.0, 31622.0, 56230.0, 100000.0, 177830.0, 316230.0])).all()
    assert (f_vs_T_defined[1] == np.array([0.229E+00, 0.230E+00, 0.231E+00, 0.229E+00, 0.228E+00, 0.228E+00, 0.221E+00, 0.205E+00, 0.181E+00, 0.154E+00, 0.126E+00])).all()
    assert f_vs_T_undefined.shape == (2, 0)


def test_E():
    c_ii = aa.element.c_ii

    assert c_ii.E_K().shape == (77,)

    keys = [v.value for v in [
        c_ii.STRUCTURE.LS_He_2s2_3s_2S,
    ]]
    E = c_ii.E_K()[keys]
    assert E == np.array([14.447541434884599])


def test_i():
    c_ii = aa.element.c_ii

    assert c_ii.i() == 1.0


def test_Z():
    c_ii = aa.element.c_ii

    assert c_ii.Z() == 6.0


def test_M():
    c_ii = aa.element.c_ii

    assert c_ii.M() == 12.0


def test_I():
    c_ii = aa.element.c_ii

    assert c_ii.I() == 24.3793473419881


def test_f():
    c_ii = aa.element.c_ii

    assert c_ii.f_KK().shape == (77, 77)

    keys = [v.value for v in [
        c_ii.STRUCTURE.LS_He_2s_2p2_2D,
        c_ii.STRUCTURE.LS_He_2s2_3p_2Po,
    ]]
    f = c_ii.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 1.71E-2], [0.0, 0.0]])).all()


def test_sigma_vs_nu():
    c_ii = aa.element.c_ii

    assert len(c_ii.sigma_vs_nu()) == 77

    keys = [v.value for v in [
        c_ii.STRUCTURE.LS_He_2s_2p2_4P2,
    ]]
    sigma_vs_nu = [c_ii.sigma_vs_nu()[key] for key in keys]
    assert sigma_vs_nu[0].shape == (2, 166)
    assert sigma_vs_nu[0][0][0] == 5.113240E+16
    assert sigma_vs_nu[0][1][0] == 2.650E-20


def test_g():
    c_ii = aa.element.c_ii

    assert c_ii.g_K().shape == (77,)

    keys = [v.value for v in [
        c_ii.STRUCTURE.LS_He_2s_2p2_2D,
    ]]
    g = c_ii.g_K()[keys]
    assert g == np.array([10.0])


def test_STRUCTURE():
    c_ii = aa.element.c_ii

    assert len(c_ii.STRUCTURE.__members__) == 77
    assert c_ii.STRUCTURE.LS_He_2s2_2p_2Po.value == 0