import astrea as aa


def test_sun_linsky_E_q_lambda():
    spectrum = aa.spectrum.sun_linsky.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 2401)
    assert spectrum[0][0] == 0.999
    assert spectrum[1][0] == 100.0


def test_sun_linsky_F_lambda():
    spectrum = aa.spectrum.sun_linsky.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 2401)
    assert spectrum[0][0] == 0.0999
    assert spectrum[1][0] == 1.988434291440369e-08