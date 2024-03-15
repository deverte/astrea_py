import astrea as aa


def test_gj_3470_bourrier_E_q_lambda():
    spectrum = aa.spectrum.gj_3470_bourrier.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 281)
    assert spectrum[0][0] == 10
    assert spectrum[1][0] == 4283940.0


def test_gj_3470_bourrier_F_lambda():
    spectrum = aa.spectrum.gj_3470_bourrier.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 281)
    assert spectrum[0][0] == 1.0
    assert spectrum[1][0] == 8.509814865274581e-05