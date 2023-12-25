import astrea as aa
import numpy as np
import pytest


def test_tau_E():
    tau_E = aa.optics.optical_depth.tau_E

    x_X = np.array([0.1, 0.2])
    alpha_nu_XE = np.array([
        [1.2567614843378096e-25, 1.2567614843378096e-25],
        [1.8851422265067139e-25, 1.8851422265067139e-25],
    ])

    tau_E = tau_E(x_X=x_X, alpha_nu_XE=alpha_nu_XE)

    assert tau_E == pytest.approx([0.00000000e+00, 1.57095186e-26])