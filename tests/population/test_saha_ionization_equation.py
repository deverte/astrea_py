import astrea as aa
import pytest
import numpy as np


def test_Sigma_Z():
    Sigma_Z = aa.population.saha_ionization_equation.Sigma_Z

    T = 1.0e4
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    s_Z = Sigma_Z(T=T, g_ZK=g_ZK, E_ZK=E_ZK)

    assert s_Z == pytest.approx([9.00012234126441, 4.0])


def test_Phi_Z():
    Phi_Z = aa.population.saha_ionization_equation.Phi_Z

    T = 1.0e4
    I_Z = np.array([13.6, 35.1])
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    p_Z = Phi_Z(T=T, I_Z=I_Z, g_ZK=g_ZK, E_ZK=E_ZK)

    assert p_Z == pytest.approx([3.3296349856136935e-15, 0.0])


def test_Pi_Z():
    Pi_Z = aa.population.saha_ionization_equation.Pi_Z

    T = 1.0e4
    N_e = 1.0e8
    I_Z = np.array([13.6, 26.5])
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    p_Z = Pi_Z(T=T, N_e=N_e, I_Z=I_Z, g_ZK=g_ZK, E_ZK=E_ZK)

    assert p_Z == pytest.approx([3.79e-320, 0.0])


def test_Sigma_Pi():
    Sigma_Pi = aa.population.saha_ionization_equation.Sigma_Pi

    T = 1.0e4
    N_e = 1.0e8
    I_Z = np.array([13.6, 26.5])
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    s_Z = Sigma_Pi(T=T, N_e=N_e, I_Z=I_Z, g_ZK=g_ZK, E_ZK=E_ZK)

    assert s_Z == pytest.approx(3.7994e-320)


def test_N_Z():
    N_Z = aa.population.saha_ionization_equation.N_Z

    T = 1.0e4
    N_e = 1.0e8
    I_Z = np.array([13.6, 26.5])
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    n_Z = N_Z(T=T, N_e=N_e, I_Z=I_Z, g_ZK=g_ZK, E_ZK=E_ZK)

    assert n_Z == pytest.approx([1.0, 0.0])


def test_n_ZK():
    saha_ionization_equation = aa.population.saha_ionization_equation.n_ZK

    n_ZK = [np.array([0.3, 0.7]), np.array([1.0])]
    T = 1.0e4
    N_e = 1.0e8
    I_Z = np.array([13.6, 26.5])
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    n_ZK = saha_ionization_equation(
        n_ZK=n_ZK,
        T=T,
        N_e=N_e,
        I_Z=I_Z,
        g_ZK=g_ZK,
        E_ZK=E_ZK,
    )

    assert n_ZK[0] == pytest.approx(np.array([0.3, 0.7]))
    assert n_ZK[1] == pytest.approx(np.array([1.0]))


def test_n_XZK():
    saha_ionization_equation = aa.population.saha_ionization_equation.n_XZK

    n_XZK = [
        [np.array([0.3, 0.7]), np.array([1.0])],
        [np.array([0.3, 0.7]), np.array([1.0])],
    ]
    T_X = np.array([1.0e4, 1.0e5])
    N_e_X = np.array([1.0e8, 3.0e8])
    I_Z = np.array([13.6, 26.5])
    g_ZK = [np.array([9.0, 5.0]), np.array([4.0])]
    E_ZK = [np.array([0.0, 9.15]), np.array([0.0])]

    n_XZK = saha_ionization_equation(
        n_XZK=n_XZK,
        T_X=T_X,
        N_e_X=N_e_X,
        I_Z=I_Z,
        g_ZK=g_ZK,
        E_ZK=E_ZK,
    )

    assert n_XZK[0][0] == pytest.approx(np.array([0.3, 0.7]))
    assert n_XZK[0][1] == pytest.approx(np.array([1.0]))
    assert n_XZK[1][0] == pytest.approx(np.array([0.3, 0.7]))
    assert n_XZK[1][1] == pytest.approx(np.array([1.0]))