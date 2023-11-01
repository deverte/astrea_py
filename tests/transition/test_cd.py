import astrea as aa
import numpy as np
import pytest


def test_R():
    cd = aa.transition.cd

    T = np.array([1.0e4, 1.0e5]) # x=[0, 1]
    R_ij = [
        [ # x=0
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 4.24199422380423e-05],
                [0.0, 0.0],
            ]),
            np.zeros((1, 1)), # element=1 transitions=[[00]]
        ],
        [ # x 1
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 1.888227896211906e-01],
                [0.0, 0.0],
            ]),
            np.zeros((1, 1)), # element=1 transitions=[[00]]
        ],
    ]
    g = [
        np.array([9.0, 5.0]), # element=0 terms=[0, 1]
        np.array([4.0]), # element=1 terms=[0]
    ]
    E = [
        np.array([0.0, 9.15]), # element=0 terms=[0, 1]
        np.array([0.0]), # element=1 terms=[0]
    ]

    R_ji = cd.R(T=T, R=R_ij, g=g, E=E)

    expected = [
        [ # x=0
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 0.0],
                [3.1206108746162213, 0.0],
            ]),
            np.array([[0.0]]), # element=1 transitions=[[00]]
        ],
        [ # x=1
            np.array([ # element=0 transitions=[[00, 01], [10, 11]]
                [0.0, 0.0],
                [0.9828033283177673, 0.0],
            ]),
            np.array([[0.0]]), # element=1 transitions=[[00]]
        ],
    ]

    assert R_ji[0][0] == pytest.approx(expected[0][0])
    assert R_ji[0][1] == pytest.approx(expected[0][1])
    assert R_ji[1][0] == pytest.approx(expected[1][0])
    assert R_ji[1][1] == pytest.approx(expected[1][1])