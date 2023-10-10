import astrea as aa
import numpy as np


def test_i():
    o_i = aa.element.o_i_mashonkina

    assert o_i.i() == 0.0


def test_Z():
    o_i = aa.element.o_i_mashonkina

    assert o_i.Z() == 8.0


def test_M():
    o_i = aa.element.o_i_mashonkina

    assert o_i.M() == 16.0


def test_I():
    o_i = aa.element.o_i_mashonkina

    assert o_i.I() == 13.618055


def test_TERM():
    o_i = aa.element.o_i_mashonkina

    assert len(o_i.TERM.__members__) == 51
    assert o_i.TERM.LS_1s2_2s2_2p3_4So_3s_3So.value == 0


def test_E():
    o_i = aa.element.o_i_mashonkina

    assert o_i.E().shape == (51,)

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_3So,
    ]]
    E = o_i.E()[keys]
    assert E == np.array([9.511695728174285])


def test_n():
    o_i = aa.element.o_i_mashonkina

    assert o_i.n().shape == (51,)

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_3So,
    ]]
    n = o_i.n()[keys]
    assert n == np.array([3.0])


def test_g():
    o_i = aa.element.o_i_mashonkina

    assert o_i.g().shape == (51,)

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_3So,
    ]]
    g = o_i.g()[keys]
    assert g == np.array([3.0])


def test_A():
    o_i = aa.element.o_i_mashonkina

    assert o_i.A().shape == (51, 51)

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p4_1D,
        o_i.TERM.LS_1s2_2s2_2p4_3P,
    ]]
    A = o_i.A().T[keys].T[keys]
    assert (A == np.array([[0.0, 0.00149507], [0.0, 0.0]])).all()


def test_sigma_k():
    o_i = aa.element.o_i_mashonkina

    assert len(o_i.sigma_k()) == 51

    keys = [v.value for v in [
        o_i.TERM.LS_1s2_2s2_2p3_4So_3s_3So,
    ]]
    sigma_k = [o_i.sigma_k()[key] for key in keys]
    assert sigma_k[0].shape == (2, 862)
    assert sigma_k[0][0][0] == 9.407321e+14
    assert sigma_k[0][1][0] == 1.098e-20