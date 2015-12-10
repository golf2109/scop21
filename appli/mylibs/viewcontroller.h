/**
 * \file viewcontroller.h
 * \brief Contient la d�finition des fonctions de gestion des boutons tactiles
 * \author Fran�ois Leparoux
 * \version 1.1
 */

#ifndef APPLI_MYLIBS_VIEWCONTROLLER_H_
#define APPLI_MYLIBS_VIEWCONTROLLER_H_

#include "macro_types.h"
#include "stdint.h"

/**
 * \brief Dessine un bouton en 3D (style Windows 98)
 * Largeur et hauteur sont calcul�s automatiquement en fonction de la cha�ne de caract�res
 *
 * \param text La cha�ne de caract�res � �crire � l'�cran
 * \param x La position horizontale o� placer le texte
 * \param y La position verticale o� placer le texte
 * \param color La couleur en RGB565 du bouton
 * \param pressed L'�tat de la dalle tactile (en contact d'un doigt ou non)
 * \param touchX La position X du doigt utilisateur sur la dalle tactile
 * \param touchY La position Y du doigt utilisateur sur la dalle tactile
 *
 * \return 1 si d'apr�s les coordonn�es de l'�venement tactile, le bouton a �t� appuy�, 0 sinon
 */
char virtual3DButton(const char *text, int x, int y, const uint16_t color, int pressed, int touchX, int touchY);


#endif /* APPLI_MYLIBS_VIEWCONTROLLER_H_ */
