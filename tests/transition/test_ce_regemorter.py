import astrea as aa
import numpy as np
import pytest


def test_R_x_z_ij():
    ce = aa.transition.ce_regemorter

    g_z_i = 5.0
    E_z_ij = 9.15
    T_x = 1.0e3
    N_e_x = 1.0

    R = ce.R_x_z_ij(g_z_i=g_z_i, E_z_ij=E_z_ij, T_x=T_x, N_e_x=N_e_x)
    assert R == 4.197848075720598e-54


def test_R_x_z():
    ce = aa.transition.ce_regemorter

    g_z = np.array([9.0, 5.0])
    E_z = np.array([0.0, 9.15])
    T_x = 1.0e3
    N_e_x = 1.0

    R = ce.R_x_z(g_z=g_z, E_z=E_z, T_x=T_x, N_e_x=N_e_x)
    assert (
        R == pytest.approx(np.array([[0.0, 2.332137819844777e-54], [0.0, 0.0]]))
    )


def test_R_x():
    ce = aa.transition.ce_regemorter

    g = [np.array([9.0, 5.0]), np.array([4.0])]
    E = [np.array([0.0, 9.15]), np.array([0.0])]
    T_x = 1.0e3
    N_e_x = 1.0

    R = ce.R_x(g=g, E=E, T_x=T_x, N_e_x=N_e_x)
    assert (
        R[0] ==
            pytest.approx(np.array([[0.0, 2.332137819844777e-54], [0.0, 0.0]]))
    )
    assert (R[1] == np.array([0.0])).all()