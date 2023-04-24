import numpy as np

from lss.lss_py import cbb_mashonkina_o1_rates
from lss.lss_py import cbb_regemorter_rates
from lss.lss_py import ci_arnaud_younger_rates
from lss.lss_py import ci_hahn_rates
from lss.lss_py import cti_arnaud_rates
from lss.lss_py import ctr_arnaud_rates
from lss.lss_py import dr_badnell_rates
from lss.lss_py import pi_mashonkina_o1_rates
from lss.lss_py import pi_tasitsiomi_rates
from lss.lss_py import se_nist_o1_rates
from lss.lss_py import rbb_mashonkina_doppler_o1_rates
from lss.lss_py import rbb_mashonkina_voigt_o1_rates
from lss.lss_py import rbb_tasitsiomi_rates
from lss.lss_py import rr_badnell_verner_rates
from lss.lss_py import rr_seaton_rates
from lss.lss_py import tbr_hahn_rates
from lss.transition import Transition


def calculate_rates_matrix(
    elements,
    spectrum = None,
    charge_transfer_elements = [],
    temperature = None,
    electron_temperature = None,
    electron_number_density = None,
    optical_depth = 0.0,
    transitions_types = [],
):
    rates_matrix = np.zeros((
        sum([len(el.keys) for el in elements]),
        sum([len(el.keys) for el in elements])
    ))
    if Transition.CBB_MASHONKINA_O1 in transitions_types:
        rates_matrix += cbb_mashonkina_o1_rates(
            elements,
            temperature,
            electron_number_density,
        )
    if Transition.CBB_REGEMORTER in transitions_types:
        rates_matrix += cbb_regemorter_rates(
            elements,
            temperature,
            electron_temperature,
            electron_number_density,
        )
    if Transition.CI_ARNAUD_YOUNGER in transitions_types:
        rates_matrix += ci_arnaud_younger_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    if Transition.CI_HAHN in transitions_types:
        rates_matrix += ci_hahn_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    if Transition.CTI_ARNAUD in transitions_types:
        for charge_transfer_element in charge_transfer_elements:
            rates_matrix += cti_arnaud_rates(
                elements,
                charge_transfer_element,
                temperature,
                electron_number_density,
            )
    if Transition.CTR_ARNAUD in transitions_types:
        for charge_transfer_element in charge_transfer_elements:
            rates_matrix += ctr_arnaud_rates(
                elements,
                charge_transfer_element,
                temperature,
                electron_number_density,
            )
    if Transition.DR_BADNELL in transitions_types:
        rates_matrix += dr_badnell_rates(
            elements,
            temperature,
            electron_number_density,
        )
    if Transition.PI_MASHONKINA_O1 in transitions_types:
        rates_matrix += pi_mashonkina_o1_rates(
            elements,
            spectrum,
            optical_depth,
        )
    if Transition.PI_TASITSIOMI in transitions_types:
        rates_matrix += pi_tasitsiomi_rates(
            elements,
            spectrum,
            optical_depth,
            temperature,
            se_nist_o1_rates(elements),
        )
    if Transition.RBB_MASHONKINA_DOPPLER_O1 in transitions_types:
        rates_matrix += rbb_mashonkina_doppler_o1_rates(elements)
    if Transition.RBB_MASHONKINA_VOIGT_O1 in transitions_types:
        rates_matrix += rbb_mashonkina_voigt_o1_rates(elements)
    if Transition.RBB_TASITSIOMI in transitions_types:
        rates_matrix += rbb_tasitsiomi_rates(
            elements,
            spectrum,
            optical_depth,
            temperature,
            se_nist_o1_rates(elements),
        )
    if Transition.RR_BADNELL_VERNER in transitions_types:
        rates_matrix += rr_badnell_verner_rates(
            elements,
            temperature,
            electron_number_density,
        )
    if Transition.RR_SEATON in transitions_types:
        rates_matrix += rr_seaton_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    if Transition.SE_NIST_O1 in transitions_types:
        rates_matrix += se_nist_o1_rates(elements)
    if Transition.TBR_HAHN in transitions_types:
        rates_matrix += tbr_hahn_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    return rates_matrix