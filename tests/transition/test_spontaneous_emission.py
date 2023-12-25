import astrea as aa
import numpy as np
import pytest


def test_R_XZKK():
    rd = aa.transition.spontaneous_emission

    x_X = np.array([0, 1])
    f_ZKK = [
        np.array([ # element=0 transitions=[[00, 01], [10, 11]]
            [0.0, 0.9599E-6],
            [0.0, 0.0],
        ]),
        np.array([[0.0]]), # element=1 transitions=[[00]]
    ]
    g_ZK = [
        np.array([9.0, 5.0]), # element=0 terms=[0, 1]
        np.array([4.0]), # element=1 terms=[0]
    ]
    E_ZK = [
        np.array([0.0, 9.15]), # element=0 terms=[0, 1]
        np.array([0.0]), # element=1 terms=[0]
    ]

    R_ji = rd.R_XZKK(x_X=x_X, f_ZKK=f_ZKK, g_ZK=g_ZK, E_ZK=E_ZK)

    expected = [
        [ # x=0
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 0.0],
                [6276.972673585006, 0.0],
            ]),
            np.array([[0.0]]), # element=1 transitions=[[00]]
        ],
        [ # x=1
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 0.0],
                [6276.972673585006, 0.0],
            ]),
            np.array([[0.0]]), # element=1 transitions=[[00]]
        ],
    ]

    assert R_ji[0][0] == pytest.approx(expected[0][0])
    assert R_ji[0][1] == pytest.approx(expected[0][1])
    assert R_ji[1][0] == pytest.approx(expected[1][0])
    assert R_ji[1][1] == pytest.approx(expected[1][1])