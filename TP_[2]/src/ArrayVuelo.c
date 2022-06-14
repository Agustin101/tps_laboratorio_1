/*
 * ArrayVuelo.c
 *
 *  Created on: 8 may. 2022
 *      Author: Agustin
 */

#include "arrayVuelo.h"
/// @brief To indicate that all position in the array are empty,* this function put the flag (isEmpty)
///* in TRUE in all* position of the array
///
/// @param vuelos Vuelo* Pointer to array of passenger
/// @param len int Array length
/// @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
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
/// @brief Agrega en una lista de vuelox existente los valores recibidos por parametro en la primer posicion con isempty en 0
///
/// @param vuelos Vuelo*
/// @param len int
/// @param flyCode[] char
/// @param statusFlight int
/// @return Retorna -1 si hubo un error - 0 si pudo cargar correctamente
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
				retorno = 0;
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
			retorno = 0;
		}
	}
	return retorno;
}
/// @brief Recibe por parametro una flag que le permite modificar el estado de un vuelo si este fue cambiado
/// en el main.
///
/// @param vuelos Vuelo
/// @param len INT
/// @param flyCode Codigo de vuelo que recibe para activar o modificar
/// @param statusFlight  Estado de vuelo que recibe para activar o modificar
/// @param flagModifico Bandera
/// @return Retorna -1 si no recibio un parametro valido - 0 si pudo modificar
int modificarVuelos(Vuelo *vuelos, int len, char flyCode[], int statusFlight, int flagModifico) {
	int retorno;
	int indiceVacio;
	int flagCargoVuelo;
	retorno = -1;
	flagCargoVuelo = 0;

	if (vuelos != NULL && len > 0 && flyCode != NULL && statusFlight > 0) {
		if(flagModifico == 1){
			for (int i = 0; i < len; i++) {
				if (stricmp(flyCode, vuelos[i].flyCode) == 0 && vuelos[i].isEmpty == 0) {
					vuelos[i].statusFlight = statusFlight;
					flagCargoVuelo = 1;
				break;
				}
			}
		if (flagCargoVuelo == 0) {
			indiceVacio = findFreeIndexFlight(vuelos, len);
			strncpy(vuelos[indiceVacio].flyCode, flyCode,sizeof(vuelos[indiceVacio].flyCode));
			vuelos[indiceVacio].statusFlight = statusFlight;
			vuelos[indiceVacio].isEmpty = 0;
		}
		}
		retorno = 0;
	}
	return retorno;
}

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
/// @brief Carga en una matriz paralela los datos de todos los vuelos activos
///
/// @param vuelos Array de vuelos
/// @param len int
/// @param array Matriz de vuelos activos que retorna
/// @return Retorna 0 si pudo cargar el vuelo en la matriz - -1 si no
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
/// @brief Remove a flight by Id (put isEmpty Flag in 1)
///
/// @param vuelos Vuelo*
/// @param len int
/// @param flycode char
/// @return Return (-1) if Error [Invalid length or NULL pointer or if can't find the flight] - (0) if Ok
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

/// @brief find a flight by Id and returns the index position in array.*
///
/// @param list flight*
/// @param len int
/// @param flyCode char
/// @return Return flight index position or (-1) if [Invalid length or NULL pointer received or flight not found]
int findFlightById(Vuelo *list, int len, char flyCode[]) {
	int retorno;
	retorno = -1;

	if (list != NULL && len > 0 && flyCode != NULL) {
		for (int i = 0; i < len; i++) {
			if (stricmp(list[i].flyCode, flyCode) && list[i].isEmpty == 0) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/// @brief Verifica si hay al menos un pasajero cargado en el array de pasajeros.
///
/// @param vuelos Vuelo*
/// @param len int
/// @return Retorna (-1) si tiene error o no puede encontrar un pasajero - 1 si al menos hay uno.
int thereIsFlight(Vuelo *vuelos, int len) {
	int retorno;
	retorno = -1;

	if (vuelos != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if (vuelos[i].statusFlight == 0) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

























