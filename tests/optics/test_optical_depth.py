import astrea as aa
import numpy as np
import pytest


def test_tau_X():
    tau_X = aa.optics.optical_depth.tau_X

    x_X = np.array([0.1, 0.2])
    alpha_nu_X = np.array([1.2567614843378096e-25, 1.8851422265067139e-25])

    tau_X = tau_X(x_X=x_X, alpha_nu_X=alpha_nu_X)

    assert tau_X == pytest.approx([0.00000000e+00, 1.57095186e-26])