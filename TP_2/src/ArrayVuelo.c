/*
 * ArrayVuelo.c
 *
 *  Created on: 8 may. 2022
 *      Author: Agustin
 */

#include "arrayVuelo.h"

int initVuelos(Vuelo *vuelos, int len) {
	int retorno;
	retorno = -1;

	if (vuelos != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			vuelos[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int addVuelo(Vuelo *vuelos, int len, char flyCode[], int statusFlight) {
	int retorno;
	int indiceVacio;
	int flagCargoVuelo;
	retorno = -1;
	flagCargoVuelo = 0;

	if (vuelos != NULL && len > 0 && flyCode != NULL && statusFlight > 0) {
		for (int i = 0; i < len; i++) {
			if(vuelos[i].isEmpty == 0){
			if (stricmp(flyCode, vuelos[i].flyCode) == 0) {
				vuelos[i].statusFlight = statusFlight;
				flagCargoVuelo = 1;
				break;
			}
			}
		}
		if (flagCargoVuelo == 0) {
			indiceVacio = findFreeIndexFlight(vuelos, len);
			strncpy(vuelos[indiceVacio].flyCode, flyCode,
					sizeof(vuelos[indiceVacio].flyCode));
			vuelos[indiceVacio].statusFlight = statusFlight;
			vuelos[indiceVacio].isEmpty = 0;

		}
	}
	return retorno;
}
/*
int modificarVuelos(Vuelo *vuelos, int len, char flyCode[], int statusFlight) {
	int retorno;
	int indiceVacio;
	int flagCargoVuelo;
	retorno = -1;
	flagCargoVuelo = 0;

	if (vuelos != NULL && len > 0 && flyCode != NULL && statusFlight > 0) {
		for (int i = 0; i < len; i++) {
			if (stricmp(flyCode, vuelos[i].flyCode) == 0 && vuelos[i].isEmpty == 0) {
				vuelos[i].statusFlight = statusFlight;
				flagCargoVuelo = 1;
				break;
			}
		}
		if (flagCargoVuelo == 0) {
			indiceVacio = findFreeIndexFlight(vuelos, len);
			strncpy(vuelos[indiceVacio].flyCode, flyCode,
					sizeof(vuelos[indiceVacio].flyCode));
			vuelos[indiceVacio].statusFlight = statusFlight;
			vuelos[indiceVacio].isEmpty = 0;
		}
	}
	return retorno;
}
*/
/// @brief Finds a free index in the array of flights
///
/// @param list Vuelo*
/// @param len int
/// @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - free index if Ok
int findFreeIndexFlight(Vuelo *list, int len) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 1) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int vuelosActivos(Vuelo *vuelos, int len, char array[][10]) {
	int retorno = -1;
	int j = 0;
	if (vuelos != NULL && len > 0 && array != NULL) {
		for (int i = 0; i < len; i++) {
			if (vuelos[i].isEmpty == 0 && vuelos[i].statusFlight == ACTIVO) { // 1 ES ACTIVO
				strncpy(array[j], vuelos[i].flyCode, 10);
				j++;
				break;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int bajaVuelos(Vuelo *vuelos, int len, char flycode[]){
	int retorno = -1;

		if(vuelos != NULL && len >0 && flycode!= NULL){
			for(int i = 0; i < len; i++){
				if(vuelos[i].isEmpty == 0 && stricmp(vuelos[i].flyCode, flycode) == 0){
					vuelos[i].isEmpty=1;
					break;
				}
				retorno = 0;
			}
		}

	return retorno;
}
