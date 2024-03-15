import astrea as aa


def test_hd_85512_muscles_E_q_lambda():
    spectrum = aa.spectrum.hd_85512_muscles.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 3041)
    assert spectrum[0][0] == 5
    assert spectrum[1][0] == 13350.0


def test_hd_85512_muscles_F_lambda():
    spectrum = aa.spectrum.hd_85512_muscles.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 3041)
    assert spectrum[0][0] == 0.5
    assert spectrum[1][0] == 5.303810438587639e-07