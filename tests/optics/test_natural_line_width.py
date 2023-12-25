import astrea as aa
import numpy as np
import pytest


def test_Delta_nu_L():
    Delta_nu_L = aa.optics.natural_line_width.Delta_nu_L

    A_ji = 1e3

    natural_line_width = Delta_nu_L(A_ji=A_ji)

    assert natural_line_width == pytest.approx(159.15494309189535)