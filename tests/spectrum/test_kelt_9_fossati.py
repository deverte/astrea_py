import astrea as aa


def test_kelt_9_fossati():
    spectrum = aa.spectrum.kelt_9_fossati.F_lambda_vs_lambda()

    assert spectrum.shape == (2, 1000)
    assert spectrum[0][0] == 30.6
    assert spectrum[1][0] == 1.795104381202966e-20