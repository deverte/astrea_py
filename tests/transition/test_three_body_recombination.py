import astrea as aa
import numpy as np
import pytest


def test_R_XZK():
    tbr = aa.transition.three_body_recombination
    o_i = aa.element.o_i
    o_ii = aa.element.o_ii

    T_X = np.array([1.0e4, 3.0e4])
    R_XZK = [
        [np.array([362.1178317114999]), np.array([0.0])],
        [np.array([0.0])],
    ]
    I_Z = np.array([o_i.I(), o_ii.I()])
    g_ZK = [
        np.array([9.0, 5.0]), # element=0 terms=[0, 1]
        np.array([4.0]), # element=1 terms=[0]
    ]
    E_ZK = [
        np.array([0.0, 9.15]), # element=0 terms=[0, 1]
        np.array([0.0]), # element=1 terms=[0]
    ]

    R = tbr.R_XZK(
        R_XZK=R_XZK,
        T_X=T_X,
        I_Z=I_Z,
        g_ZK=g_ZK,
        E_ZK=E_ZK,
    )
    assert (
        R[0][0] ==
            pytest.approx(np.array([1.2312489040204968e-12]), np.array([0.0]))
    )
    assert (R[0][1] == np.array([0.0])).all()