/*
    ChibiOS - Copyright (C) 2014 Greg Wuller

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    ADCv1/hal_adc_lld.c
 * @brief   MIMXRT1062 ADC subsystem low level driver source.
 *
 * @addtogroup ADC
 * @{
 */

#include "hal.h"

#if HAL_USE_ADC || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#define ADC_CHANNEL_MASK                    0x1f

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/** @brief ADC1 driver identifier.*/
#if MIMXRT1062_ADC_USE_ADC1 || defined(__DOXYGEN__)
ADCDriver ADCD1;
#endif

/** @brief ADC1 driver identifier.*/
#if MIMXRT1062_ADC_USE_ADC2 || defined(__DOXYGEN__)
ADCDriver ADCD2;
#endif

/** @brief ADC1 driver identifier.*/
#if MIMXRT1062_ADC_USE_ADC3 || defined(__DOXYGEN__)
ADCDriver ADCD3;
#endif

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void calibrate(ADCDriver *adcp) {
  // TODO:
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

#if MIMXRT1062_ADC_USE_ADC1 || defined(__DOXYGEN__)
/**
 * @brief   ADC interrupt handler.
 *
 * @isr
 */
OSAL_IRQ_HANDLER(MIMXRT1062_ADC1_IRQ_VECTOR) {
  OSAL_IRQ_PROLOGUE();

  ADCDriver *adcp = &ADCD1;

  // TODO:

  OSAL_IRQ_EPILOGUE();
}
#endif

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level ADC driver initialization.
 *
 * @notapi
 */
void adc_lld_init(void) {

#if MIMXRT1062_ADC_USE_ADC1
  /* Driver initialization.*/
  adcObjectInit(&ADCD1);
#endif

  /* The shared vector is initialized on driver initialization and never
     disabled.*/
  nvicEnableVector(ADC1_IRQn, MIMXRT1062_ADC_IRQ_PRIORITY);
}

/**
 * @brief   Configures and activates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start(ADCDriver *adcp) {

  /* If in stopped state then enables the ADC clock.*/
  // if (adcp->state == ADC_STOP) {
  //   SIM->SCGC6 |= SIM_SCGC6_ADC0;

// TODO:
// #if MIMXRT1062_ADC_USE_ADC1
//     if (&ADCD1 == adcp) {
//       adcp->adc = ADC0;
//       if (adcp->config->calibrate) {
//         calibrate(adcp);
//       }
//     }
// #endif /* MIMXRT1062_ADC_USE_ADC1 */
  // }
}

/**
 * @brief   Deactivates the ADC peripheral.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop(ADCDriver *adcp) {

  /* If in ready state then disables the ADC clock.*/
  // if (adcp->state == ADC_READY) {
  //   SIM->SCGC6 &= ~SIM_SCGC6_ADC0;

// TODO:
// #if MIMXRT1062_ADC_USE_ADC0
//     if (&ADCD1 == adcp) {
//       /* Disable Interrupt, Disable Channel */
//       adcp->adc->SC1A = ADCx_SC1n_ADCH(ADCx_SC1n_ADCH_DISABLED);
//     }
// #endif
  // }
}

/**
 * @brief   Starts an ADC conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_start_conversion(ADCDriver *adcp) {
  // TODO:
  // const ADCConversionGroup *grpp = adcp->grpp;

  // /* Enable the Bandgap Buffer if channel mask includes BANDGAP */
  // if (grpp->channel_mask & ADC_BANDGAP) {
  //   PMC->REGSC |= PMC_REGSC_BGBE;
  // }

  // adcp->number_of_samples = adcp->depth * grpp->num_channels;
  // adcp->current_index = 0;

  // /* Skip to the next channel */
  // adcp->current_channel = 0;
  // while (((1 << adcp->current_channel) & grpp->channel_mask) == 0) {
  //   adcp->current_channel = (adcp->current_channel + 1) & ADC_CHANNEL_MASK;
  // }

  // /* Set clock speed and conversion size */
  // adcp->adc->CFG1 = grpp->cfg1;

  // /* Set averaging */
  // adcp->adc->SC3 = grpp->sc3;

  // /* Enable Interrupt, Select Channel */
  // adcp->adc->SC1A = ADCx_SC1n_AIEN | ADCx_SC1n_ADCH(adcp->current_channel);
}

/**
 * @brief   Stops an ongoing conversion.
 *
 * @param[in] adcp      pointer to the @p ADCDriver object
 *
 * @notapi
 */
void adc_lld_stop_conversion(ADCDriver *adcp) {
  // TODO:
  // const ADCConversionGroup *grpp = adcp->grpp;

  // /* Disable the Bandgap buffer if channel mask includes BANDGAP */
  // if (grpp->channel_mask & ADC_BANDGAP) {
  //   /* Clear BGBE, ACKISO is w1c, avoid setting */
  //   PMC->REGSC &= ~(PMC_REGSC_BGBE | PMC_REGSC_ACKISO);
  // }

}

#endif /* HAL_USE_ADC */

/** @} */
