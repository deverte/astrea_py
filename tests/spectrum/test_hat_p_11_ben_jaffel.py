import astrea as aa


def test_hat_p_11_ben_jaffel_E_q_lambda():
    spectrum = aa.spectrum.hat_p_11_ben_jaffel.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 570)
    assert spectrum[0][0] == 1.5
    assert spectrum[1][0] == 17000


def test_hat_p_11_ben_jaffel_F_lambda():
    spectrum = aa.spectrum.hat_p_11_ben_jaffel.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 570)
    assert spectrum[0][0] == 0.15000000000000002
    assert spectrum[1][0] == 2.2513053047687854e-06