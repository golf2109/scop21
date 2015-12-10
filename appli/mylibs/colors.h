#ifndef APPLI_MYLIBS_COLORS_H_
#define APPLI_MYLIBS_COLORS_H_

/**
 * \file colors.h
 * \brief Contient les d�finitions des couleurs utilis�es pour dessiner � l'�cran, et des fonctions associ�es
 * \author Fran�ois Leparoux
 * \version 1.8
 */

/**
 * 50 Nuances de Gris
 * (En RBG565)
 */
#define GREY_90	0xE71C
#define GREY_80	0xCE59
#define GREY_75	0xB5B6
#define GREY_70	0x94B2
#define GREY_50	0x7BEF
#define GREY_30	0x5ACB

/**
 * Les couleurs des signaux � afficher, de leur copie m�moire et du signal Maths
 * (En RBG565)
 */
#define COLOR_SIGNAL_1_ON 	0xF2EB
#define COLOR_SIGNAL_1_MEM 	0xFD95
#define COLOR_SIGNAL_2_ON 	0x678C
#define COLOR_SIGNAL_2_MEM 	0xAFB5
#define COLOR_SIGNAL_MATH 	0xF746

/*
 * Rappel : RGB888 -> RBG565 :
 * ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
 */

/**
 * \brief Permet de convertir une couleur encod�e en RBG565 en RGB888 BMP
 * \param rawBuff la couleur en RGB565 � convertir
 * \param bmpBuff le tableau � remplir : 0 -> bleu, 1-> vert, 2->rouge (cf sp�cifications BMP)
 */
void Color565ToBMP (uint16_t rawBuff, uint8_t *bmpBuff);

#endif
