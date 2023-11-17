import astrea as aa
import numpy as np
import pytest


def test_cooling():
    L = aa.cooling.cooling_rate.L_X
    La = aa.cooling.cooling_rate_approximation.L_X
    o_i = aa.element.o_i

    T_X = np.geomspace(1.0e4, 1.0e5, 10) # C_vs_T and Lambda_vs_T intersection
    N_e_X = np.full(10, 1.0e3)
    N_A_X = np.full(10, 1.0e3)
    terms = np.array([
        o_i.STRUCTURE.LS_He_2s2_2p4_3P.value,
        o_i.STRUCTURE.LS_He_2s2_2p4_1D.value,
        o_i.STRUCTURE.LS_He_2s2_2p4_1S.value,
    ])
    E_K = o_i.E()[terms]
    g_K = o_i.g()[terms]
    C_vs_T_ZKK = [[[o_i.C_vs_T()[i][j] for j in terms] for i in terms]]
    f_ZKK = o_i.f().T[terms].T[terms]

    # Cooling rate calculation using NLTE
    C_ij = aa.transition.ce.R_XZKK(T_X=T_X, N_e_X=N_e_X, C_vs_T_ZKK=C_vs_T_ZKK)
    C_ji = aa.transition.cd.R_XZKK(T_X=T_X, R_XZKK=C_ij, g_ZK=[g_K], E_ZK=[E_K])
    A_ji = aa.transition.rd.R_XZKK(x_X=T_X, f_ZKK=f_ZKK, g_ZK=[g_K], E_ZK=[E_K])
    R_ij = C_ij
    R_ji = [[C_ji[x][0] + A_ji[x][0]] for x in range(len(T_X))]
    R_ik = [[np.zeros(3,)] for x in range(len(T_X))]
    R_ki = R_ik

    lte = aa.population.boltzmann_distribution.n_XZK(T_X=T_X, g_ZK=[g_K], E_ZK=[E_K])
    n = aa.population.balance_equation.n_t_plus_Delta_t_XZK(
        x_X=T_X,
        n_t_XZK=lte,
        R_ij_XZKK=R_ij,
        R_ji_XZKK=R_ji,
        R_ik_XZK=R_ik,
        R_ki_XZK=R_ki,
        Delta_t=6e2,
    )
    n_XK = [n[x][0] for x in range(len(T_X))]

    R_XKK = [R_ji[i][0] + A_ji[i][0] for i in range(len(T_X))]
    L = L(x_X=T_X, n_XK=n_XK, R_XKK=R_XKK, E_K=E_K)

    # Cooling rate approximation
    La = La(Lambda_vs_T=o_i.Lambda_vs_T(), T_X=T_X, N_e_X=N_e_X, N_A_X=N_A_X)

    assert L == pytest.approx(La, abs=1e-12)