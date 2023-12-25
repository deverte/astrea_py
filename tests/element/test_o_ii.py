import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    o_ii = aa.element.o_ii

    Lambda_vs_T = o_ii.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 3.88e-21
    assert Lambda_vs_T[1][-1] == 1.65e-18


def test_i():
    o_ii = aa.element.o_ii

    assert o_ii.i() == 1.0


def test_Z():
    o_ii = aa.element.o_ii

    assert o_ii.Z() == 8.0


def test_M():
    o_ii = aa.element.o_ii

    assert o_ii.M() == 16.0


def test_I():
    o_ii = aa.element.o_ii

    assert o_ii.I() == 35.12112


def test_STRUCTURE():
    o_ii = aa.element.o_ii

    assert len(o_ii.STRUCTURE.__members__) == 1
    assert o_ii.STRUCTURE.LS_He_2s2_2p3_4S.value == 0


def test_E():
    o_ii = aa.element.o_ii

    assert o_ii.E_K().shape == (1,)

    keys = [v.value for v in [
        o_ii.STRUCTURE.LS_He_2s2_2p3_4S,
    ]]
    E = o_ii.E_K()[keys]
    assert E == np.array([0.0])


def test_n():
    o_ii = aa.element.o_ii

    assert o_ii.n_K().shape == (1,)

    keys = [v.value for v in [
        o_ii.STRUCTURE.LS_He_2s2_2p3_4S,
    ]]
    n = o_ii.n_K()[keys]
    assert n == np.array([2.0])


def test_g():
    o_ii = aa.element.o_ii

    assert o_ii.g_K().shape == (1,)

    keys = [v.value for v in [
        o_ii.STRUCTURE.LS_He_2s2_2p3_4S,
    ]]
    g = o_ii.g_K()[keys]
    assert g == np.array([4.0])