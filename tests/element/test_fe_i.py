import astrea as aa
import numpy as np


def test_Lambda_vs_T():
    fe_i = aa.element.fe_i

    Lambda_vs_T = fe_i.Lambda_vs_T()

    assert Lambda_vs_T.shape == (2, 189)
    assert Lambda_vs_T[0][0] == 1.00e+04
    assert Lambda_vs_T[0][-1] == 1.00e+08
    assert Lambda_vs_T[1][0] == 2.18e-20
    assert Lambda_vs_T[1][-1] == 9.92e-19


def test_f_vs_T_KK():
    fe_i = aa.element.fe_i

    assert len(fe_i.f_vs_T_KK()) == 239
    f_vs_T_KK_defined = fe_i.f_vs_T_KK()[fe_i.STRUCTURE.LS_Ar_3d6_4s2_a5D.value][fe_i.STRUCTURE.LS_Ar_3d7_4F_4s_a5F.value]
    f_vs_T_KK_undefined = fe_i.f_vs_T_KK()[fe_i.STRUCTURE.LS_Ar_3d6_4s2_a5D.value][fe_i.STRUCTURE.LS_Ar_3d6_3G_4s_4p_1Po_3Ho.value]
    assert (f_vs_T_KK_defined[0] == np.array([3000.0, 5000.0, 8000.0, 10000.0, 15000.0, 20000.0])).all()
    assert (f_vs_T_KK_defined[1] == np.array([0.5410E+01, 0.6387E+01, 0.6837E+01, 0.6963E+01, 0.7114E+01, 0.7159E+01])).all()
    assert f_vs_T_KK_undefined.shape == (2, 0)


def test_E_K():
    fe_i = aa.element.fe_i

    assert fe_i.E_K().shape == (239,)

    keys = [v.value for v in [
        fe_i.STRUCTURE.LS_Ar_3d6_4s2_b3F,
    ]]
    E = fe_i.E_K()[keys]
    assert E == np.array([2.5306005718242583])


def test_i():
    fe_i = aa.element.fe_i

    assert fe_i.i() == 0.0


def test_Z():
    fe_i = aa.element.fe_i

    assert fe_i.Z() == 26.0


def test_M():
    fe_i = aa.element.fe_i

    assert fe_i.M() == 55.845


def test_I():
    fe_i = aa.element.fe_i

    assert fe_i.I() == 7.852419912103682


def test_f_KK():
    fe_i = aa.element.fe_i

    assert fe_i.f_KK().shape == (239, 239)

    keys = [v.value for v in [
        fe_i.STRUCTURE.LS_Ar_3d7_4P_4s_a5P,
        fe_i.STRUCTURE.LS_Ar_3d6_3D_4s_4p_3Po_t5Po,
    ]]
    f = fe_i.f_KK().T[keys].T[keys]
    assert (f == np.array([[0.0, 0.149], [0.0, 0.0]])).all()


def test_sigma_vs_nu_K():
    fe_i = aa.element.fe_i

    assert len(fe_i.sigma_vs_nu_K()) == 239

    keys = [v.value for v in [
        fe_i.STRUCTURE.LS_Ar_3d7_2D2_4s_a1D,
    ]]
    sigma_vs_nu_K = [fe_i.sigma_vs_nu_K()[key] for key in keys]
    assert sigma_vs_nu_K[0].shape == (2, 1368)
    assert sigma_vs_nu_K[0][0][0] == 1.546450e+15
    assert sigma_vs_nu_K[0][1][0] == 7.516580e-19


def test_n():
    fe_i = aa.element.fe_i

    assert fe_i.n_K().shape == (239,)

    keys = [v.value for v in [
        fe_i.STRUCTURE.LS_Ar_3d6_5D_4s_6D_7s_7D,
    ]]
    n = fe_i.n_K()[keys]
    assert n == np.array([7.0])


def test_g_K():
    fe_i = aa.element.fe_i

    assert fe_i.g_K().shape == (239,)

    keys = [v.value for v in [
        fe_i.STRUCTURE.LS_Ar_3d6_4s2_a5D,
    ]]
    g = fe_i.g_K()[keys]
    assert g == np.array([25.0])


def test_STRUCTURE():
    fe_i = aa.element.fe_i

    assert len(fe_i.STRUCTURE.__members__) == 239
    assert fe_i.STRUCTURE.LS_Ar_3d6_4s2_a5D.value == 0