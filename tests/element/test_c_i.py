import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    c_i = aa.element.c_i

    Lambda_vs_T = c_i.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 6.60e-21
    assert Lambda_vs_T[1][-1] == 1.24e-18


def test_f_vs_T():
    c_i = aa.element.c_i

    assert len(c_i.f_vs_T()) == 158
    f_vs_T_defined = c_i.f_vs_T()[c_i.STRUCTURE.LS_He_2s2_2p2_3P0.value][c_i.STRUCTURE.LS_He_2s2_2p2_3P1.value]
    f_vs_T_undefined = c_i.f_vs_T()[c_i.STRUCTURE.LS_He_2s2_2p2_3P0.value][c_i.STRUCTURE.LS_He_2s2_2p_4d_3Do3.value]
    assert (f_vs_T_defined[0] == np.array([1000.0, 2500.0, 5000.0, 10000.0, 20000.0, 30000.0, 40000.0, 50000.0, 100000.0, 200000.0, 500000.0])).all()
    assert (f_vs_T_defined[1] == np.array([3.57E-02, 1.70E-01, 3.19E-01, 4.24E-01, 4.73E-01, 4.88E-01, 4.95E-01, 5.00E-01, 5.06E-01, 4.88E-01, 4.00E-01])).all()
    assert f_vs_T_undefined.shape == (2, 0)


def test_E():
    c_i = aa.element.c_i

    assert c_i.E_K().shape == (158,)

    keys = [v.value for v in [
        c_i.STRUCTURE.LS_He_2s_2p3_3Po,
    ]]
    E = c_i.E_K()[keys]
    assert E == np.array([9.33031440132414])


def test_i():
    c_i = aa.element.c_i

    assert c_i.i() == 0.0


def test_Z():
    c_i = aa.element.c_i

    assert c_i.Z() == 6.0


def test_M():
    c_i = aa.element.c_i

    assert c_i.M() == 12.0


def test_I():
    c_i = aa.element.c_i

    assert c_i.I() == 11.2601823623863


def test_f():
    c_i = aa.element.c_i

    assert c_i.f_KK().shape == (158, 158)

    keys = [v.value for v in [
        c_i.STRUCTURE.LS_He_2s2_2p_3s_3Po2,
        c_i.STRUCTURE.LS_He_2s2_2p_3p_3S1,
    ]]
    f = c_i.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 1.05E-01], [0.0, 0.0]])).all()


def test_sigma_vs_nu():
    c_i = aa.element.c_i

    assert len(c_i.sigma_vs_nu()) == 158

    keys = [v.value for v in [
        c_i.STRUCTURE.LS_He_2s2_2p2_3P0,
    ]]
    sigma_vs_nu = [c_i.sigma_vs_nu()[key] for key in keys]
    assert sigma_vs_nu[0].shape == (2, 555)
    assert sigma_vs_nu[0][0][0] == 3.289780E+17
    assert sigma_vs_nu[0][1][0] == 1.730E-20


def test_g():
    c_i = aa.element.c_i

    assert c_i.g_K().shape == (158,)

    keys = [v.value for v in [
        c_i.STRUCTURE.LS_He_2s_2p3_3Do,
    ]]
    g = c_i.g_K()[keys]
    assert g == np.array([15.0])


def test_STRUCTURE():
    c_i = aa.element.c_i

    assert len(c_i.STRUCTURE.__members__) == 158
    assert c_i.STRUCTURE.LS_He_2s2_2p2_3P0.value == 0