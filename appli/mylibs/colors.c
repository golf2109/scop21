/**
 * \file colors.c
 * \brief Contient le code source des couleurs utilis�es pour dessiner � l'�cran, et quelques fonctions utiles
 * \author Fran�ois Leparoux
 * \version 1.8
 */

#include "stm32f4xx_hal.h"
#include "colors.h"
#include "macro_types.h"

/**
 * \brief Permet de convertir une couleur encod�e en RBG565 en RGB888 BMP
 * \param rawBuff la couleur en RGB565 � convertir
 * \param bmpBuff le tableau � remplir : 0 -> bleu, 1-> vert, 2->rouge (cf sp�cifications BMP)
 */
void Color565ToBMP (uint16_t rawBuff, uint8_t *bmpBuff) {

	bmpBuff[2] = (rawBuff >> 8) & 0xF8; // RED
	bmpBuff[1] = (rawBuff >> 3) & 0xFC; // GREEN
	bmpBuff[0] = rawBuff << 3; 		 	// BLUE
}
