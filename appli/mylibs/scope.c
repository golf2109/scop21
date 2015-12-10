/**
 * \file scope.c
 * \brief Contient les code source des fonctions de gestion de l'oscilloscope
 * \author Fran�ois Leparoux
 * \version 1.2
 */

#include "scope.h"

/**
 * \brief Texte des boutons tactiles
 */
const char *STR_BUTTONS_VALUES[] = {"START", " CH1 ", " CH2 ", "MATH ", " BMP "};

/**
 * \brief Couleurs des boutons tactiles (en RBG565)
 */
const uint16_t COLORS_BUTTONS_VALUES[] = {0xC639, COLOR_SIGNAL_1_MEM, COLOR_SIGNAL_2_MEM, 0xC639, LCD_COLOR_BLUE2};

/**
 * \brief Initialise le fond de l'�cran et la police utilis�e
 */
void ScreenInitGraphics (void) {
	LCD_Clear(GREY_50);
	LCD_SetFont(&Font8x12);
}

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
					int16_t cursorA, char *textCursorA, int16_t cursorB, char *textCursorB) {

	unsigned char i;

	// Virtual screen
	LCD_DrawFullRect(5, 35, 300, 200, GREY_75, GREY_30);

	// Middle lines
	LCD_DrawLine(6, 136, 299, LCD_DIR_HORIZONTAL, GREY_50);
	LCD_DrawLine(155, 36, 199, LCD_DIR_VERTICAL, GREY_50);

	// Draw data lines on screen
	for (i=1;i<100;i++) { // TODO CSTE

		// Channel 1
		LCD_DrawUniLine((i-1)*3+6, (signed int)(136-(data_scope[i-1])),i*3+6, (signed int)(136-(data_scope[i])), COLOR_SIGNAL_1_ON);

		// Channel 1 memory copy if enabled
		if (copyChannel1 == 2) LCD_DrawUniLine((i-1)*3+6, (signed int)(136-(data_scope_mem[i-1])),i*3+6, (signed int)(136-(data_scope_mem[i])), COLOR_SIGNAL_1_MEM);

		// Channel 2
		LCD_DrawUniLine((i-1)*3+6, (signed int)(136-(data_scope2[i-1])),i*3+6, (signed int)(136-(data_scope2[i])), COLOR_SIGNAL_2_ON);

		// Channel 2 memory copy if enabled
		if (copyChannel2 == 2) LCD_DrawUniLine((i-1)*3+6, (signed int)(136-(data_scope_mem2[i-1])),i*3+6, (signed int)(136-(data_scope_mem2[i])), COLOR_SIGNAL_2_MEM);

		// Math memory copy if enabled
		if (copyChannelMath != 0) LCD_DrawUniLine((i-1)*3+6, (signed int)(136-(data_scope_math[i-1])),i*3+6, (signed int)(136-(data_scope_math[i])), COLOR_SIGNAL_MATH);

	}

	// Draw cursors on screen

	// Horizontal cursors
	LCD_DrawLine(6, cursorA, 298, LCD_DIR_HORIZONTAL, LCD_COLOR_MAGENTA);
	LCD_DrawLine(6, cursorB, 298, LCD_DIR_HORIZONTAL, LCD_COLOR_MAGENTA);

	// Text for cursors
	LCD_DisplayStringLine(cursorA >= 57 ? cursorA - 15 : cursorA + 3,8,(uint8_t *)textCursorA,LCD_COLOR_WHITE,LCD_COLOR_MAGENTA,LCD_NO_DISPLAY_ON_UART);
	LCD_DisplayStringLine(cursorB - 15,8,(uint8_t *)textCursorB,LCD_COLOR_WHITE,LCD_COLOR_MAGENTA,LCD_NO_DISPLAY_ON_UART);

	// Math mode on screen
	LCD_DisplayStringLine(40,150,(uint8_t *)textMaths,LCD_COLOR_WHITE,COLOR_SIGNAL_MATH,LCD_NO_DISPLAY_ON_UART);

}


/**
 * \brief 	Permet de convertir une valeur en pixel horizontal sur l'�cran en volt (depuis l'�cran virtuel du scope)
 * 			Haut de l'�cran : y = 36 pixels => V = 3.3V (convertisseur ADC 256 bits)
 * 			Bas de l'�cran : y = 236 pixels => V = 0.0V
 * \param valY la valeur en pixels verticaux de la positon du curseur � mesurer
 * \return La valeur en volt de la mesure curseur
 */
float pixelToVolt (uint8_t valY) {
	return (236-valY)/60.6;
}
