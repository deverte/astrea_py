import astrea as aa
import numpy as np
import pytest


def test_cooling():
    _L = aa.cooling.L
    _La = aa.cooling.L_approximation
    o_i = aa.element.o_i

    T = np.geomspace(1.0e4, 1.0e5, 10) # C_vs_T and Lambda_vs_T intersection
    N_e = np.full(10, 1.0e3)
    N_A = np.full(10, 1.0e3)
    terms = np.array([
        o_i.STRUCTURE.LS_He_2s2_2p4_3P.value,
        o_i.STRUCTURE.LS_He_2s2_2p4_1D.value,
        o_i.STRUCTURE.LS_He_2s2_2p4_1S.value,
    ])
    E_z = o_i.E()[terms]
    g_z = o_i.g()[terms]
    C_vs_T = [[[o_i.C_vs_T()[i][j] for j in terms] for i in terms]]
    f = o_i.f().T[terms].T[terms]

    # Cooling rate calculation using NLTE
    C_ij = aa.transition.ce.R(T=T, N_e=N_e, C_vs_T=C_vs_T)
    C_ji = aa.transition.cd.R(T=T, R=C_ij, g=[g_z], E=[E_z])
    A_ji = aa.transition.rd.R(x=T, f=f, g=[g_z], E=[E_z])
    R_ij = C_ij
    R_ji = [[C_ji[x][0] + A_ji[x][0]] for x in range(len(T))]
    R_ik = [[np.zeros(3,)] for x in range(len(T))]
    R_ki = R_ik

    lte = aa.population.boltzmann_distribution.n(T=T, g=[g_z], E=[E_z])
    n = aa.population.balance_equation.n_t_plus_Delta_t(
        x=T,
        n_t=lte,
        R_ij=R_ij,
        R_ji=R_ji,
        R_ik=R_ik,
        R_ki=R_ki,
        Delta_t=6e2,
    )
    n_z = [n[x][0] for x in range(len(T))]

    R_z = [R_ji[i][0] + A_ji[i][0] for i in range(len(T))]
    L = _L(x=T, n_z=n_z, R_z=R_z, E_z=E_z)

    # Cooling rate approximation
    La = _La(Lambda_vs_T=o_i.Lambda_vs_T(), T=T, N_e=N_e, N_A=N_A)

    assert L == pytest.approx(La, abs=1e-12)