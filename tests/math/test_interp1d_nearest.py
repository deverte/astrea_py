import astrea as aa
import numpy as np


def test_interp1d_nearest():
    x_Y = np.array([0.0, 1.0, 2.0])
    y_Y = np.array([4.0, 2.0, 6.0])

    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=-1.0) == 4.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=0.0) == 4.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=0.4) == 4.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=0.5) == 4.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=0.6) == 2.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=1.0) == 2.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=1.4) == 2.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=1.5) == 2.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=1.6) == 6.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=2.0) == 6.0
    assert aa.math.interp1d_nearest(x_Y=x_Y, y_Y=y_Y, x=3.0) == 6.0


def test_interp1d_nearest_X():
    x_Y = np.array([0.0, 1.0, 2.0])
    y_Y = np.array([4.0, 2.0, 6.0])
    x_X = np.array([-1.0, 0.0, 0.4, 0.5, 0.6, 1.0, 1.4, 1.5, 1.6, 2.0, 3.0])

    y_X = np.array([4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0, 2.0, 6.0, 6.0, 6.0])

    assert (aa.math.interp1d_nearest_X(x_Y=x_Y, y_Y=y_Y, x_X=x_X) == y_X).all()