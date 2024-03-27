import astrea as aa
import numpy as np


def test_f():
    x_Y = np.array([1.0, 2.0, 3.0])
    y_Y = np.array([4.0, 2.0, 6.0])

    # interpolation [a, b)
    assert aa.math.interp1d_log10xy.f(x_Y=x_Y, y_Y=y_Y, x=0.5) == 1.0
    assert aa.math.interp1d_log10xy.f(x_Y=x_Y, y_Y=y_Y, x=1.0) == 4.0
    assert (
        aa.math.interp1d_log10xy.f(x_Y=x_Y, y_Y=y_Y, x=1.5) == 2.6666666666666665
    )
    assert aa.math.interp1d_log10xy.f(x_Y=x_Y, y_Y=y_Y, x=2.0) == 2.0
    assert (
        aa.math.interp1d_log10xy.f(x_Y=x_Y, y_Y=y_Y, x=2.5) == 3.661076216589502
    )
    assert aa.math.interp1d_log10xy.f(x_Y=x_Y, y_Y=y_Y, x=3.0) == 1.0


def test_f_X():
    x_Y = np.array([1.0, 2.0, 3.0])
    y_Y = np.array([4.0, 2.0, 6.0])
    x_X = np.array([0.5, 1.0, 1.5, 2.0, 2.5, 3.0])

    y_X = np.array([1.0, 4.0, 2.6666666666666665, 2.0, 3.661076216589502, 1.0])

    # interpolation [a, b)
    assert (
        aa.math.interp1d_log10xy.f_X(x_Y=x_Y, y_Y=y_Y, x_X=x_X) == y_X
    ).all()