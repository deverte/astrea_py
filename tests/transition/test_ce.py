import astrea as aa
import numpy as np
import pytest


def test_R():
    ce = aa.transition.ce

    T = np.array([1.2e4, 2.0e4]) # x=[0, 1]
    N_e = np.array([1.0e8, 1.0e9]) # x=[0, 1]
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
        ],
        [ # element=1 (must use C = 0)
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

    R_ij = ce.R(T=T, N_e=N_e, C_vs_T=C_vs_T)

    expected = [
        [ # x=0
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 2.53e-05],
                [0.0, 0.0],
            ]),
            np.array([ # element=1 transitions=[[00, 01], [10, 11]]
                [0.0, 0.0],
                [0.0, 0.0],
            ]),
            np.array([[0.0]]), # element=2 transitions=[[00]]
        ],
        [ # x=1
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 0.00737],
                [0.0, 0.0],
            ]),
            np.array([ # element=1 transitions=[[00, 01], [10, 11]]
                [0.0, 0.0],
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