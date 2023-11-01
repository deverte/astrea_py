import astrea as aa
import numpy as np


def test_E():
    fe_iii = aa.element.fe_iii

    assert fe_iii.E().shape == (1,)

    keys = [v.value for v in [
        fe_iii.STRUCTURE.LS_Ar_3d6_5D,
    ]]
    E = fe_iii.E()[keys]
    assert E == np.array([0.0])


def test_i():
    fe_iii = aa.element.fe_iii

    assert fe_iii.i() == 2.0


def test_Z():
    fe_iii = aa.element.fe_iii

    assert fe_iii.Z() == 26.0


def test_M():
    fe_iii = aa.element.fe_iii

    assert fe_iii.M() == 55.845


def test_I():
    fe_iii = aa.element.fe_iii

    assert fe_iii.I() == 30.59894486405585


def test_n():
    fe_iii = aa.element.fe_iii

    assert fe_iii.n().shape == (1,)

    keys = [v.value for v in [
        fe_iii.STRUCTURE.LS_Ar_3d6_5D,
    ]]
    n = fe_iii.n()[keys]
    assert n == np.array([3.0])


def test_g():
    fe_iii = aa.element.fe_iii

    assert fe_iii.g().shape == (1,)

    keys = [v.value for v in [
        fe_iii.STRUCTURE.LS_Ar_3d6_5D,
    ]]
    g = fe_iii.g()[keys]
    assert g == np.array([25.0])


def test_STRUCTURE():
    fe_iii = aa.element.fe_iii

    assert len(fe_iii.STRUCTURE.__members__) == 1
    assert fe_iii.STRUCTURE.LS_Ar_3d6_5D.value == 0