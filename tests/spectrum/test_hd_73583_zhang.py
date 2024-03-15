import astrea as aa


def test_hd_73583_zhang_E_q_lambda():
    spectrum = aa.spectrum.hd_73583_zhang.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 625)
    assert spectrum[0][0] == 5.0
    assert spectrum[1][0] == 7476130.0


def test_hd_73583_zhang_F_lambda():
    spectrum = aa.spectrum.hd_73583_zhang.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 625)
    assert spectrum[0][0] == 0.5
    assert spectrum[1][0] == 0.0002970185493201364