import astrea as aa
import numpy as np
import pytest


def test_R_XZK():
    ci = aa.transition.collisional_ionization
    P_v_X = aa.math.maxwell_boltzmann_distribution.P_v_X
    o_i = aa.element.o_i

    keys = [v.value for v in [
        o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_5So,
    ]]

    c = 2.99792458e5 # km s-1
    m_i = o_i.M() * 938.2720881629e6 / c**2 # eV s km-1

    sigma_vs_nu_ZK = [
        [o_i.sigma_vs_nu_K()[key] for key in keys],
        [np.array([[0.0], [0.0]])],
    ]
    sigma_vs_v_ZK = sigma_vs_nu_ZK
    for z in range(len(sigma_vs_nu_ZK)):
        sigma_vs_v_ZK[z][0] = sigma_vs_nu_ZK[z][0]

    E_ZK = [
        np.array([0.0, 9.15]), # element=0 terms=[0, 1]
        np.array([0.0]), # element=1 terms=[0]
    ]
    v_ZK = [np.sqrt(2.0 * E_K / m_i) for E_K in E_ZK]

    T_X = np.array([1.0e3, 1.0e4])
    v_X = np.array([9.17, 9.8])
    N_e_X = np.array([1.0e8, 1.0e9]) # x=[0, 1]

    f_vs_v = P_v_X(v_X=v_X, T_X=T_X, m=m_i)

    R = ci.R_XZK(
        sigma_vs_v_ZK=sigma_vs_v_ZK,
        f_vs_v=f_vs_v,
        v_ZK=v_ZK,
        N_e_X=N_e_X,
    )
    assert R[0][0] == pytest.approx(np.array([2.39380246e-60]))
    assert (R[0][1] == np.array([0.0])).all()