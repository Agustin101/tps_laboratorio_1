#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaESDedatos.h"
#include "ArrayPassenger.h"
#include "ArrayVuelo.h"
#include "informes.h"

#define CANT_PASAJEROS 4 //deberian ser 2000

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	int opcionSubmenu;
	int orderAux;
	char codigoDeVuelos[CANT_PASAJEROS][10];

	//declaracion de variables auxiliares para la funcion addpassenger
	char nombreAux[51];
	char apellidoAux[51];
	float precioAux;
	char flyCodeAux[10];
	int typePassengerAux;
	int statusFlightAux;
	int idAux;
	char flycodeAnterior[10];

	Passenger pasajero[CANT_PASAJEROS];
	Vuelo vuelos[CANT_PASAJEROS];
	initPassengers(pasajero, CANT_PASAJEROS);
	initVuelos(vuelos, CANT_PASAJEROS);

	do {
		if (utn_getInt(&opcionMenuPrincipal,
				"Bienvenido al sistema. ¿Que desea hacer?\n1)Alta de pasajero.\n2)Modificar pasajero.\n3)Baja de un pasajero.\n4)Informes.\n5)Carga forzada de 5 pasajeros.\n6)Cerrar programa.",
				"Por favor, ingrese una opcion valida.", 1, 6, 2) == 0) {
			switch (opcionMenuPrincipal) {
			case 1:     //ALTAS DE DE PASAJEROS OK 8/5/22
				if (findFreeIndex(pasajero, CANT_PASAJEROS) != -1) {
					if (getString(nombreAux,
							"Introduzca el nombre del pasajero:\n",
							"El nombre no pudo ser validado.\n", 2) == 0
							&& getString(apellidoAux,
									"Introduzca el apellido del pasajero:\n",
									"El apellido no pudo ser validado, ingreselo nuevamente:\n",
									2) == 0
							&& utnGetFloat(&precioAux,
									"Ingrese el precio del viaje:",
									"El valor es incorrecto, ingreselo nuevamente:\n",
									10000, 1000000, 2) == 0
							&& utn_getFlyCode(flyCodeAux,
									"Ingrese el codigo de vuelo:\n",
									"Error, ingrese un codigo alfanumerico:", 2)
									== 0
							&& utn_getInt(&typePassengerAux,
									"Ingrese el tipo de pasajero:\n1-Primera clase.\n2-Clase ejecutiva.\n3-Clase turista",
									"Por favor, ingrese una opcion valida.", 1,
									3, 2) == 0
							&& utn_getInt(&statusFlightAux,
									"Ingrese el estado del vuelo:\n1-Activo.\n2-Demorado.\n3-Cancelado.\n",
									"Por favor, ingrese una opcion valida.", 1,
									3, 2) == 0) {
						addPassenger(pasajero, CANT_PASAJEROS, idAux, nombreAux,
								apellidoAux, precioAux, typePassengerAux,
								flyCodeAux);
						addVuelo(vuelos, CANT_PASAJEROS, flyCodeAux,
								statusFlightAux);
						vuelosActivos(vuelos, CANT_PASAJEROS, codigoDeVuelos);
					} else {
						mensajeGenerico(
								"\n\n\n*******************************************\nError en la carga de pasajero, volviendo al menu principal.\n");
					}
				} else {
					mensajeGenerico(
							"No hay espacio disponible para agregar pasajeros.\n");
				}
				break;
			case 2: //MODIFICACIONES DE PASAJEROS OK 8/5/22 excpeto que si modifica un vuelo cancelado no acutaliza
				if (thereIsPassenger(pasajero, CANT_PASAJEROS) == 1) {
					if (utn_getInt(&idAux,
							"Ingrese el id del pasajero que desea modificar:\n",
							"Por favor, ingrese una id valida.", 1000, 70000, 2)
							== 0) {
						modifyPassenger(pasajero, CANT_PASAJEROS, idAux,
								flyCodeAux, &statusFlightAux, flycodeAnterior);
						addVuelo(vuelos, CANT_PASAJEROS, flyCodeAux,
								statusFlightAux);
						for (int i = 0; i < CANT_PASAJEROS; i++) {
							if (pasajero[i].isEmpty == 0) {
								for (int j = 0; j < CANT_PASAJEROS; j++) {
									if (pasajero[i].flycode
											!= vuelos[j].flyCode) {
										bajaVuelos(vuelos, CANT_PASAJEROS,
												flycodeAnterior);
									}
								}
							}

						}
						vuelosActivos(vuelos, CANT_PASAJEROS, codigoDeVuelos);
					}
				} else {
					mensajeGenerico("Aun no cargo ningun pasajero\n");
				}
				break;
			case 3: //BAJA DE CLIENTES OK 8/5/22
				if (thereIsPassenger(pasajero, CANT_PASAJEROS) == 1) {
					if (utn_getInt(&idAux,
							"Ingrese el id del pasajero que desea eliminar",
							"Indique un numero valido", 0, 16000, 2) == 0) {
						removePassenger(pasajero, CANT_PASAJEROS, idAux,
								flycodeAnterior);
						bajaVuelos(vuelos, CANT_PASAJEROS, flycodeAnterior);
						vuelosActivos(vuelos, CANT_PASAJEROS, codigoDeVuelos);
					}
				} else {
					mensajeGenerico("Aun no cargo ningun pasajero.\n");
				}
				break;
			case 4: //INFORMES DE CLIENTES  en proceso
				if (thereIsPassenger(pasajero, CANT_PASAJEROS) == 1) {
					if (utn_getInt(&opcionSubmenu,
							"¿De que manera desea ver el listado?\n1)Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero,\n2)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3)Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n4)Volver al menu principal. ",
							"Indique una opcion valida:\n", 1, 4, 2) == 0) {
						switch (opcionSubmenu) {
						case 1: //solo primer listado ordenado por apellido y por tipo de pasajero
							if (utn_getInt(&orderAux,
									"Indique 0 para descendente o 1 para ascendente.",
									"Indique una opcion valida:\n", 0, 1, 2)
									== 0) {
								sortPassengersByName(pasajero, CANT_PASAJEROS,
										orderAux);
								printPassenger(pasajero, CANT_PASAJEROS);
								printf("Presione enter para continuar...");
								fflush(stdin);
								getchar();
							}
							break;
						case 2:
							promedioPassengers(pasajero, CANT_PASAJEROS);
							break;
						case 3:
							if (utn_getInt(&orderAux,
									"Indique 0 para descendente o 1 para ascendente.",
									"Indique una opcion valida:\n", 0, 1, 2)
									== 0) {
								vuelosActivos(vuelos, CANT_PASAJEROS,
										codigoDeVuelos);
								sortPassengersByStatus(pasajero, vuelos,
										CANT_PASAJEROS, orderAux);
								printActivePassengers(pasajero, CANT_PASAJEROS,
										codigoDeVuelos, vuelos);
								printf("Presione enter para continuar...");
								fflush(stdin);
								getchar();
							}
							break;
						case 4:
							break;
						}
					}
				} else {
					mensajeGenerico("Aun no cargo ningun pasajero.\n");
				}
				break;
			case 5: //carga forzada
				forzedPassengers(pasajero);
				printPassenger(pasajero, CANT_PASAJEROS);
				break;
			case 6: //SALIR DEL PROGRAMA
				mensajeGenerico("Programa finalizado correctamente.\n");
				break;
			}
		}
	} while (opcionMenuPrincipal != 6);
	return 0;
}
