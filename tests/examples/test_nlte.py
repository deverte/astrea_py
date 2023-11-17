def test_nlte():
    import astrea as aa
    import numpy as np


    class KELT_9_b:
        def __init__(self):
            distance = 0.03
            self.F_lambda_vs_lambda = (
                aa.spectrum.kelt_9_fossati.F_lambda_vs_lambda()
            )
            self.F_lambda_vs_lambda[1] = (
                self.F_lambda_vs_lambda[1] / distance**2
            )


    class O_I:
        def __init__(self):
            keys = [
                aa.element.o_i.STRUCTURE.LS_He_2s2_2p4_3P,
                aa.element.o_i.STRUCTURE.LS_He_2s2_2p3_4So_3s_5So,
            ]

            int_keys = np.array([k.value for k in keys])
            sort_indices = aa.element.o_i.E()[int_keys].argsort()
            sorted_keys = [int_keys[i] for i in sort_indices]

            self.keymap = {
                keys[sort_indices[i]]: i for i in range(len(sort_indices))
            }

            self.E_K = aa.element.o_i.E()[sorted_keys]
            self.g_K = aa.element.o_i.g()[sorted_keys]
            self.f_KK = aa.element.o_i.f().T[sorted_keys].T[sorted_keys]
            self.C_vs_T_KK = [
                [aa.element.o_i.C_vs_T()[i][j] for j in sorted_keys]
                for i in sorted_keys
            ]
            self.sigma_vs_nu_K = [
                aa.element.o_i.sigma_vs_nu()[i] for i in sorted_keys
            ]


    class O_II:
        def __init__(self):
            keys = list(aa.element.o_ii.STRUCTURE.__members__.values())

            int_keys = np.array([k.value for k in keys])
            sort_indices = aa.element.o_ii.E()[int_keys].argsort()
            sorted_keys = [int_keys[i] for i in sort_indices]

            self.keymap = {
                keys[sort_indices[i]]: i for i in range(len(sort_indices))
            }

            self.E_K = aa.element.o_ii.E()[sorted_keys]
            self.g_K = aa.element.o_ii.g()[sorted_keys]
            self.f_KK = np.zeros((1, 1))
            self.C_vs_T_KK = [
                [
                    np.zeros((2, 0)),
                ],
            ]
            self.sigma_vs_nu_K = [
                np.zeros((2, 0)),
            ]


    class Env:
        def __init__(self, T_X, N_e_X, N_a_X, Delta_t=6e2):
            self.F_lambda_vs_lambda = KELT_9_b().F_lambda_vs_lambda

            elements = [
                O_I(),
                O_II(),
            ]
            self.E_ZK = [e.E_K for e in elements]
            self.g_ZK = [e.g_K for e in elements]
            self.f_ZKK = [e.f_KK for e in elements]
            self.C_vs_T_ZKK = [e.C_vs_T_KK for e in elements]
            self.sigma_vs_nu_ZK = [e.sigma_vs_nu_K for e in elements]

            self.T_X = T_X
            self.N_e_X = N_e_X
            self.N_a_X = N_a_X
            self.Delta_t = Delta_t

            self.cd = aa.transition.cd.R_XZKK
            self.ce = aa.transition.ce.R_XZKK
            self.rd = aa.transition.rd.R_XZKK
            self.re = aa.transition.re_lorentz.R_XZKK
            self.ri = aa.transition.ri.R_XZK
            self.rr = lambda ri: [
                [np.zeros_like(ri_x_z) for ri_x_z in ri_x] for ri_x in ri
            ]

            self.nlte = aa.population.balance_equation.n_t_plus_Delta_t_XZK
            self.lte = aa.population.boltzmann_distribution.n_XZK

            self.n = []

        def equilibrium(self):
            rd = self.rd(x_X=self.T_X, f_ZKK=self.f_ZKK, g_ZK=self.g_ZK, E_ZK=self.E_ZK)
            re = self.re(
                x_X=self.T_X,
                g_ZK=self.g_ZK,
                E_ZK=self.E_ZK,
                A_ZKK=rd[x:=0],
                F_lambda_vs_lambda=self.F_lambda_vs_lambda,
            )
            ri = self.ri(
                x_X=self.T_X,
                sigma_vs_nu_ZK=self.sigma_vs_nu_ZK,
                F_lambda_vs_lambda=self.F_lambda_vs_lambda,
            )
            rr = self.rr(ri)
            ce = self.ce(T_X=self.T_X, N_e_X=self.N_e_X, C_vs_T_ZKK=self.C_vs_T_ZKK)
            cd = self.cd(T_X=self.T_X, R_XZKK=ce, g_ZK=self.g_ZK, E_ZK=self.E_ZK)

            R_ij = [
                [re[x][z] + ce[x][z] for z in range(len(re[x]))]
                for x in range(len(re))
            ]
            R_ji = [
                [rd[x][z] + cd[x][z] for z in range(len(rd[x]))]
                for x in range(len(rd))
            ]
            R_ik = ri
            R_ki = rr

            lte = self.lte(T_X=self.T_X, g_ZK=self.g_ZK, E_ZK=self.E_ZK)
            nlte = self.nlte(
                x_X=self.T_X,
                n_t_XZK=lte,
                R_ij_XZKK=R_ij,
                R_ji_XZKK=R_ji,
                R_ik_XZK=R_ik,
                R_ki_XZK=R_ki,
                Delta_t=self.Delta_t,
            )

            self.n = [ # full population is taken from MHD
                [
                    self.N_a_X[x][z] * nlte[x][z] / nlte[x][z].sum()
                    for z in range(len(self.E_ZK))
                ]
                for x in range(len(self.T_X))
            ]


    size = 100
    T = np.geomspace(1e3, 1e4, size)
    N_e = np.geomspace(1e7, 1e9, size)
    N_a = np.ones((2, size)).T / 2
    Delta_t = 6e10

    env = Env(T_X=T, N_e_X=N_e, N_a_X=N_a, Delta_t=Delta_t)

    env.equilibrium()

    assert len(env.n) == size