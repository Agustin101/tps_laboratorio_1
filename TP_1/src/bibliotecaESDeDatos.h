/*
 * utn.h
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */


#ifndef BIBLIOTECAESDEDATOS_H_
#define BIBLIOTECAESDEDATOS_H_

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);
int pedirKilometros(int * pKilometrosIngresados);
int pedirCosto(float * pCosto, char*pMensajeDeError, int reintentos);
int mostrarResultados(int kmsIngresados, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin, float precioUnitarioAerolineas,
		float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioUnitarioLatam, float diferenciaDePrecio);
#endif /* BIBLIOTECAESDEDATOS_H_ */
