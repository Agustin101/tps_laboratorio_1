/*
 * ArrayVuelo.h
 *
 *  Created on: 8 may. 2022
 *      Author: Agustin
 */

#ifndef ARRAYVUELO_H_
#define ARRAYVUELO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ACTIVO 1
#define DEMORADO 2
#define CANCELADO 3

struct {
    char flyCode[10];
    int  statusFlight;
    int  isEmpty;
} typedef Vuelo;

int addVuelo(Vuelo* vuelos, int len,char flyCode[], int statusFlight);
int findFreeIndexFlight(Vuelo* list,int len);
int initVuelos(Vuelo * vuelos, int len);
int vuelosActivos(Vuelo *vuelos, int len, char array[][10]);
int bajaVuelos(Vuelo *vuelos, int len, char  flycode[]);

#endif /* ARRAYVUELO_H_ */
