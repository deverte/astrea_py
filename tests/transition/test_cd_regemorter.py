import astrea as aa
import numpy as np


def test_R_x_z_ji():
    cd = aa.transition.cd_regemorter

    g_z_j = 9.0
    T_x = 1.0e3
    N_e_x = 1.0

    R = cd.R_x_z_ji(g_z_j=g_z_j, T_x=T_x, N_e_x=N_e_x)
    assert R == 3.031967965957346e-08


def test_R_x_z():
    cd = aa.transition.cd_regemorter

    g_z = np.array([9.0, 5.0])
    T_x = 1.0e3
    N_e_x = 1.0

    R = cd.R_x_z(g_z=g_z, T_x=T_x, N_e_x=N_e_x)
    assert (R == np.array([[0.0, 0.0], [5.457542338723223e-08, 0.0]])).all()


def test_R_x():
    cd = aa.transition.cd_regemorter

    g = [np.array([9.0, 5.0]), np.array([4.0])]
    T_x = 1.0e3
    N_e_x = 1.0

    R = cd.R_x(g=g, T_x=T_x, N_e_x=N_e_x)
    assert (R[0] == np.array([[0.0, 0.0], [5.457542338723223e-08, 0.0]])).all()
    assert (R[1] == np.array([0.0])).all()