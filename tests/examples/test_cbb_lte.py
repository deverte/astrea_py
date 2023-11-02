import astrea as aa
import numpy as np
import pytest


def test_cbb_lte():
    lte = aa.population.boltzmann_distribution
    cd = aa.transition.cd
    ce = aa.transition.ce

    T = np.geomspace(1.0e3, 1.0e5, 10)
    N_e = np.geomspace(1.0e6, 1.0e9, 10)
    g = [np.array([9.0, 5.0])]
    E = [np.array([0.0, 9.15])]
    C_vs_T = [
        [ # element=0 (must use C from C_vs_T)
            [
                np.zeros((2, 0)), # transition=00
                np.array([ # transition=01
                    [1000.0, 3000.0, 5000.0, 8000.0, 12000.0, 20000.0, 50000.0, 100000.0],
                    [0.103E-54, 0.933E-24, 0.130E-17, 0.342E-14, 0.253E-12, 0.737E-11, 0.132E-09, 0.275E-09],
                ]),
            ],
            [
                np.zeros((2, 0)), # transition=10
                np.zeros((2, 0)), # transition=11
            ],
        ]
    ]

    R_ij = ce.R(T=T, N_e=N_e, C_vs_T=C_vs_T)
    R_ji = cd.R(T=T, R=R_ij, g=g, E=E)

    n_lte_0 = np.array([
        lte.n(T=T, g=g, E=E)[x][ion:=0][term:=0] for x in range(T.shape[0])
    ])
    n_nlte_0 = np.array([
        R_ji[x][ion:=0][j:=1][i:=0]
        / (R_ij[x][ion:=0][i:=0][j:=1] + R_ji[x][ion:=0][j:=1][i:=0])
        for x in range(T.shape[0])
    ])

    n_lte_1 = np.array([
        lte.n(T=T, g=g, E=E)[x][ion:=0][term:=1] for x in range(T.shape[0])
    ])
    n_nlte_1 = np.array([
        R_ij[x][ion:=0][i:=0][j:=1]
        / (R_ij[x][ion:=0][i:=0][j:=1] + R_ji[x][ion:=0][j:=1][i:=0])
        for x in range(T.shape[0])
    ])

    assert n_lte_0 + n_lte_1 == pytest.approx(1.0, abs=1e-12)
    assert n_nlte_0 + n_nlte_1 == pytest.approx(1.0, abs=1e-12)
    assert n_lte_0 == pytest.approx(n_nlte_0, abs=1e-12)
    assert n_lte_1 == pytest.approx(n_nlte_1, abs=1e-12)