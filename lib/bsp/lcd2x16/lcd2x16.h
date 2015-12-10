/**
 * @addtogroup lcd2x16
 *
 * Afficheur LCD 2 lignes de 16 caract�res.
 * 
 *
 * L'afficheur est utilis� en mode 4 bits. Les ports d'entr�e/sortie se d�composent par cons�quent en
 *    - trois bits de commande
 *    - quatre bits de donn�es
 *
 * Les bits de commande sont configur�es en sortie tandis que les bits de donn�es peuvent �tre acc�d�s
 * soit en lecture, soit en �criture.
 *
 * El�ments � modifier pour configurer l'�cran LCD :
 *    - pour la gestion des d�lais : #CLOCK_FREQUENCY
 *    - Configuration des ports de donn�es et de commande
 * @{
 */

/**
 * @file lcd2x16_c18.h
 *
 *  Driver d'afficheur LCD 2 lignes de 16 caract�res.
 *
 *  @version 1.3
 *  @date 24/08/2015
 */

#ifndef __LCD2X16_H
#define __LCD2X16_H

#include "stm32f4xx_hal.h"

/**
 * Bits du port de donn�es.
 * Adaptez ces configurations � votre design (ports et pins utilis�s).
 */
	#define PORT_DATA_0 GPIOD
	#define PORT_DATA_1 GPIOD
	#define PORT_DATA_2 GPIOD
	#define PORT_DATA_3 GPIOD
	#define	PIN_DATA_0	GPIO_PIN_8
	#define	PIN_DATA_1	GPIO_PIN_9
	#define	PIN_DATA_2	GPIO_PIN_10
	#define	PIN_DATA_3	GPIO_PIN_11
	
	#define PORT_RS		GPIOE
	#define PORT_RW		GPIOE
	#define PORT_E		GPIOE
	#define PIN_RS		GPIO_PIN_7
	#define PIN_RW		GPIO_PIN_11
	#define PIN_E		GPIO_PIN_12

	#define LCD2X16_HAL_CLOCK_ENABLE()	__HAL_RCC_GPIOD_CLK_ENABLE(); __HAL_RCC_GPIOE_CLK_ENABLE()



/**
 * Fonction d'initialisation du LCD.
 *
 * Cette fonction doit �tre appel�e pr�alablement � toute utilisation de l'�cran LCD.
 */
void LCD2X16_init(void);



/** Fonction d'�criture d'un caract�re sur le LCD. Cette fonction affiche un caract�re ascii sur l'afficheur	\n
 *  Il existe des caract�res de contr�le :																		\n
 *     - \\f  efface l'�cran																					\n
 *     - \\n  saut au d�but de la seconde ligne																	\n
 *     - \\b  retour arri�re d'un caract�re
 *     
 *     @param c le caract�re � afficher
 *     @pre     l'usage de cette fonction doit �tre pr�c�d� au moins une fois de l'appel � LCD2X16_init().
 *     @post    les bits du port de donn�es sont configur�s en �criture.
 *  */
void LCD2X16_putChar(char c);



/** Fonction de positionnement du curseur sur le LCD
 * 
 *    @param x indice de colonne (1 � 16)
 *    @param y indice de ligne (1 ou 2)
 *    @pre     l'usage de cette fonction doit �tre pr�c�d� au moins une fois de l'appel de LCD2X16_init()
 */
void LCD2X16_setCursor(unsigned char x, unsigned char y);



/** Fonction de lecture d'un caract�re sur le LCD.
 * 
 *    @param x indice de colonne du caract�re � lire (1 � 16)
 *    @param y indice de ligne du caract�re � lire (1 ou 2)
 *    @return  le caract�re lu en (x,y)
 *    @pre     l'usage de cette fonction doit �tre pr�c�d� au moins une fois de l'appel de LCD2X16_init()
 */
char LCD2X16_getChar( unsigned char x, unsigned char y);

/** Fonction devant �tre appel�e toutes les ms pour permettre un fonctionnement correct du pilote.
 */
void LCD2X16_process_1ms(void);

/** Fonction d'affichage d'une chaine formatt�e (cf printf)
 * 	@param  premier param�tre = chaine de format
 * 	@param  param�tres suivantes = selon les balises %x indiqu�es dans la cha�ne de format
 * 	@pre 	La chaine fabriqu�e ne DOIT PAS exc�der 20 caract�res (et en pratique 16 caract�res pour un �cran de 16 caract�res par lignes). *    @pre     l'usage de cette fonction doit �tre pr�c�d� au moins une fois de l'appel de LCD2X16_init()
 * 	@post	Si la cha�ne fabriqu�e exc�de 20 caract�res, un message est affich�e via printf.
 */
int	LCD2X16_printf(const char *__restrict, ...) __attribute__ ((__format__ (__printf__, 1, 2)));


/**
 * @}
 */
#endif
