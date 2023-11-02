import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    mg_i = aa.element.mg_i

    Lambda_vs_T = mg_i.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 9.12e-21
    assert Lambda_vs_T[1][-1] == 5.05e-17


def test_f_vs_T():
    mg_i = aa.element.mg_i

    assert len(mg_i.f_vs_T()) == 70
    f_vs_T_defined = mg_i.f_vs_T()[mg_i.STRUCTURE.LS_Ne_3s2_1S.value][mg_i.STRUCTURE.LS_Ne_3s_2S_3p_1Po.value]
    f_vs_T_undefined = mg_i.f_vs_T()[mg_i.STRUCTURE.LS_Ne_3s2_1S.value][mg_i.STRUCTURE.LS_Ne_3s_2S_16p_Ne_3s_2S_59p.value]
    assert (f_vs_T_defined[0] == np.array([500.0, 1000.0, 2000.0, 4000.0, 6000.0, 8000.0, 10000.0, 15000.0, 20000.0])).all()
    assert (f_vs_T_defined[1] == np.array([1.630E-02, 3.740E-02, 9.640E-02, 2.960E-01, 5.980E-01, 9.920E-01, 1.470E+00, 3.060E+00, 5.210E+00])).all()
    assert f_vs_T_undefined.shape == (2, 0)


def test_E():
    mg_i = aa.element.mg_i

    assert mg_i.E().shape == (70,)

    keys = [v.value for v in [
        mg_i.STRUCTURE.LS_Ne_3s_2S_4s_1S,
    ]]
    E = mg_i.E()[keys]
    assert E == np.array([5.392985082394041])


def test_i():
    mg_i = aa.element.mg_i

    assert mg_i.i() == 0.0


def test_Z():
    mg_i = aa.element.mg_i

    assert mg_i.Z() == 12.0


def test_M():
    mg_i = aa.element.mg_i

    assert mg_i.M() == 24.304


def test_I():
    mg_i = aa.element.mg_i

    assert mg_i.I() == 7.6451952529134


def test_f():
    mg_i = aa.element.mg_i

    assert mg_i.f().shape == (70, 70)

    keys = [v.value for v in [
        mg_i.STRUCTURE.LS_Ne_3s_2S_3p_3Po0,
        mg_i.STRUCTURE.LS_Ne_3p2_3P,
    ]]
    f = mg_i.f().T[keys].T[keys]
    assert (f == np.array([[0.0, 0.632], [0.0, 0.0]])).all()


def test_sigma_vs_nu():
    mg_i = aa.element.mg_i

    assert len(mg_i.sigma_vs_nu()) == 70

    keys = [v.value for v in [
        mg_i.STRUCTURE.LS_Ne_3s2_1S,
    ]]
    sigma_vs_nu = [mg_i.sigma_vs_nu()[key] for key in keys]
    assert sigma_vs_nu[0].shape == (2, 743)
    assert sigma_vs_nu[0][0][0] == 3.706485E+16
    assert sigma_vs_nu[0][1][0] == 2.678E-21


def test_g():
    mg_i = aa.element.mg_i

    assert mg_i.g().shape == (70,)

    keys = [v.value for v in [
        mg_i.STRUCTURE.LS_Ne_3s_2S_10d_Ne_3s_2S_15f,
    ]]
    g = mg_i.g()[keys]
    assert g == np.array([211.0])


def test_STRUCTURE():
    mg_i = aa.element.mg_i

    assert len(mg_i.STRUCTURE.__members__) == 70
    assert mg_i.STRUCTURE.LS_Ne_3s2_1S.value == 0