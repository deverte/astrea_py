import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    h_i = aa.element.h_i

    Lambda_vs_T = h_i.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 4.59e-24
    assert Lambda_vs_T[1][-1] == 3.10e-19


def test_f_vs_T_KK():
    h_i = aa.element.h_i

    assert len(h_i.f_vs_T_KK()) == 19
    f_vs_T_KK_defined = h_i.f_vs_T_KK()[h_i.STRUCTURE.LS_1.value][h_i.STRUCTURE.LS_2.value]
    f_vs_T_KK_undefined = h_i.f_vs_T_KK()[h_i.STRUCTURE.LS_1.value][h_i.STRUCTURE.LS_8.value]
    assert (f_vs_T_KK_defined[0] == np.array([2500.0, 5000.0, 7500.0, 10000.0, 15000.0, 20000.0, 25000.0, 30000.0, 40000.0, 50000.0, 60000.0, 80000.0])).all()
    assert (f_vs_T_KK_defined[1] == np.array([0.640E+00, 0.698E+00, 0.757E+00, 0.809E+00, 0.897E+00, 0.978E+00, 0.106E+01, 0.115E+01, 0.132E+01, 0.151E+01, 0.168E+01, 0.202E+01])).all()
    assert f_vs_T_KK_undefined.shape == (2, 0)


def test_E_K():
    h_i = aa.element.h_i

    assert h_i.E_K().shape == (19,)

    keys = [v.value for v in [
        h_i.STRUCTURE.LS_4,
    ]]
    E = h_i.E_K()[keys]
    assert E == np.array([12.748539388262216])


def test_i():
    h_i = aa.element.h_i

    assert h_i.i() == 0.0


def test_Z():
    h_i = aa.element.h_i

    assert h_i.Z() == 1.0


def test_M():
    h_i = aa.element.h_i

    assert h_i.M() == 1.0


def test_I():
    h_i = aa.element.h_i

    assert h_i.I() == 13.598434599702


def test_A_H_sun():
    h_i = aa.element.h_i

    assert h_i.A_H_sun() == 1.0


def test_oscillator_strengths_doppler():
    h_i = aa.element.h_i

    assert h_i.oscillator_strengths_doppler.f_KK().shape == (19, 19)

    keys = [v.value for v in [
        h_i.STRUCTURE.LS_1,
        h_i.STRUCTURE.LS_15,
    ]]
    f = h_i.oscillator_strengths_doppler.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 0.468E-03], [0.0, 0.0]])).all()


def test_oscillator_strengths_stark():
    h_i = aa.element.h_i

    assert h_i.oscillator_strengths_stark.f_KK().shape == (19, 19)

    keys = [v.value for v in [
        h_i.STRUCTURE.LS_2,
        h_i.STRUCTURE.LS_7,
    ]]
    f = h_i.oscillator_strengths_stark.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 0.127E-01], [0.0, 0.0]])).all()


def test_n():
    h_i = aa.element.h_i

    assert h_i.n_K().shape == (19,)

    keys = [v.value for v in [
        h_i.STRUCTURE.LS_8,
    ]]
    n = h_i.n_K()[keys]
    assert n == np.array([8.0])


def test_g_K():
    h_i = aa.element.h_i

    assert h_i.g_K().shape == (19,)

    keys = [v.value for v in [
        h_i.STRUCTURE.LS_11,
    ]]
    g = h_i.g_K()[keys]
    assert g == np.array([242.0])


def test_STRUCTURE():
    h_i = aa.element.h_i

    assert len(h_i.STRUCTURE.__members__) == 19
    assert h_i.STRUCTURE.LS_10.value == 9