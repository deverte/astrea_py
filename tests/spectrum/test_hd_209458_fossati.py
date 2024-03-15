import astrea as aa


def test_hd_209458_fossati_E_q_lambda():
    spectrum = aa.spectrum.hd_209458_fossati.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 1019)
    assert spectrum[0][0] == 8
    assert spectrum[1][0] == 1111.11


def test_hd_209458_fossati_F_lambda():
    spectrum = aa.spectrum.hd_209458_fossati.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 1019)
    assert spectrum[0][0] == 0.8
    assert spectrum[1][0] == 2.7589498204209323e-08