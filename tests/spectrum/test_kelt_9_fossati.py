import astrea as aa


def test_kelt_9_fossati_E_q_lambda():
    spectrum = aa.spectrum.kelt_9_fossati.E_q_lambda_vs_lambda()

    assert spectrum.shape == (2, 1000)
    assert spectrum[0][0] == 306
    assert spectrum[1][0] == 2.76525e-08


def test_kelt_9_fossati_F_lambda():
    spectrum = aa.spectrum.kelt_9_fossati.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 1000)
    assert spectrum[0][0] == 30.6
    assert spectrum[1][0] == 1.7951043812029656e-20