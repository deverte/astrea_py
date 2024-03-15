import astrea as aa


def test_gj_436_fossati_E_q_lambda():
    spectrum = aa.spectrum.gj_436_fossati.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 908)
    assert spectrum[0][0] == 5.49944
    assert spectrum[1][0] == 85151.36068


def test_gj_436_fossati_F_lambda():
    spectrum = aa.spectrum.gj_436_fossati.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 908)
    assert spectrum[0][0] == 0.549944
    assert spectrum[1][0] == 3.0757416692132324e-06