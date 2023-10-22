import astrea as aa
import numpy as np
import pytest


def test_R():
    rd = aa.transition.rd

    A = [
        np.array([ # element=0
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9],
        ])
    ]

    T = np.array([1.0e3, 1.0e4]) # x=[0, 1]

    R_ji = rd.R(x=T, A=A)

    expected = [
        [ # x = 0
            np.array([ # element=0
                [1, 2, 3],
                [4, 5, 6],
                [7, 8, 9],
            ]),
        ],
        [ # x = 1
            np.array([ # element=0
                [1, 2, 3],
                [4, 5, 6],
                [7, 8, 9],
            ]),
        ],
    ]
    assert R_ji[0][0] == pytest.approx(expected[0][0])
    assert R_ji[1][0] == pytest.approx(expected[1][0])