#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	FILE* pFile = NULL;
	int retorno = -1;
	pFile = fopen(path, "r");

	if(path != NULL && pArrayListPassenger != NULL){
		if(pFile != NULL && !parser_PassengerFromText(pFile, pArrayListPassenger)){
				retorno = 0;
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
	FILE* pFile = NULL;
	int retorno = -1;

	if(path != NULL && pArrayListPassenger != NULL){
		pFile = fopen(path, "rb");
		if(pFile != NULL && ! parser_PassengerFromBinary(pFile, pArrayListPassenger)){
				retorno = 0;
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger){
    int retorno = -1;
	int  bufferId;
	char bufferName[50];
	char bufferLastName[50];
	float bufferPrice;
	char bufferFlyCode[10];
	int bufferTypePassenger;
	char bufferStatusFlight[50];
	bufferId = controller_generarId( pArrayListPassenger);

	Passenger * pPasajero = NULL;

   if(pArrayListPassenger != NULL){
	   if(getString(bufferName, "Ingrese el nombre del pasajero:\n", "Error, pruebe con un caracter valido\n", 2)== 0 && getString(bufferLastName, "Ingrese el apellido del pasajero:\n", "Error, pruebe con un caracter valido\n", 2)== 0 &&
			utnGetFloat(&bufferPrice, "Ingrese el precio del viaje", "Error ingrese un numero valido", 0, 10000000, 2) == 0 && utn_getFlyCode(bufferFlyCode, "Ingrese el codigo de vuelo:\n", "Error solo caracteres alfanumericos", 2) == 0 &&
			utn_getInt(&bufferTypePassenger, "Ingrese el tipo de pasajero: \n1)FIRSTCLASS\n2)EXECUTIVECLASS\n3)ECONOMYCLASS\n", "Error ingrese una opcion valida.", 1, 3, 2) == 0 &&
			getString(bufferStatusFlight, "Ingrese el estado del vuelo:\n", "Error, pruebe con un caracter valido\n", 2)== 0){
		   pPasajero = Passenger_new();
		   if(pPasajero != NULL){
				if(Passenger_setId(pPasajero, bufferId) == -1 || Passenger_setPrecio(pPasajero, bufferPrice) == -1 || Passenger_setTipoPasajero(pPasajero, bufferTypePassenger)	== -1 ||
					Passenger_setNombre(pPasajero, bufferName) == -1 || Passenger_setApellido(pPasajero, bufferLastName) == -1 || Passenger_setCodigoVuelo(pPasajero, bufferFlyCode) ||
					Passenger_setStatusFlight(pPasajero, bufferStatusFlight)==-1){
					Passenger_delete(pPasajero);
					pPasajero=NULL;
				}
				else{
					ll_add(pArrayListPassenger, pPasajero);
					retorno = 0;
				}
		   }
	   }
   }
   return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger){
	int retorno = -1;
	int opcion;
	int idAmodificar;
	int idAux;
	int cantidadElementos;
	Passenger * pPasajero = NULL;
	char nombreAux[50];
	char apellidoAux[50];
	float precioAux;
	char codigoDeVueloAux[8];
	int tipoPasajeroAux;
	char estadoDeVueloAux[50];


	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger)){
		controller_ListPassenger(pArrayListPassenger);
		if(!utn_getInt(&idAmodificar, "Ingrese el id del pasajero que desea modificar:\n", "Ingrese un numero en el rango.\n", 1, 10000, 2)){
			cantidadElementos = ll_len(pArrayListPassenger);
			for(int i = 0; i < cantidadElementos; i++){
				pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pPasajero, &idAux);
				if(idAmodificar == idAux){
					do{
						if(utn_getInt(&opcion, "Ingrese el campo que desea modificar:\n1)Nombre.\n2)Apellido.\n3)Precio.\n4)Codigo de vuelo.\n5)Tipo de pasajero\n6)Estado de vuelo.\n7)Volver al menu principal.", "Ingrese un numero en el rango.\n", 1, 7, 2)==0){
							switch(opcion){
							case 1:
								if(!getString(nombreAux, "Ingrese el nuevo nombre del pasajero: \n", "Ingrese un nombre valido", 2)){
									if(!Passenger_setNombre(pPasajero, nombreAux)){
										printf("El nombre fue actualizado con exito.\n");
										retorno = 0;
									}
									else{
										printf("Hubo un error en el cambio de nombre.\n");
									}
								}
								break;
							case 2:
								if(!getString(apellidoAux, "Ingrese el nuevo apellido del pasajero: \n", "Ingrese un apellido valido\n", 2)){
									if(!Passenger_setApellido(pPasajero, apellidoAux)){
										printf("Apellido modificado con exito\n");
										retorno = 0;
									}
								}
								break;
							case 3:
								if(!utnGetFloat(&precioAux, "Ingrese el nuevo precio del viaje:\n", "Por favor ingrese un valor valido.", 0, 1000000, 2)){
									if(!Passenger_setPrecio(pPasajero, precioAux)){
										printf("Precio actualizado con exito.\n");
										retorno = 0;
									}
								}
								break;
							case 4:
								if(!utn_getFlyCode(codigoDeVueloAux, "Ingrese el nuevo codigo de vuelo: \n", "Ingrese un codigo alfanumerico.\n", 2)){
									if(!Passenger_setCodigoVuelo(pPasajero, codigoDeVueloAux)){
										printf("Codigo de vuelo actualizado con exito.\n");
										retorno = 0;
									}
								}
								break;
							case 5:
								if(!utn_getInt(&tipoPasajeroAux, "Ingrese el nuevo tipo de pasajero: \n1)First Class\n2)Executive class\n3)Economy Class\n", "Ingrese una opcion valida.", 1, 3, 2)){
									if(!Passenger_setTipoPasajero(pPasajero, tipoPasajeroAux)){
										printf("Tipo de pasajero actualizado con exito.\n");
										retorno = 0;
									}
								}
								break;
							case 6:
								if(!getString(estadoDeVueloAux, "Ingrese el nuevo estado de vuelo: \n", "Ingrese un estado de vuelo valido\n", 2)){
									if(!Passenger_setStatusFlight(pPasajero, estadoDeVueloAux)){
										printf("Estado de vuelo actualizado con exito.\n");
										retorno = 0;
									}
								}
								break;
							case 7:
								break;
							}
						}
					}while(opcion != 7);
				}
			}
		}
		retorno = -1;
	}else{
		retorno = -2;
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger){
	int retorno = -2;
	int idAEliminar;
	int idAux;
	int cantidadElementos;

	Passenger * pAux;
	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger)){
		controller_ListPassenger(pArrayListPassenger);
		if(utn_getInt(&idAEliminar, "Ingrese el id del pasajero a eliminar: \n", "Ingrese un id valido", 1, 10000, 2) == 0){
			cantidadElementos = ll_len(pArrayListPassenger);
			for(int i = 0; i < cantidadElementos; i++){
				pAux = (Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(pAux, &idAux);
				if(idAux == idAEliminar && !ll_remove(pArrayListPassenger,i)){
					Passenger_delete(pAux);
					retorno = 0;
					break;
				}
				else{
					retorno = -1;
				}
			}
		}
	}

    return retorno;;
}

/** \brief Listar pasajeros
 * \param pArrayListPassenger LinkedList*
 * \return int -1 si no hay ningun pasajero 0 si hay al menos 1
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){
	Passenger * pPasajero = NULL;
	int retorno = -2;
	int cantidadElementos;
	int  bufferId;
	char bufferName[50];
	char bufferLastName[50];
	float bufferPrice;
	char bufferFlyCode[10];
	int bufferTypePassenger;
	char bufferStatusFlight[50];
	char bufferTypePassengerStr[50];

	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger)){
		printf("ID   NOMBRE          APELLIDO        PRECIO     FLYCODE T.PASAJERO      FLIGHTSTATUS\n");
		cantidadElementos = ll_len(pArrayListPassenger);
		for(int i =0; i < cantidadElementos; i++){
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			if(pPasajero != NULL){
				Passenger_getId(pPasajero, &bufferId);
				Passenger_getNombre(pPasajero, bufferName);
				Passenger_getApellido(pPasajero, bufferLastName);
				Passenger_getPrecio(pPasajero, &bufferPrice);
				Passenger_getCodigoVuelo(pPasajero, bufferFlyCode);
				Passenger_getTipoPasajero(pPasajero, &bufferTypePassenger);
				Passenger_tipoPasajeroTxt(pPasajero,bufferTypePassenger, bufferTypePassengerStr);
				Passenger_getStatusFlight(pPasajero, bufferStatusFlight);
				printf("%-4d %-15s %-15s $%-9.2f %-7s %-15s %-15s\n",bufferId,bufferName, bufferLastName,bufferPrice,bufferFlyCode,bufferTypePassengerStr,bufferStatusFlight);
				retorno = 0;
			}
			else{
				retorno = -1;
			}
		}
	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger){
	int retorno = -2;
	int opcion;
	int order;

	if(pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger)){
			retorno = -1;
			do{
				if(!utn_getInt(&opcion, "Indique la forma en que desea ordenar\n1)Ordenar por id.\n2)Por nombre\n3)Apellido\n4)Precio.\n5)Codigo de vuelo.\n6)Tipo de pasajero.\n7)Estado de vuelo.\n8)Volver al menu principal.", "Error ingrese una opcion valida", 1, 8, 2)){
				switch(opcion){
				case 1:
					if(!utn_getInt(&order, "Indique el orden para ordenar.\n0)Descendente.\n1)Ascendente.\n", "Indique una opcion valida.", 0, 1, 2)){
						printf("Ordenando, por favor espere\n");
						ll_sort(pArrayListPassenger, controller_sortById, order);
						retorno = 0;
					}
					break;
				case 2:
					if(!utn_getInt(&order, "Indique el orden para ordenar.\n0)Descendente.\n1)Ascendente.\n", "Indique una opcion valida.", 0, 1, 2)){
						printf("Ordenando, por favor espere\n");
						ll_sort(pArrayListPassenger,controller_sortByName, order);
						retorno = 0;
					}
					break;
				case 3:
					if(!utn_getInt(&order, "Indique el orden para ordenar.\n0)Descendente.\n1)Ascendente.\n", "Indique una opcion valida.", 0, 1, 2)){
						printf("Ordenando, por favor espere\n");
						ll_sort(pArrayListPassenger,controller_sortByLastName, order);
						retorno = 0;
					}
					break;
				case 4:
					if(!utn_getInt(&order, "Indique el orden para ordenar.\n0)Descendente.\n1)Ascendente.\n", "Indique una opcion valida.", 0, 1, 2)){
						printf("Ordenando, por favor espere\n");
						ll_sort(pArrayListPassenger,controller_sortByPrice, order);
						retorno = 0;
					}
					break;
				case 5:
					if(!utn_getInt(&order, "Indique el orden para ordenar.\n0)Descendente.\n1)Ascendente.\n", "Indique una opcion valida.", 0, 1, 2)){
						printf("Ordenando, por favor espere\n");
						ll_sort(pArrayListPassenger,controller_sortByFlyCode, order);
						retorno = 0;
					}
					break;
				case 6:
					if(!utn_getInt(&order, "Indique el orden para ordenar.\n0)Descendente.\n1)Ascendente.\n", "Indique una opcion valida.", 0, 1, 2)){
						printf("Ordenando, por favor espere\n");
						ll_sort(pArrayListPassenger,controller_sortByTypePassenger, order);
						retorno = 0;
					}
					break;
				case 7:
					if(!utn_getInt(&order, "Indique el orden para ordenar.\n0)Descendente.\n1)Ascendente.\n", "Indique una opcion valida.", 0, 1, 2)){
						printf("Ordenando, por favor espere\n");
						ll_sort(pArrayListPassenger,controller_sortByFlightStatus, order);
						retorno = 0;
					}
					break;
				case 8:
					break;
				}
			}
			}while(opcion!=8);
	}


    return retorno;
}

int controller_sortById(void* primerElemento, void* segundoElemento){
	int retorno = 0;
	int idPrimerElemento;
	int idSegundoElemento;

	Passenger * primElem;
	Passenger * SegElem;

	if(primerElemento != NULL && segundoElemento != NULL){
		primElem = (Passenger *) primerElemento;
		SegElem = (Passenger *) segundoElemento;

		Passenger_getId(primElem, &idPrimerElemento);
		Passenger_getId(SegElem, &idSegundoElemento);

		if(idPrimerElemento > idSegundoElemento){
			retorno = 1;
		}
		else if (idPrimerElemento < idSegundoElemento){
			retorno = -1;
		}

	}
	return retorno;
}

int controller_sortByName(void* primerElemento, void* segundoElemento){
	int retorno = -1;
	char nombreUno[50];
	char nombreDos[50];

	Passenger * primElem;
	Passenger * SegElem;

	if(primerElemento != NULL && segundoElemento != NULL){
		primElem = (Passenger *) primerElemento;
		SegElem = (Passenger *) segundoElemento;

		Passenger_getNombre(primElem, nombreUno);
		Passenger_getNombre(SegElem, nombreDos);

		retorno = strcmp(nombreUno,nombreDos);

	}

	return retorno;
}


int controller_sortByLastName(void* primerElemento, void* segundoElemento){
	int retorno = -1;
	char apellidoUno[50];
	char apellidoDos[50];

	Passenger * primElem;
	Passenger * SegElem;

	if(primerElemento != NULL && segundoElemento != NULL){
		primElem = (Passenger *) primerElemento;
		SegElem = (Passenger *) segundoElemento;

		Passenger_getNombre(primElem, apellidoUno);
		Passenger_getNombre(SegElem, apellidoDos);

		retorno = strcmp(apellidoUno,apellidoDos);

	}

	return retorno;
}


int controller_sortByPrice(void* primerElemento, void* segundoElemento){
	int retorno = 0;
	float precioPrimerElemento;
	float precioSegundoElemento;

	Passenger * primElem;
	Passenger * SegElem;

	if(primerElemento != NULL && segundoElemento != NULL){
		primElem = (Passenger *) primerElemento;
		SegElem = (Passenger *) segundoElemento;

		Passenger_getPrecio(primElem, &precioPrimerElemento);
		Passenger_getPrecio(SegElem, &precioSegundoElemento);

		if(precioPrimerElemento > precioSegundoElemento){
			retorno = 1;
		}
		else if (precioPrimerElemento < precioSegundoElemento){
			retorno = -1;
		}

	}
	return retorno;
}


int controller_sortByFlyCode(void* primerElemento, void* segundoElemento){
	int retorno = -1;
	char codigoUno[50];
	char codigoDos[50];

	Passenger * primElem;
	Passenger * SegElem;

	if(primerElemento != NULL && segundoElemento != NULL){
		primElem = (Passenger *) primerElemento;
		SegElem = (Passenger *) segundoElemento;

		Passenger_getCodigoVuelo(primElem, codigoUno);
		Passenger_getCodigoVuelo(SegElem, codigoDos);

		retorno = strcmp(codigoUno,codigoDos);

	}

	return retorno;
}

int controller_sortByTypePassenger(void* primerElemento, void* segundoElemento){
	int retorno = 0;
	int tipoPrimerElemento;
	int tipoSegundoElemento;

	Passenger * primElem;
	Passenger * SegElem;

	if(primerElemento != NULL && segundoElemento != NULL){
		primElem = (Passenger *) primerElemento;
		SegElem = (Passenger *) segundoElemento;
		Passenger_getTipoPasajero(primElem, &tipoPrimerElemento);
		Passenger_getTipoPasajero(SegElem, &tipoSegundoElemento);
		if(tipoPrimerElemento > tipoSegundoElemento){
			retorno = 1;
		}
		else if (tipoPrimerElemento < tipoSegundoElemento){
			retorno = -1;
		}
	}
	return retorno;


}

int controller_sortByFlightStatus(void* primerElemento, void* segundoElemento){
	int retorno = -1;
	char estadoUno[50];
	char estadoDos[50];

	Passenger * primElem;
	Passenger * SegElem;

	if(primerElemento != NULL && segundoElemento != NULL){
		primElem = (Passenger *) primerElemento;
		SegElem = (Passenger *) segundoElemento;

		Passenger_getStatusFlight(primElem, estadoUno);
		Passenger_getStatusFlight(SegElem, estadoDos);
		retorno = strcmp(estadoUno,estadoDos);
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger){
	Passenger * pPasajero = NULL;
	FILE * pFile = NULL;
	int retorno = -1;
	int cantidadElementos;
	int  bufferId;
	char bufferName[50];
	char bufferLastName[50];
	float bufferPrice;
	char bufferFlyCode[10];
	int bufferTypePassenger;
	char bufferStatusFlight[50];
	char bufferTypePassengerStr[50];


	pFile = fopen(path, "w");

	if(path != NULL && pArrayListPassenger != NULL && pFile != NULL){
			cantidadElementos = ll_len(pArrayListPassenger);
			for(int i = 0; i < cantidadElementos; i++){
				pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
				if(!Passenger_getId(pPasajero, &bufferId) && !Passenger_getNombre(pPasajero, bufferName)&& !Passenger_getApellido(pPasajero, bufferLastName)&&
		    	   !Passenger_getPrecio(pPasajero, &bufferPrice) && !Passenger_getCodigoVuelo(pPasajero, bufferFlyCode) && !Passenger_getTipoPasajero(pPasajero, &bufferTypePassenger)
				   && !Passenger_tipoPasajeroTxt(pPasajero,bufferTypePassenger, bufferTypePassengerStr) && !Passenger_getStatusFlight(pPasajero, bufferStatusFlight)){
						fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",bufferId,bufferName, bufferLastName,bufferPrice,bufferFlyCode,bufferTypePassengerStr,bufferStatusFlight);
						retorno = 0;
				}
			}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){
	int retorno = -1;
	int cantidadElementos;
	Passenger * pPasajero = NULL;
	FILE * pFile = NULL;
	pFile = fopen(path,"wb");

	if(path != NULL && pArrayListPassenger != NULL && pFile != NULL){
		cantidadElementos = ll_len(pArrayListPassenger);
			for(int i =0; i < cantidadElementos; i++){
				pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
				if(pPasajero != NULL){
					fwrite(pPasajero,sizeof(Passenger),1,pFile);
					retorno=0;
				}
			}
	}
	fclose(pFile);
	return retorno;
}

int controller_generarId( LinkedList* pArrayListPassenger){
	int cantidadElementos;
	int id;
	int idAnt = 0;
	Passenger * pPasajero;

	if(pArrayListPassenger!=NULL){
		cantidadElementos= ll_len(pArrayListPassenger);
		for(int i =0; i < cantidadElementos; i++){
			pPasajero =(Passenger*)  ll_get(pArrayListPassenger, i);
			Passenger_getId(pPasajero, &id);
			if(idAnt < id){
				id++;
			}
		}
	}
	return id;
}





