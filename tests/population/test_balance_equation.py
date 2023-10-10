import astrea as aa
import pytest
import numpy as np


def test_Q_x():
    nlte = aa.population.balance_equation

    S_x = np.array([
        [1.0, 2.0, 3.0],
        [4.0, 5.0, 6.0],
        [7.0, 8.0, 9.0],
    ])

    Q_x_ = np.array([
        [-5.0, 4.0, 7.0],
        [2.0, -10.0, 8.0],
        [3.0, 6.0, -15.0],
    ])

    Q_x = nlte.Q_x(S_x=S_x)
    assert (Q_x == Q_x_).all()


def test_P_x():
    nlte = aa.population.balance_equation

    Q_x = np.array([
        [5.0, 4.0, 7.0],
        [2.0, 10.0, 8.0],
        [3.0, 6.0, 15.0],
    ])
    Delta_t = 1.0e1

    P_x_ = np.array([
        [-0.02922476, 0.00516888, 0.01095451],
        [0.001703382388788219, -0.01527464, 0.0074009],
        [0.00519825, 0.00511015, -0.01189724],
    ])

    P_x = nlte.P_x(Q_x=Q_x, Delta_t=Delta_t)
    assert P_x == pytest.approx(P_x_)


def test_p_x_t_plus_Delta_t():
    nlte = aa.population.balance_equation

    p_x_t = np.array([1.0, 2.0, 3.0])
    P_x = np.array([
        [-0.02922476, 0.00516888, 0.01095451],
        [0.001703382388788219, -0.01527464, 0.0074009],
        [0.00519825, 0.00511015, -0.01189724],
    ])

    p_x_t_plus_Delta_t_ = np.array(
        [0.013976530000000001, -0.0066431976112117826, -0.020273169999999997],
    )

    p_x_t_plus_Delta_t = nlte.p_x_t_plus_Delta_t(p_x_t=p_x_t, P_x=P_x)
    assert p_x_t_plus_Delta_t == pytest.approx(p_x_t_plus_Delta_t_)


def test_p_x_t():
    nlte = aa.population.balance_equation

    n_x_t = [np.array([1.0, 2.0]), np.array([3.0, 4.0, 5.0]), np.array([6.0])]

    p_x_t_ = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0])

    p_x_t = nlte.p_x_t(n_x_t=n_x_t)
    assert p_x_t == pytest.approx(p_x_t_)


def test_S_x():
    nlte = aa.population.balance_equation

    R_x_ij = [
        np.array([
            [0.0, 1.0],
            [0.0, 0.0],
        ]),
        np.array([
            [0.0, 2.0, 3.0],
            [0.0, 0.0, 4.0],
            [0.0, 0.0, 0.0],
        ]),
        np.array([[0.0]]),
    ]
    R_x_ji = [
        np.array([
            [0.0, 0.0],
            [5.0, 0.0],
        ]),
        np.array([
            [0.0, 0.0, 0.0],
            [6.0, 0.0, 0.0],
            [7.0, 8.0, 0.0],
        ]),
        np.array([[0.0]]),
    ]
    R_x_ik = [
        np.array([9.0, 10.0]),
        np.array([11.0, 12.0, 13.0]),
        np.array([14.0]),
    ]
    R_x_ki = [
        np.array([15.0, 16.0]),
        np.array([17.0, 18.0, 19.0]),
        np.array([20.0]),
    ]

    S_x_ = np.array([
        [ 0.0,  1.0,  9.0,  0.0,  0.0,  0.0],
        [ 5.0,  0.0, 10.0,  0.0,  0.0,  0.0],
        [15.0, 16.0,  0.0,  2.0,  3.0, 11.0],
        [ 0.0,  0.0,  6.0,  0.0,  4.0, 12.0],
        [ 0.0,  0.0,  7.0,  8.0,  0.0, 13.0],
        [ 0.0,  0.0, 17.0, 18.0, 19.0,  0.0],
    ])

    S_x = nlte.S_x(R_x_ij=R_x_ij, R_x_ji=R_x_ji, R_x_ik=R_x_ik, R_x_ki=R_x_ki)
    assert S_x == pytest.approx(S_x_)


def test_n_x_t_plus_Delta_t():
    nlte = aa.population.balance_equation

    n_x_t = [np.array([1.0, 2.0]), np.array([1.0, 2.0, 3.0]), np.array([1.0])]
    R_x_ij = [
        np.array([
            [0.0, 1.0],
            [0.0, 0.0],
        ]),
        np.array([
            [0.0, 2.0, 3.0],
            [0.0, 0.0, 4.0],
            [0.0, 0.0, 0.0],
        ]),
        np.array([[0.0]]),
    ]
    R_x_ji = [
        np.array([
            [0.0, 0.0],
            [5.0, 0.0],
        ]),
        np.array([
            [0.0, 0.0, 0.0],
            [6.0, 0.0, 0.0],
            [7.0, 8.0, 0.0],
        ]),
        np.array([[0.0]]),
    ]
    R_x_ik = [
        np.array([9.0, 10.0]),
        np.array([11.0, 12.0, 13.0]),
        np.array([14.0]),
    ]
    R_x_ki = [
        np.array([15.0, 16.0]),
        np.array([17.0, 18.0, 19.0]),
        np.array([20.0]),
    ]
    Delta_t = 1.0e1

    n_x_t_plus_Delta_t_ = [
        np.array([3.4746906854554194, 2.006624388422274]),
        np.array([1.6640835987325575, 1.1451081089978288, 0.8992155919667877]),
        np.array([0.8102776264251446]),
    ]

    n_x_t_plus_Delta_t = nlte.n_x_t_plus_Delta_t(
        n_x_t=n_x_t,
        R_x_ij=R_x_ij,
        R_x_ji=R_x_ji,
        R_x_ik=R_x_ik,
        R_x_ki=R_x_ki,
        Delta_t=Delta_t,
    )
    assert n_x_t_plus_Delta_t[0] == pytest.approx(n_x_t_plus_Delta_t_[0])
    assert n_x_t_plus_Delta_t[1] == pytest.approx(n_x_t_plus_Delta_t_[1])
    assert n_x_t_plus_Delta_t[2] == pytest.approx(n_x_t_plus_Delta_t_[2])