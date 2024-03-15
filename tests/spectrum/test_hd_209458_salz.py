import astrea as aa


def test_hd_209458_salz_E_q_lambda():
    spectrum = aa.spectrum.hd_209458_salz.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 841)
    assert spectrum[0][0] == 7
    assert spectrum[1][0] == 12.5


def test_hd_209458_salz_F_lambda():
    spectrum = aa.spectrum.hd_209458_salz.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 841)
    assert spectrum[0][0] == 0.7000000000000001
    assert spectrum[1][0] == 3.547224744908801e-10