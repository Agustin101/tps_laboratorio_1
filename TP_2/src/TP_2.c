#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaESDedatos.h"
#include "ArrayPassenger.h"

#define CANT_PASAJEROS 2   //deberian ser 2000


int main(void) {
	setbuf(stdout, NULL);
	int opcionMenuPrincipal;
	int flagCargoPasajero;
	//declaracion de variables auxiliares para la funcion addpassenger
	char nombreAux[51];
	char apellidoAux[51];
	float precioAux;
	char flyCodeAux[10];
	int typePassengerAux;
	int statusFlightAux;
	int r;
	int idAux;
	idAux=0;
	flagCargoPasajero = 0;
	Passenger pasajero[CANT_PASAJEROS]; //INICIALIZO LA ESTRUCTURA CON LA CANTIDAD DE PASAJEROS ASIGNADA Y EL NOMBRE "PASAJERO" PARA CADA UNO DE LOS OBJETOS
	//Flight vuelo[CANT_PASAJEROS]; //INICIALIZO UNA SEGUNDA ESTRUCTURA CON LA CANTIDAD DE PASAJEROS ASIGNADA Y EL NOMBRE "VUELO" PARA CADA UNO DE LOS OBJETOS QUE LA COMPONEN
	initPassengers(pasajero,CANT_PASAJEROS); // inicializo todos los pasajeros con valor empty en true (1)
	//initPassengers(vuelo,CANT_PASAJEROS);
	do{
	if(utn_getInt(&opcionMenuPrincipal, "Bienvenido al sistema de altas de pasajeros, seleccione la opcion que necesite usar:\n1)Alta de pasajero\n2)Modififcar pasajero\n3)Baja de un pasajero\n4)Informes\n5)Cerrar programa.", "Por favor, ingrese una opcion valida.",1,5,2)==0){

		switch(opcionMenuPrincipal){
		case 1:     //ALTAS DE DE PASAJEROS
			do{
				r =utn_getString(nombreAux, "Ingrese el nombre del pasajero:\n", "El nombre solo debe tener caracteres validos (letras y/o espacios.)",51);
			}while(r == -1);
			do{
				r= utn_getString(apellidoAux, "Ingrese el apellido del pasajero:\n", "El nombre solo debe tener caracteres validos (letras y/o espacios.)",51);
			}while(r == -1);
			if (utn_getFloat(&precioAux, "Ingrese el costo del viaje: \n", "Ingreso un precio invalido, intente nuevamente.", 50000, 1000000,1)== 0 && utn_getFlyCode(flyCodeAux, "Ingrese el codigo de vuelo:\n", "El codigo de vuelo debe constar de 10 caracteres alfanumericos. Ingreselo nuevamente: \n", 10, 1)==0&&utn_getInt(&typePassengerAux, "Ingrese el tipo de pasajero:\n1-Primera clase.\n2-Clase ejecutiva.\n3-Clase premium economica.\n4-Clase turista", "Por favor, ingrese una opcion valida.",1,4,2)==0 && utn_getInt(&statusFlightAux, "Ingrese el estado del vuelo:\n1-Activo.\n2-Cancelado.\n3-Demorado.\n", "Por favor, ingrese una opcion valida.",1,3,2) == 0){
				addPassenger(pasajero,CANT_PASAJEROS,idAux, nombreAux,apellidoAux,precioAux,typePassengerAux, flyCodeAux);
				flagCargoPasajero = 1;
			}
			else{
				printf("La carga de los datos del pasajero sufrio un error, volviendo al menu principal");
			}
			break;
		case 2: //MODIFICACIONES DE PASAJEROS
			if(flagCargoPasajero == 1){
				if(utn_getInt(&idAux, "Ingrese el id del pasajero a modificar", "Por favor, ingrese una opcion valida.",0,2000,2) == 0){
					if((r =(findPassengerById(pasajero, 2, idAux)))== idAux){
						do{
							r = utn_getInt(&opcionMenuPrincipal, "¿Que desea modificar?:\n1)Nombre\n2)Apellido\n3)Precio\n4)Tipo de pasajero\n5)Codigo de vuelo.\n6)Volver al menu principal", "Por favor, ingrese una opcion valida.",1,6,2);
							if(r == 0){
								switch(opcionMenuPrincipal){
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
										r =utn_getFloat(precioAux, "Ingrese el nuevo precio del viaje:\n", "Ingrese un precio valido.",30000,10000,2);
										if (r== 0){
											for(int i =0; i<CANT_PASAJEROS; i++){
												if(pasajero[i].id == idAux){
													pasajero[i].price = precioAux;
												}
											}
										}
									}while(r == -1);
									break;
								}
							}
						}while(opcionMenuPrincipal !=6);
					}
					else{
						printf("El id del pasajero no fue encontrado en el sistema.");
					}
				}
			}
			else{
				printf("Aun no cargo ningun pasajero.");
			}
			break;
		case 3: //BAJA DE CLIENTES
			/*do{

			}while();*/
			break;
		case 4://INFORMES DE CLIENTES
			printf("\n\n  Nombre completo:%s %s Precio vuelo: %.2f Codigo de vuelo: %s tipo de pasajero: %i estado de vuelo:  id del pasajero: %i\n\n",pasajero[0].lastName, pasajero[0].name, pasajero[0].price, pasajero[0].flycode, pasajero[0].typePassenger,pasajero[0].id);
			printf("\n\n  Nombre completo:%s %s Precio vuelo: %.2f Codigo de vuelo: %s tipo de pasajero: %i estado de vuelo:  Id del pasajero: %i\n\n",pasajero[1].lastName, pasajero[1].name, pasajero[1].price, pasajero[1].flycode, pasajero[1].typePassenger,pasajero[1].id);
			break;
		case 5: //SALIR DEL PROGRAMA
			printf("Programa finalizado correctamente.");
			break;
		}

	}}while(opcionMenuPrincipal != 5);





	return 0;
}
