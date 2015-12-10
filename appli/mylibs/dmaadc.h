/**
 * \file dmaadc.h
 * \brief Contient la d�finition des fonctions permettant l'initialisation et la gestion des p�riph�riques ADC et DMA
 * \author Tim� Kadel
 * \version 2.5
 */

#ifndef APPLI_MYLIBS_DMAADC_H_
#define APPLI_MYLIBS_DMAADC_H_

#include "stm32f4xx_hal.h"
#include "stm32f4_gpio.h"
#include "stm32f4_uart.h"
#include "stm32f4_timer.h"
#include "stm32f4_sys.h"
#include "macro_types.h"

// Le nombre de samples n�cessaires
#define BUFFER_SIZE 100

extern volatile uint32_t ADC_Buff_channel1[BUFFER_SIZE*2];
extern volatile uint32_t ADC_Buff_channel2[BUFFER_SIZE*2];

// Handler
extern volatile ADC_HandleTypeDef g_AdcHandle;
extern volatile ADC_HandleTypeDef g_AdcHandle2;
extern volatile DMA_HandleTypeDef g_DmaHandle;
extern volatile DMA_HandleTypeDef g_DmaHandle2;

/**
 * \brief Initialise les p�riph�riques ADC et DMA pour qu'ils fonctionnent ensemblent
 */
void DmaAdcInit (void);

/**
 * \brief Lance les p�riph�riques
 */
void DmaAdcStart (void);

/**
 * \brief Coupe l'acquisition
 */
void DmaAdcStop (void);

/**
 * \brief Configure le p�riph�rique ADC
 */
void ConfigureADC (void);

/**
 * \brief Configure le p�riph�rique DMA
 */
void ConfigureDMA (void);


#endif /* APPLI_MYLIBS_DMAADC_H_ */
