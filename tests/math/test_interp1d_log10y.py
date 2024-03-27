import astrea as aa
import numpy as np


def test_f():
    x_Y = np.array([0.0, 1.0, 2.0])
    y_Y = np.array([4.0, 2.0, 6.0])

    # interpolation [a, b)
    assert aa.math.interp1d_log10y.f(x_Y=x_Y, y_Y=y_Y, x=-1.0) == 1.0
    assert aa.math.interp1d_log10y.f(x_Y=x_Y, y_Y=y_Y, x=0.0) == 4.0
    assert (
        aa.math.interp1d_log10y.f(x_Y=x_Y, y_Y=y_Y, x=0.5) == 2.82842712474619
    )
    assert aa.math.interp1d_log10y.f(x_Y=x_Y, y_Y=y_Y, x=1.0) == 2.0
    assert (
        aa.math.interp1d_log10y.f(x_Y=x_Y, y_Y=y_Y, x=1.5) == 3.464101615137755
    )
    assert aa.math.interp1d_log10y.f(x_Y=x_Y, y_Y=y_Y, x=2.0) == 1.0
    assert aa.math.interp1d_log10y.f(x_Y=x_Y, y_Y=y_Y, x=3.0) == 1.0


def test_f_X():
    x_Y = np.array([0.0, 1.0, 2.0])
    y_Y = np.array([4.0, 2.0, 6.0])
    x_X = np.array([-1.0, 0.0, 0.5, 1.0, 1.5, 2.0, 3.0])

    y_X = np.array(
        [1.0, 4.0, 2.82842712474619, 2.0, 3.464101615137755, 1.0, 1.0]
    )

    # interpolation [a, b)
    assert (aa.math.interp1d_log10y.f_X(x_Y=x_Y, y_Y=y_Y, x_X=x_X) == y_X).all()