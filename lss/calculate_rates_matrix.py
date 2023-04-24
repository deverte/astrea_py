import numpy as np

from . import lss_py

from .transition import Transition


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
        rates_matrix += lss_py.cbb_mashonkina_o1_rates(
            elements,
            temperature,
            electron_number_density,
        )
    if Transition.CBB_REGEMORTER in transitions_types:
        rates_matrix += lss_py.cbb_regemorter_rates(
            elements,
            temperature,
            electron_temperature,
            electron_number_density,
        )
    if Transition.CI_ARNAUD_YOUNGER in transitions_types:
        rates_matrix += lss_py.ci_arnaud_younger_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    if Transition.CI_HAHN in transitions_types:
        rates_matrix += lss_py.ci_hahn_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    if Transition.CTI_ARNAUD in transitions_types:
        for charge_transfer_element in charge_transfer_elements:
            rates_matrix += lss_py.cti_arnaud_rates(
                elements,
                charge_transfer_element,
                temperature,
                electron_number_density,
            )
    if Transition.CTR_ARNAUD in transitions_types:
        for charge_transfer_element in charge_transfer_elements:
            rates_matrix += lss_py.ctr_arnaud_rates(
                elements,
                charge_transfer_element,
                temperature,
                electron_number_density,
            )
    if Transition.DR_BADNELL in transitions_types:
        rates_matrix += lss_py.dr_badnell_rates(
            elements,
            temperature,
            electron_number_density,
        )
    if Transition.PI_MASHONKINA_O1 in transitions_types:
        rates_matrix += lss_py.pi_mashonkina_o1_rates(
            elements,
            spectrum,
            optical_depth,
        )
    if Transition.PI_TASITSIOMI in transitions_types:
        rates_matrix += lss_py.pi_tasitsiomi_rates(
            elements,
            spectrum,
            optical_depth,
            temperature,
            lss_py.se_nist_o1_rates(elements),
        )
    if Transition.RBB_MASHONKINA_DOPPLER_O1 in transitions_types:
        rates_matrix += lss_py.rbb_mashonkina_doppler_o1_rates(elements)
    if Transition.RBB_MASHONKINA_VOIGT_O1 in transitions_types:
        rates_matrix += lss_py.rbb_mashonkina_voigt_o1_rates(elements)
    if Transition.RBB_TASITSIOMI in transitions_types:
        rates_matrix += lss_py.rbb_tasitsiomi_rates(
            elements,
            spectrum,
            optical_depth,
            temperature,
            lss_py.se_nist_o1_rates(elements),
        )
    if Transition.RR_BADNELL_VERNER in transitions_types:
        rates_matrix += lss_py.rr_badnell_verner_rates(
            elements,
            temperature,
            electron_number_density,
        )
    if Transition.RR_SEATON in transitions_types:
        rates_matrix += lss_py.rr_seaton_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    if Transition.SE_NIST_O1 in transitions_types:
        rates_matrix += lss_py.se_nist_o1_rates(elements)
    if Transition.TBR_HAHN in transitions_types:
        rates_matrix += lss_py.tbr_hahn_rates(
            elements,
            electron_temperature,
            electron_number_density,
        )
    return rates_matrix