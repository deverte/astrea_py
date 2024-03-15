import astrea as aa


def test_wasp_80_salz_fossati_E_q_lambda():
    spectrum = aa.spectrum.wasp_80_salz_fossati.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 588)
    assert spectrum[0][0] == 8.0
    assert spectrum[1][0] == 140500.0


def test_wasp_80_salz_fossati_F_lambda():
    spectrum = aa.spectrum.wasp_80_salz_fossati.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 588)
    assert spectrum[0][0] == 0.8
    assert spectrum[1][0] == 3.488695536617806e-06