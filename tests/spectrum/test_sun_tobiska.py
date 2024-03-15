import astrea as aa


def test_sun_tobiska_E_q_lambda():
    spectrum = aa.spectrum.sun_tobiska.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 649)
    assert spectrum[0][0] == 18.62
    assert spectrum[1][0] == 722000


def test_sun_tobiska_F_lambda():
    spectrum = aa.spectrum.sun_tobiska.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 649)
    assert spectrum[0][0] == 1.862
    assert spectrum[1][0] == 7.702545160373396e-06