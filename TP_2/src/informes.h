/*
 * listados.h
 *
 *  Created on: 13 may. 2022
 *      Author: Agustin
 */

#ifndef LISTADOS_H_
#define LISTADOS_H_

#include "ArrayPassenger.h"
#include "ArrayVuelo.h"

int sortPassengersByStatus(Passenger *list, Vuelo *vuelos, int len, int order);
int printActivePassengers(Passenger *list, int length, char vuelosActivos[][10], Vuelo *vuelos);
int forzedPassengers(Passenger *list, Vuelo * vuelos);




#endif /* LISTADOS_H_ */
