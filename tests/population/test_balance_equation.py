import astrea as aa
import pytest
import numpy as np


def test_Q_KK():
    nlte = aa.population.balance_equation

    S_KK = np.array([
        [1.0, 2.0, 3.0],
        [4.0, 5.0, 6.0],
        [7.0, 8.0, 9.0],
    ])

    Q_KK_ = np.array([
        [-5.0, 4.0, 7.0],
        [2.0, -10.0, 8.0],
        [3.0, 6.0, -15.0],
    ])

    Q_KK = nlte.Q_KK(S_KK=S_KK)
    assert (Q_KK == Q_KK_).all()


def test_P_KK():
    nlte = aa.population.balance_equation

    Q_KK = np.array([
        [5.0, 4.0, 7.0],
        [2.0, 10.0, 8.0],
        [3.0, 6.0, 15.0],
    ])
    Delta_t = 1.0e1

    P_KK_ = np.array([
        [-0.02922476, 0.00516888, 0.01095451],
        [0.001703382388788219, -0.01527464, 0.0074009],
        [0.00519825, 0.00511015, -0.01189724],
    ])

    P_KK = nlte.P_KK(Q_KK=Q_KK, Delta_t=Delta_t)
    assert P_KK == pytest.approx(P_KK_)


def test_p_t_plus_Delta_t_K():
    nlte = aa.population.balance_equation

    p_K = np.array([1.0, 2.0, 3.0])
    P_KK = np.array([
        [-0.02922476, 0.00516888, 0.01095451],
        [0.001703382388788219, -0.01527464, 0.0074009],
        [0.00519825, 0.00511015, -0.01189724],
    ])

    p_t_plus_Delta_t_K_ = np.array(
        [0.013976530000000001, -0.0066431976112117826, -0.020273169999999997],
    )

    p_t_plus_Delta_t_K = nlte.p_t_plus_Delta_t_K(p_K=p_K, P_KK=P_KK)
    assert p_t_plus_Delta_t_K == pytest.approx(p_t_plus_Delta_t_K_)


def test_p_K():
    nlte = aa.population.balance_equation

    n_ZK = [np.array([1.0, 2.0]), np.array([3.0, 4.0, 5.0]), np.array([6.0])]

    p_K_ = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0])

    p_K = nlte.p_K(n_ZK=n_ZK)
    assert p_K == pytest.approx(p_K_)


def test_S_KK():
    nlte = aa.population.balance_equation

    R_ij_ZKK = [
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
    R_ji_ZKK = [
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
    R_ik_ZK = [
        np.array([9.0, 10.0]),
        np.array([11.0, 12.0, 13.0]),
        np.array([14.0]),
    ]
    R_ki_ZK = [
        np.array([15.0, 16.0]),
        np.array([17.0, 18.0, 19.0]),
        np.array([20.0]),
    ]

    S_KK_ = np.array([
        [ 0.0,  1.0,  9.0,  0.0,  0.0,  0.0],
        [ 5.0,  0.0, 10.0,  0.0,  0.0,  0.0],
        [15.0, 16.0,  0.0,  2.0,  3.0, 11.0],
        [ 0.0,  0.0,  6.0,  0.0,  4.0, 12.0],
        [ 0.0,  0.0,  7.0,  8.0,  0.0, 13.0],
        [ 0.0,  0.0, 17.0, 18.0, 19.0,  0.0],
    ])

    S_KK = nlte.S_KK(R_ij_ZKK=R_ij_ZKK, R_ji_ZKK=R_ji_ZKK, R_ik_ZK=R_ik_ZK, R_ki_ZK=R_ki_ZK)
    assert S_KK == pytest.approx(S_KK_)


def test_n_t_plus_Delta_t_ZK():
    nlte = aa.population.balance_equation

    n_ZK = [np.array([1.0, 2.0]), np.array([1.0, 2.0, 3.0]), np.array([1.0])]
    R_ij_ZKK = [
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
    R_ji_ZKK = [
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
    R_ik_ZK = [
        np.array([9.0, 10.0]),
        np.array([11.0, 12.0, 13.0]),
        np.array([14.0]),
    ]
    R_ki_ZK = [
        np.array([15.0, 16.0]),
        np.array([17.0, 18.0, 19.0]),
        np.array([20.0]),
    ]
    Delta_t = 1.0e1

    n_t_plus_Delta_t_ZK_ = [
        np.array([3.4746906854554194, 2.006624388422274]),
        np.array([1.6640835987325575, 1.1451081089978288, 0.8992155919667877]),
        np.array([0.8102776264251446]),
    ]

    n_t_plus_Delta_t_ZK = nlte.n_t_plus_Delta_t_ZK(
        n_ZK=n_ZK,
        R_ij_ZKK=R_ij_ZKK,
        R_ji_ZKK=R_ji_ZKK,
        R_ik_ZK=R_ik_ZK,
        R_ki_ZK=R_ki_ZK,
        Delta_t=Delta_t,
    )
    assert n_t_plus_Delta_t_ZK[0] == pytest.approx(n_t_plus_Delta_t_ZK_[0])
    assert n_t_plus_Delta_t_ZK[1] == pytest.approx(n_t_plus_Delta_t_ZK_[1])
    assert n_t_plus_Delta_t_ZK[2] == pytest.approx(n_t_plus_Delta_t_ZK_[2])


def test_n_t_plus_Delta_t_XZK():
    nlte = aa.population.balance_equation

    T_X = np.array([1.0e3, 1.0e4])
    n_t_XZK = [[np.array([1.0, 2.0]), np.array([1.0, 2.0, 3.0]), np.array([1.0])]] * 2
    R_ij_XZKK = [[
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
    ]] * 2
    R_ji_XZKK = [[
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
    ]] * 2
    R_ik_XZK = [[
        np.array([9.0, 10.0]),
        np.array([11.0, 12.0, 13.0]),
        np.array([14.0]),
    ]] * 2
    R_ki_XZK = [[
        np.array([15.0, 16.0]),
        np.array([17.0, 18.0, 19.0]),
        np.array([20.0]),
    ]] * 2
    Delta_t = 1.0e1

    n_t_plus_Delta_t_XZK_ = [[
        np.array([3.4746906854554194, 2.006624388422274]),
        np.array([1.6640835987325575, 1.1451081089978288, 0.8992155919667877]),
        np.array([0.8102776264251446]),
    ]] * 2

    n_t_plus_Delta_t_XZK = nlte.n_t_plus_Delta_t_XZK(
        x_X=T_X,
        n_t_XZK=n_t_XZK,
        R_ij_XZKK=R_ij_XZKK,
        R_ji_XZKK=R_ji_XZKK,
        R_ik_XZK=R_ik_XZK,
        R_ki_XZK=R_ki_XZK,
        Delta_t=Delta_t,
    )
    assert n_t_plus_Delta_t_XZK[0][0] == pytest.approx(n_t_plus_Delta_t_XZK_[0][0])
    assert n_t_plus_Delta_t_XZK[0][1] == pytest.approx(n_t_plus_Delta_t_XZK_[0][1])
    assert n_t_plus_Delta_t_XZK[0][2] == pytest.approx(n_t_plus_Delta_t_XZK_[0][2])