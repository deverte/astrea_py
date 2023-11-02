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


def test_E():
    mg_iii = aa.element.mg_iii

    assert mg_iii.E().shape == (1,)

    keys = [v.value for v in [
        mg_iii.STRUCTURE.LS_Ne_1S,
    ]]
    E = mg_iii.E()[keys]
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


def test_g():
    mg_iii = aa.element.mg_iii

    assert mg_iii.g().shape == (1,)

    keys = [v.value for v in [
        mg_iii.STRUCTURE.LS_Ne_1S,
    ]]
    g = mg_iii.g()[keys]
    assert g == np.array([1.0])


def test_STRUCTURE():
    mg_iii = aa.element.mg_iii

    assert len(mg_iii.STRUCTURE.__members__) == 1
    assert mg_iii.STRUCTURE.LS_Ne_1S.value == 0