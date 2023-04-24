import matplotlib.pyplot as plt
import numpy as np

from lss.lss_py import BlackBodyPlanck
from lss.lss_py import SunGueymard
from lss.lss_py import Kelt9Fossati


def plot_spectrum(spectrum, wavelengths = None):
    if wavelengths is None:
        wavelengths = np.linspace(
            spectrum.min_wavelength,
            spectrum.max_wavelength,
        )

    spectral_flux_densities = np.array([spectrum(l) for l in wavelengths])

    if isinstance(spectrum, BlackBodyPlanck):
        title = (
            f"Black Body (Planck) "
            f"({spectrum.temperature} $K$, "
            f"{spectrum.total_area} $W \cdot m^{{-2}}$)"
        )
    if isinstance(spectrum, SunGueymard):
        title = f"Sun (Gueymard)"
    if isinstance(spectrum, Kelt9Fossati):
        title = "Kelt 9 (Fossati)"

    plt.plot(wavelengths, spectral_flux_densities)
    plt.title(title)
    plt.xlabel('Wavelength, $nm$')
    plt.ylabel('Spectral Irradiance, $W \cdot m^{{-2}} \cdot nm^{{-1}}$')
    plt.show()