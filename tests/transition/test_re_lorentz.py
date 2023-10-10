import astrea as aa
import numpy as np
import pytest


def test_R_x_z_ij():
    re = aa.transition.re_lorentz

    g_z_i = 9.0
    g_z_j = 5.0
    E_z_ij = 9.15
    A_z_ji = 2780.00
    F_lambda = aa.spectrum.kelt_9_fossati.spectrum()
    F_lambda[1] = F_lambda[1] / 0.03**2

    R = re.R_x_z_ij(
        g_z_i=g_z_i,
        g_z_j=g_z_j,
        E_z_ij=E_z_ij,
        A_z_ji=A_z_ji,
        F_lambda=F_lambda,
    )
    assert R == 0.0026569719823126494


def test_R_x_z():
    re = aa.transition.re_lorentz

    g_z = np.array([9.0, 5.0])
    E_z = np.array([0.0, 9.15])
    A_z = np.array([[0.0, 0.0], [2780.00, 0.0]])
    F_lambda = aa.spectrum.kelt_9_fossati.spectrum()
    F_lambda[1] = F_lambda[1] / 0.03**2

    R = re.R_x_z(g_z=g_z, E_z=E_z, A_z=A_z, F_lambda=F_lambda)
    assert (
        R ==
            pytest.approx(np.array([[0.0, 0.0026569719823126494], [0.0, 0.0]]))
    )


def test_R_x():
    re = aa.transition.re_lorentz

    g = [np.array([9.0, 5.0]), np.array([4.0])]
    E = [np.array([0.0, 9.15]), np.array([0.0])]
    A = [np.array([[0.0, 0.0], [2780.00, 0.0]]), np.array([0.0])]
    F_lambda = aa.spectrum.kelt_9_fossati.spectrum()
    F_lambda[1] = F_lambda[1] / 0.03**2

    R = re.R_x(g=g, E=E, A=A, F_lambda=F_lambda)
    assert (
        R[0] ==
            pytest.approx(np.array([[0.0, 0.0026569719823126494], [0.0, 0.0]]))
    )
    assert (R[1] == np.array([0.0])).all()