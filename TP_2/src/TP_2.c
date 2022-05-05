#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaESDedatos.h"
#include "ArrayPassenger.h"

#define CANT_PASAJEROS 2   //deberian ser 2000


int main(void) {
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	int opcionSubmenu;
	int orderAux;

	//declaracion de variables auxiliares para la funcion addpassenger
	char nombreAux[51];
	char apellidoAux[51];
	float precioAux;
	char flyCodeAux[10];
	int typePassengerAux;
	int statusFlightAux;
	int r;
	int idAux;


	Passenger pasajero[CANT_PASAJEROS]; //INICIALIZO LA ESTRUCTURA CON LA CANTIDAD DE PASAJEROS ASIGNADA Y EL NOMBRE "PASAJERO" PARA CADA UNO DE LOS OBJETOS
	//Flight vuelo[CANT_PASAJEROS]; //INICIALIZO UNA SEGUNDA ESTRUCTURA CON LA CANTIDAD DE PASAJEROS ASIGNADA Y EL NOMBRE "VUELO" PARA CADA UNO DE LOS OBJETOS QUE LA COMPONEN
	initPassengers(pasajero,CANT_PASAJEROS); // inicializo todos los pasajeros con valor empty en true (1)
	//initPassengers(vuelo,CANT_PASAJEROS);
	do{
	if(utn_getInt(&opcionMenuPrincipal, "Bienvenido al sistema de altas de pasajeros, seleccione la opcion que necesite usar:\n1)Alta de pasajero\n2)Modififcar pasajero\n3)Baja de un pasajero\n4)Informes\n5)\n6)Cerrar programa.", "Por favor, ingrese una opcion valida.",1,6,2)==0){
		switch(opcionMenuPrincipal){
		case 1:     //ALTAS DE DE PASAJEROS
			if(findFreeIndex(pasajero,CANT_PASAJEROS) != -1){
			do{
				r =utn_getString(nombreAux, "Ingrese el nombre del pasajero:\n", "El nombre solo debe tener caracteres validos (letras y/o espacios.)",51);
			}while(r == -1);
			do{
				r= utn_getString(apellidoAux, "Ingrese el apellido del pasajero:\n", "El nombre solo debe tener caracteres validos (letras y/o espacios.)",51);
			}while(r == -1);
			if (utn_getFloat(&precioAux, "Ingrese el costo del viaje: \n", "Ingreso un precio invalido, intente nuevamente.", 50000, 1000000,1)== 0 && utn_getFlyCode(flyCodeAux, "Ingrese el codigo de vuelo:\n", "El codigo de vuelo debe constar de 10 caracteres alfanumericos. Ingreselo nuevamente: \n", 10, 1)==0&&utn_getInt(&typePassengerAux, "Ingrese el tipo de pasajero:\n1-Primera clase.\n2-Clase ejecutiva.\n3-Clase premium economica.\n4-Clase turista", "Por favor, ingrese una opcion valida.",1,4,2)==0 && utn_getInt(&statusFlightAux, "Ingrese el estado del vuelo:\n1-Activo.\n2-Cancelado.\n3-Demorado.\n", "Por favor, ingrese una opcion valida.",1,3,2) == 0){
				addPassenger(pasajero,CANT_PASAJEROS,idAux, nombreAux,apellidoAux,precioAux,typePassengerAux, flyCodeAux);
			}
			}
			else{
				mensajeErrorGenerico("No hay espacio disponible para arreglar pasajeros.\n");
			}
			break;
		case 2: //MODIFICACIONES DE PASAJEROS
			if(thereIsPassenger(pasajero, CANT_PASAJEROS)==1){
				if(utn_getInt(&idAux, "Ingrese el id del pasajero a modificar", "Por favor, ingrese una id valida.",0,16000,2) == 0){
					if((r =(findPassengerById(pasajero, 2, idAux)))== idAux){
						do{
							r = utn_getInt(&opcionSubmenu, "¿Que desea modificar?:\n1)Nombre\n2)Apellido\n3)Precio\n4)Tipo de pasajero\n5)Codigo de vuelo.\n6)Volver al menu principal", "Por favor, ingrese una opcion valida.",1,6,2);
							if(r == 0){
								switch(opcionSubmenu){
								case 1:
									do{
										r =utn_getString(nombreAux, "Ingrese el nuevo nombre del pasajero:\n", "El nombre solo debe tener caracteres validos (letras y/o espacios.)",51);
										if (r== 0){
											for(int i =0; i<CANT_PASAJEROS; i++){
												if(pasajero[i].id == idAux){
													strcpy(pasajero[i].name, nombreAux);
												}
											}
										}
									}while(r == -1);
									break;
								case 2:
									do{
										r =utn_getString(apellidoAux, "Ingrese el nuevo apellido del pasajero:\n", "El apellido solo debe tener caracteres validos (letras y/o espacios.)",51);
											if (r== 0){
												for(int i =0; i<CANT_PASAJEROS; i++){
													if(pasajero[i].id == idAux){
														strcpy(pasajero[i].lastName, apellidoAux);
													}
												}
										}
									}while(r == -1);
									break;
								case 3:
									do{
										r =utn_getFloat(&precioAux, "Ingrese el nuevo precio del viaje:\n", "Ingrese un precio valido.",30000,1000000,2);
										if (r== 0){
											for(int i =0; i<CANT_PASAJEROS; i++){
												if(pasajero[i].id == idAux){
													pasajero[i].price = precioAux;
												}
											}
										}
									}while(r == -1);
									break;
								case 4:
									do{
										utn_getInt(&typePassengerAux, "Ingrese el tipo de pasajero actual:\n1-Primera clase.\n2-Clase ejecutiva.\n3-Clase premium economica.\n4-Clase turista", "Por favor, ingrese una opcion valida.",1,4,2);
											if (r== 0){
												for(int i =0; i<CANT_PASAJEROS; i++){
													if(pasajero[i].id == idAux){
														pasajero[i].typePassenger = typePassengerAux;
													}
												}
											}
									}while(r == -1);
									break;
								case 5:
									do{
										utn_getFlyCode(flyCodeAux, "Ingrese el nuevo codigo de vuelo:\n", "El codigo de vuelo debe constar de 10 caracteres alfanumericos. Ingreselo nuevamente: \n", 10, 2);
											if (r== 0){
												for(int i =0; i<CANT_PASAJEROS; i++){
													if(pasajero[i].id == idAux){
														strcpy(pasajero[i].flycode, flyCodeAux);
													}
												}
											}
									}while(r == -1);
									break;
								case 6:
									printf("Volviendo al menu principal.\n");
								}
							}
						}while(opcionSubmenu !=6);
					}
					else{
						mensajeErrorGenerico("El id del pasajero no fue encontrado en el sistema.\n");
					}
				}
			}
			else{
				mensajeErrorGenerico("Aun no cargo ningun pasajero\n");
			}
			break;
		case 3: //BAJA DE CLIENTES correcta no hace falta cambiar 5/5/22
			if(thereIsPassenger(pasajero, CANT_PASAJEROS)==1){
					if(utn_getInt(&idAux,"Ingrese el id del pasajero que desea eliminar", "Indique un numero valido",0,16000,2)==0){
						removePassenger(pasajero, CANT_PASAJEROS, idAux);
					}
			}
			else{
				mensajeErrorGenerico("Aun no cargo ningun pasajero.\n");
			}
			break;
		case 4://INFORMES DE CLIENTES  arreglado 5/5/2022
			if(thereIsPassenger(pasajero, CANT_PASAJEROS)==1){
					if(utn_getInt(&opcionSubmenu, "¿De que manera desea ver el listado?\n1)Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero,\n2)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3)Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’ ", "Indique una opcion valida:\n",1,4,2)==0){
						switch(opcionSubmenu){
						case 1:
							if(utn_getInt(&orderAux, "Indique 0 para descendente o 1 para ascendente.", "Indique una opcion valida:\n",0,1,2)==0){
						printPassenger(pasajero, CANT_PASAJEROS);
						sortPassengersByName(pasajero, CANT_PASAJEROS, orderAux);
						printPassenger(pasajero, CANT_PASAJEROS);
							}
						}
					}
			}
			else{
				mensajeErrorGenerico("Aun no cargo ningun pasajero.\n");
			}
			break;
		case 5: //carga forzada
			break;
		case 6: //SALIR DEL PROGRAMA
			printf("Programa finalizado correctamente.");
			break;
		}

	}}while(opcionMenuPrincipal != 6);





	return 0;
}
