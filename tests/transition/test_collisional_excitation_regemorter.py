import astrea as aa
import numpy as np
import pytest


def test_R_XZKK():
    ce = aa.transition.collisional_excitation_regemorter

    T_X = np.array([1.0e4, 2.0e4]) # x=[0, 1]
    N_e_X = np.array([1.0e8, 1.0e9]) # x=[0, 1]
    g_ZK = [
        np.array([9.0, 5.0]), # element=0 terms=[0, 1]
        np.array([9.0, 5.0]), # element=1 terms=[0, 1]
        np.array([4.0]), # element=2 terms=[0]
    ]
    E_ZK = [
        np.array([0.0, 9.15]), # element=0 terms=[0, 1]
        np.array([0.0, 9.15]), # element=1 terms=[0, 1]
        np.array([0.0]), # element=1 terms=[0]
    ]
    f_vs_T_ZKK = [
        [ # element=0 (must use f from f_vs_T)
            [
                np.zeros((2, 0)), # transition=00
                np.array([ # transition=01
                    [500.0, 1000.0, 2000.0, 4000.0, 6000.0, 8000.0, 10000.0, 15000.0, 20000.0],
                    [1.630E-02, 3.740E-02, 9.640E-02, 2.960E-01, 5.980E-01, 9.920E-01, 1.470E+00, 3.060E+00, 5.210E+00],
                ]),
            ],
            [
                np.zeros((2, 0)), # transition=10
                np.zeros((2, 0)), # transition=11
            ],
        ],
        [ # element=1 (must use f = 1)
            [
                np.zeros((2, 0)), # transition=00
                np.zeros((2, 0)), # transition=01
            ],
            [
                np.zeros((2, 0)), # transition=10
                np.zeros((2, 0)), # transition=11
            ],
        ],
        [ # element=2
            [
                np.zeros((2, 0)), # transition=00
            ],
        ],
    ]

    R_ij = ce.R_XZKK(
        T_X=T_X,
        N_e_X=N_e_X,
        g_ZK=g_ZK,
        E_ZK=E_ZK,
        f_vs_T_ZKK=f_vs_T_ZKK,
    )

    expected = [
        [ # x=0
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 3.448616514314352e-05],
                [0.0, 0.0],
            ]),
            np.array([ # element=1 transitions=[[00, 01], [10, 11]]
                [0.0, 2.3459976287852736e-05],
                [0.0, 0.0],
            ]),
            np.array([[0.0]]), # element=2 transitions=[[00]]
        ],
        [ # x=1
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 0.17472249154525513],
                [0.0, 0.0],
            ]),
            np.array([ # element=1 transitions=[[00, 01], [10, 11]]
                [0.0, 0.0335359868608935],
                [0.0, 0.0],
            ]),
            np.array([[0.0]]), # element=2 transitions=[[00]]
        ],
    ]
    assert R_ij[0][0] == pytest.approx(expected[0][0])
    assert R_ij[0][1] == pytest.approx(expected[0][1])
    assert R_ij[0][2] == pytest.approx(expected[0][2])
    assert R_ij[1][0] == pytest.approx(expected[1][0])
    assert R_ij[1][1] == pytest.approx(expected[1][1])
    assert R_ij[1][2] == pytest.approx(expected[1][2])