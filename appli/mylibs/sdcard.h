/**
 * \file sdcard.h
 * \brief Contient le prototype de la machine � �tat de gestion de la carte SD
 * \author Fran�ois Leparoux
 * \version 1.4
 */

#ifndef APPLI_MYLIBS_SDCARD_H_
#define APPLI_MYLIBS_SDCARD_H_


/**
 * \union state_e
 * \brief Enum�ration des �tats possibles de la machine � �tats
 */
typedef enum {
	INIT = 0,
	MOUNT,
	PREPARE_WRITE,
	WRITE_TEST_FILE,
	READ_TEST_FILE,
	DELETE_TEST_FILE,
	END_WITH_ERROR,
	IDLE
} state_e;

/**
 * \brief Le statut courant de la machine � �tats de la carte SD
 */
extern state_e status;

/**
 * \brief Machine � �tat permettant la capture d'�cran puis l'enregistrement sur carte SD
 */
void SDCardMachine (void);

#endif /* APPLI_MYLIBS_SDCARD_H_ */
