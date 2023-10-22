import astrea as aa
import numpy as np


def test_interp1d_nearest_x():
    xs = np.array([0.0, 1.0, 2.0])
    ys = np.array([4.0, 2.0, 6.0])

    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=-1.0) == 4.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=0.0) == 4.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=0.4) == 4.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=0.5) == 4.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=0.6) == 2.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=1.0) == 2.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=1.4) == 2.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=1.5) == 2.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=1.6) == 6.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=2.0) == 6.0
    assert aa.math.interp1d_nearest_x(xs=xs, ys=ys, x=3.0) == 6.0


def test_interp1d_nearest_xs():
    xs = np.array([0.0, 1.0, 2.0])
    ys = np.array([4.0, 2.0, 6.0])
    x = np.array([-1.0, 0.0, 0.4, 0.5, 0.6, 1.0, 1.4, 1.5, 1.6, 2.0, 3.0])

    y = np.array([4.0, 4.0, 4.0, 4.0, 2.0, 2.0, 2.0, 2.0, 6.0, 6.0, 6.0])

    assert (aa.math.interp1d_nearest_xs(xs=xs, ys=ys, x=x) == y).all()