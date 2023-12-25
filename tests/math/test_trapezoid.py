import astrea as aa
import numpy as np
import pytest


def test_F_dx():
    y1 = np.array([1.0, 2.0, 3.0])
    dx1 = 2
    y2 = np.linspace(0, 4, int(1e5))**2
    dx2 = 4.0e-5

    assert aa.math.trapezoid.F_dx(y_X=y1, dx=dx1) == 8.0
    assert (
        aa.math.trapezoid.F_dx(y_X=y2, dx=dx2)
        == pytest.approx(4.0**3.0 / 3.0, abs=1e-3)
    )


def test_F():
    x1 = np.array([4.0, 6.0, 8.0])
    y1 = np.array([1.0, 2.0, 3.0])
    x2 = np.linspace(0, 4, int(1e5))
    y2 = x2**2

    assert aa.math.trapezoid.F(y_X=y1, x_X=x1) == 8.0
    assert (
        aa.math.trapezoid.F(y_X=y2, x_X=x2)
        == pytest.approx(4.0**3.0 / 3.0, abs=1e-8)
    )