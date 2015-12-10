/**
 * \file timer.h
 * \brief Contient la d�finition des fonctions de gestion du Timer 3 (cadencement th�orique de l'ADC). Non Utilis�.
 * \author Tim� Kadel
 * \version 1.1
 */

#ifndef TIMER_H_
#define TIMER_H_

void TIMER3_init_for_1ms(void); //initialise et param�tre le timer
void TIMER3_run(void); //lance le timer
void TIMER3_stop(void); //arr�te le timer
void TIM3_IRQHandler(void); //Interruption provoqu�e par le timer
void TIMER3_user_handler_it_1ms(void); //fonction de l�utilisateur
/*
typedef struct  Tim2_Handle{
	unsigned int Prescaler;
	int CounterMode;
	int period;
	int ClockDivision;
	int RepetitionCounter;
};
*/
#endif /* TIMER_H_*/
