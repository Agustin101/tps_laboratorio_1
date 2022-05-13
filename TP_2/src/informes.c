/*
 * listados.c
 *
 *  Created on: 13 may. 2022
 *      Author: Agustin
 */
#include "informes.h"

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



int printActivePassengers(Passenger *list, int length, char vuelosActivos[][10], Vuelo *vuelos) {
	char tipoPasajeroAux[16];
	char estadoDeVuelo[16];

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
						break;
					}
				}
			}
		}
	}
	return 0;
}























