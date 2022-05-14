/*
 * listados.c
 *
 *  Created on: 13 may. 2022
 *      Author: Agustin
 */
#include "informes.h"


/// @brief Ordena los elementos en el array de pasajeros, el argumento indica ascendente o descendente
///
/// @param list Passenger*
/// @param vuelos Vuelo *
/// @param len int
/// @param order int [1] ascendente - [0] indicate descendente
/// @return Retorna (-1) si hay error  - (0) if Ok*
int sortPassengersByStatus(Passenger *list, Vuelo *vuelos, int len, int order) {

	int retorno;
	int i;
	int estaOrdenado;
	retorno = -1;
	Vuelo aux;

	if (list != NULL && vuelos != NULL && len > 0) {
		sortPassengersByFlyCode(list, len, order);

		if (order == 0) {
			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (vuelos[i].statusFlight < vuelos[i + 1].statusFlight) {
						aux = vuelos[i];
						vuelos[i] = vuelos[i + 1];
						vuelos[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			} while (estaOrdenado == 0);
		} else if (order == 1) {
			do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (vuelos[i].statusFlight > vuelos[i + 1].statusFlight) {
						aux = vuelos[i];
						vuelos[i] = vuelos[i + 1];
						vuelos[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			} while (estaOrdenado == 0);
			retorno = 0;
		}

	}
	return retorno;
}


/// @brief Imprime el contenido de los pasajeros activos
///
/// @param list Passenger *
/// @param length int
/// @param vuelosActivos Matriz de vuelos activos
/// @param vuelos Vuelo*
/// @return Retorna (-1) si hay error  - (0) if Ok*
int printActivePassengers(Passenger *list, int length, char vuelosActivos[][10], Vuelo *vuelos) {

	char tipoPasajeroAux[16];
	char estadoDeVuelo[16];
	int retorno = -1;

	if (list != NULL && length > 0 && vuelos != NULL && vuelosActivos != NULL) {

		for (int i = 0; i < length; i++) {


			if (list[i].isEmpty == 0 ) {
				for(int j = 0; j < length; j++){
					if(stricmp(list[i].flycode,vuelos[j].flyCode) ==0 && vuelos[j].isEmpty == 0 && vuelos[j].statusFlight == ACTIVO){
						switch(list[i].typePassenger){
									case PRIMERACLASE:
											strcpy(tipoPasajeroAux, "Primera clase");
										break;
									case EJECUTIVA:
											strcpy(tipoPasajeroAux, "Clase ejecutiva");
										break;
									case TURISTA:
											strcpy(tipoPasajeroAux, "Clase turista");
										break;
									}
									switch(vuelos[j].statusFlight){
									case ACTIVO:
											strcpy(estadoDeVuelo, "Activo");
										break;
									case DEMORADO:
											strcpy(estadoDeVuelo, "Demorado");
										break;
									case CANCELADO:
											strcpy(estadoDeVuelo, "Cancelado");
										break;
									}
						printf(	"\n\nNombre completo: %-15s%-15s Precio vuelo: $%-9.2f Codigo de vuelo:%-10s Tipo de pasajero: %-15s Id del pasajero: %-5i Estado de vuelo:%-10s\n\n",
												list[i].lastName, list[i].name, list[i].price,
												list[i].flycode, tipoPasajeroAux,
												 list[i].id,estadoDeVuelo);
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/// @brief Agrega en la lista de pasajeros existente 5 usuarios de manera automatica en los primeros 5 posiciones.
///
/// @param listPassenger *
/// @return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
int forzedPassengers(Passenger *list, Vuelo * vuelos) {
	int retorno;
	retorno = -1;

	if (list != NULL && vuelos != NULL) {

		list[0].isEmpty = 0;
		strcpy(list[0].name, "Pedro");
		strcpy(list[0].lastName, "Diaz");
		list[0].id = passengerId();
		list[0].price = 160000;
		list[0].typePassenger = 1;
		strcpy(list[0].flycode, "ADC123");
		strcpy(vuelos[0].flyCode, "ADC123");
		vuelos[0].statusFlight = ACTIVO;
		vuelos[0].isEmpty = 0;

		list[1].isEmpty = 0;
		strcpy(list[1].name, "Claudia");
		strcpy(list[1].lastName, "Diaz");
		list[1].id = passengerId();
		list[1].price = 120000;
		list[1].typePassenger = 2;
		strcpy(list[1].flycode, "ADC123");
		strcpy(vuelos[0].flyCode, "ADC123");
		vuelos[0].statusFlight =ACTIVO;
		vuelos[0].isEmpty = 0;

		list[2].isEmpty = 0;
		strcpy(list[2].name, "Agustin");
		strcpy(list[2].lastName, "Barberis");
		list[2].id = passengerId();
		list[2].price = 100000;
		list[2].typePassenger = 3;
		strcpy(list[2].flycode, "AGUS101");
		strcpy(vuelos[1].flyCode, "AGUS101");
		vuelos[1].statusFlight = ACTIVO;
		vuelos[1].isEmpty = 0;

		list[3].isEmpty = 0;
		strcpy(list[3].name, "Sol");
		strcpy(list[3].lastName, "Carpinetti");
		list[3].id = passengerId();
		list[3].price = 120000;
		list[3].typePassenger = 1;
		strcpy(list[3].flycode, "AGUS101");
		strcpy(vuelos[1].flyCode, "AGUS101");
		vuelos[1].statusFlight = ACTIVO;
		vuelos[1].isEmpty = 0;

		list[4].isEmpty = 0;
		strcpy(list[4].name, "Miguel");
		strcpy(list[4].lastName, "Barberis");
		list[4].id = passengerId();
		list[4].price = 100000;
		list[4].typePassenger = 2;
		strcpy(list[4].flycode, "TRP331");
		strcpy(vuelos[2].flyCode, "TRP331");
		vuelos[2].statusFlight = ACTIVO;
		vuelos[2].isEmpty = 0;
	}
	return retorno;
}





















