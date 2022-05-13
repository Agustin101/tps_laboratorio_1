/*
 * ArrayPassenger.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Agustin
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bibliotecaESDeDatos.h"

#define PRIMERACLASE 1
#define EJECUTIVA 2
#define TURISTA 3

struct
{
	int   id;
	char  name[51];
	char  lastName[51];
	float price;
	char  flycode[10];
	int   typePassenger;
	int   isEmpty;
}typedef Passenger;

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[]);
int sortPassengersByFlyCode(Passenger* list, int len, int order);
int printPassenger(Passenger* list, int length);
int sortPassengersByName(Passenger* list, int len, int order);
int removePassenger(Passenger *list, int len, int id, char * flycodeAnterior) ;
int findPassengerById(Passenger* list, int len,int id);
int initPassengers(Passenger* list, int len);

int findFreeIndex(Passenger* list,int len);
int thereIsPassenger(Passenger * list, int len);

int findOccupedIndex(Passenger* list,int len);
int modifyPassenger(Passenger *list, int len, int id, char * flyCode, int * statusFlight, char * flycodeAnterior);

int promedioPassengers(Passenger * list, int len );

int forzedPassengers(Passenger * list);
int passengerId(void);
#endif /* ARRAYPASSENGER_H_ */
