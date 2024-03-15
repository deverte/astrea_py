import astrea as aa


def test_hd_189733_fossati_E_q_lambda():
    spectrum = aa.spectrum.hd_189733_fossati.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 1117)
    assert spectrum[0][0] == 4.0
    assert spectrum[1][0] == 1407030.0


def test_hd_189733_fossati_F_lambda():
    spectrum = aa.spectrum.hd_189733_fossati.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 1117)
    assert spectrum[0][0] == 0.4
    assert spectrum[1][0] == 6.987472285960643e-05