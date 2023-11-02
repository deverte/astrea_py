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


def test_E():
    c_iii = aa.element.c_iii

    assert c_iii.E().shape == (1,)

    keys = [v.value for v in [
        c_iii.STRUCTURE.LS_He_2s2_1S,
    ]]
    E = c_iii.E()[keys]
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


def test_g():
    c_iii = aa.element.c_iii

    assert c_iii.g().shape == (1,)

    keys = [v.value for v in [
        c_iii.STRUCTURE.LS_He_2s2_1S,
    ]]
    g = c_iii.g()[keys]
    assert g == np.array([1.0])


def test_STRUCTURE():
    c_iii = aa.element.c_iii

    assert len(c_iii.STRUCTURE.__members__) == 1
    assert c_iii.STRUCTURE.LS_He_2s2_1S.value == 0