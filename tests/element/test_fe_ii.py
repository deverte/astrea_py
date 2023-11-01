import astrea as aa
import numpy as np


def test_f_vs_T():
    fe_ii = aa.element.fe_ii

    assert len(fe_ii.f_vs_T()) == 89
    f_vs_T_defined = fe_ii.f_vs_T()[fe_ii.STRUCTURE.LS_Ar_3d6_5D_4s_a6D.value][fe_ii.STRUCTURE.LS_Ar_3d7_a4F.value]
    f_vs_T_undefined = fe_ii.f_vs_T()[fe_ii.STRUCTURE.LS_Ar_3d6_5D_4s_a6D.value][fe_ii.STRUCTURE.LS_Ar_3d6_5D_5s_e4D.value]
    assert (f_vs_T_defined[0] == np.array([1000.0, 2000.0, 3000.0, 5000.0, 7000.0, 9000.0, 10000.0, 12000.0, 15000.0, 17000.0, 20000.0])).all()
    assert (f_vs_T_defined[1] == np.array([0.179E+01, 0.175E+01, 0.173E+01, 0.168E+01, 0.164E+01, 0.162E+01, 0.161E+01, 0.160E+01, 0.159E+01, 0.159E+01, 0.157E+01])).all()
    assert f_vs_T_undefined.shape == (2, 0)


def test_E():
    fe_ii = aa.element.fe_ii

    assert fe_ii.E().shape == (89,)

    keys = [v.value for v in [
        fe_ii.STRUCTURE.LS_Ar_3d7_a2D2,
    ]]
    E = fe_ii.E()[keys]
    assert E == np.array([2.531395033583473])


def test_i():
    fe_ii = aa.element.fe_ii

    assert fe_ii.i() == 1.0


def test_Z():
    fe_ii = aa.element.fe_ii

    assert fe_ii.Z() == 26.0


def test_M():
    fe_ii = aa.element.fe_ii

    assert fe_ii.M() == 55.845


def test_I():
    fe_ii = aa.element.fe_ii

    assert fe_ii.I() == 16.13507622678080


def test_f():
    fe_ii = aa.element.fe_ii

    assert fe_ii.f().shape == (89, 89)

    keys = [v.value for v in [
        fe_ii.STRUCTURE.LS_Ar_3d6_5D_4s_a6D,
        fe_ii.STRUCTURE.LS_Ar_3d5_6S_4s_4p_1Po_x6Po,
    ]]
    f = fe_ii.f().T[keys].T[keys]
    assert (f == np.array([[0.0, 0.1980E-01], [0.0, 0.0]])).all()


def test_n():
    fe_ii = aa.element.fe_ii

    assert fe_ii.n().shape == (89,)

    keys = [v.value for v in [
        fe_ii.STRUCTURE.LS_Ar_3d6_5D_5s_e6D,
    ]]
    n = fe_ii.n()[keys]
    assert n == np.array([5.0])


def test_g():
    fe_ii = aa.element.fe_ii

    assert fe_ii.g().shape == (89,)

    keys = [v.value for v in [
        fe_ii.STRUCTURE.LS_Ar_3d6_5D_4s_a6D,
    ]]
    g = fe_ii.g()[keys]
    assert g == np.array([30.0])


def test_STRUCTURE():
    fe_ii = aa.element.fe_ii

    assert len(fe_ii.STRUCTURE.__members__) == 89
    assert fe_ii.STRUCTURE.LS_Ar_3d6_5D_4s_a6D.value == 0