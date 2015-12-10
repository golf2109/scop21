#ifndef APPLI_MYLIBS_SCOPE_H_
#define APPLI_MYLIBS_SCOPE_H_

/**
 * \file scope.h
 * \brief Contient les prototypes des fonctions de gestion de l'oscilloscope
 * \author Fran�ois Leparoux
 * \version 1.2
 */

// Biblioth�ques n�cessaires
#include "stm32f4_lcd.h"
#include "lcd_display_form_and_text.h"
#include "colors.h"

/**
 * \brief Texte des boutons tactiles
 */
extern const char *STR_BUTTONS_VALUES[];

/**
 * \brief Couleurs des boutons tactiles (en RBG565)
 */
extern const uint16_t COLORS_BUTTONS_VALUES[];

/**
 * \brief Initialise le fond de l'�cran et la police utilis�e
 */
void ScreenInitGraphics (void);

/**
 * \brief Met � jour l'�cran du scope : Oscar de la fonction avec le plus de param�tres.
 * \param data_scope Le tableau des valeurs de CH1
 * \param data_scope2 Le tableau des valeurs de CH2
 * \param data_scope_mem Le tableau des valeurs de CH1 m�moire
 * \param data_scope_mem2 Le tableau des valeurs de CH2 m�moire
 * \param data_scope_math Le tableau des valeurs de la fonction Math
 * \param copyChannel1 La variable permettant d'afficher ou non le signal CH1 mem � l'�cran
 * \param copyChannel2 La variable permettant d'afficher ou non le signal CH2 mem � l'�cran
 * \param copyChannelMath La variable permettant d'afficher ou non le sigal issu de la fonction math � l'�cran
 * \param cursorA La valeur du positionnement vertical du curseur A
 * \param cursorB La valeur du positionnement vertical du curseur B
 * \param textMaths Le texte associ� � l'�tat actuel de la fonction math (son mode, l'op�ration effectu�e, etc)
 * \param textCursorA Le texte indiquant la valeur mesur�e par le curseur A
 * \param textCursorB Le texte indiquant la valeur mesur�e par le curseur B
 */
void ScreenUpdate (	int8_t *data_scope, char copyChannel1, int8_t *data_scope_mem,
					int8_t *data_scope2, char copyChannel2, int8_t *data_scope_mem2,
					char copyChannelMath, int8_t *data_scope_math, char *textMaths,
					int16_t cursorA, char *textCursorA, int16_t cursorB, char *textCursorB);

/**
 * \brief 	Permet de convertir une valeur en pixel horizontal sur l'�cran en volt (depuis l'�cran virtuel du scope)
 * 			Haut de l'�cran : y = 36 pixels => V = 3.3V (convertisseur ADC 256 bits)
 * 			Bas de l'�cran : y = 236 pixels => V = 0.0V
 * \param valY la valeur en pixels verticaux de la positon du curseur � mesurer
 * \return La valeur en volt de la mesure curseur
 */
float pixelToVolt (uint8_t valY);


#endif
