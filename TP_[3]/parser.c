#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int retorna -1 si reciba un archivo o lista nula y 0 si puede cargar al menos a un pasajero.
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
	int retorno = -1;
	Passenger * pPasajeroAux;
	char bufferId[50];
	char bufferName[50];
	char bufferLastName[50];
	char bufferPrice[50];
	char bufferFlyCode[10];
	char bufferTypePassenger[50];
	char bufferStatusFlight[50];
	char ghostHeader[250];
	int cantidadCampos;

	if(pFile != NULL && pArrayListPassenger != NULL){
		fscanf(pFile, "%s\n", ghostHeader);
		while(!feof(pFile)){
			cantidadCampos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferLastName,bufferPrice,bufferFlyCode,bufferTypePassenger,bufferStatusFlight);
			if(cantidadCampos == 7){
				pPasajeroAux = Passenger_newParametros(bufferId, bufferName, bufferLastName, bufferPrice, bufferTypePassenger, bufferFlyCode, bufferStatusFlight);
				if(pPasajeroAux != NULL){
					ll_add(pArrayListPassenger, pPasajeroAux);
					retorno = 0;
				}
				else{
					Passenger_delete(pPasajeroAux);
				}
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int -1 si falla 0 si sale bien
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){
	int retorno = -1;
	int cantidad;

	Passenger * pAux = NULL;
	if(pFile != NULL && pArrayListPassenger != NULL){
		while(!feof(pFile)){
			cantidad = fread(pAux, sizeof(Passenger),1,pFile);
			if(cantidad == 1){
				pAux=Passenger_new();
				if(pAux != NULL){
					ll_add(pArrayListPassenger, pAux);
					retorno = 0;
				}
				else{
					Passenger_delete(pAux);
				}
			}
		}
	}
    return retorno;
}

///** \brief Parsea los datos los ids de los pasajeros desde el archivo data.csv (modo texto).
// *
// * \param path char*
// * \param pArrayListPassenger LinkedList*
// * \return int retorna -1 si reciba un archivo o lista nula y 0 si puede cargar al menos un id.
// *
// */
//int parser_idsFromText(FILE* pFile , LinkedList* pArrayListPassenger, int * ultimoId){
//	int retorno = -1;
//	int cantidadCampos;
//	char bufferId[50];
//	int idAnterior;
//	int maximoId;
//	int flag = 0;
//	char bufferName[50];
//	char bufferLastName[50];
//	char bufferPrice[50];
//	char bufferFlyCode[10];
//	char bufferTypePassenger[50];
//	char bufferStatusFlight[50];
//
//	if(pFile != NULL && pArrayListPassenger != NULL){
//		while(!feof(pFile)){
//			cantidadCampos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferName,bufferLastName,bufferPrice,bufferFlyCode,bufferTypePassenger,bufferStatusFlight);
//			if(cantidadCampos == 7){
//				idAnterior = atoi(bufferId);
//				if(flag == 0 || idAnterior > maximoId){
//					printf("-id-%d-",idAnterior);
//					maximoId = idAnterior;
//					flag = 1;
//				}
//			}
//		}
//		retorno = 0;
//		*ultimoId = maximoId;
//		printf("\nultimo id %d",maximoId);
//	}
//    return retorno;
//}

//int parser_idFromBinary(FILE* pFile , LinkedList* pArrayListPassenger, int * ultimoId){
//	int retorno = -1;
//	int cantidad;
//	int idAnterior;
//	int maximoId;
//	int flag = 0;
//
//	Passenger * pAux = NULL;
//
//	if(pFile != NULL && pArrayListPassenger != NULL){
//		while(!feof(pFile)){
//			printf("cuantite");
//				cantidad = fread(pAux, sizeof(Passenger),1,pFile);
//				if(cantidad == 1){
//					printf("rompi antes del get");
//					Passenger_getId(pAux, &idAnterior);
//					printf("Rompi despues");
//					if(flag == 0 || idAnterior > maximoId){
//						printf("-id-%d-",idAnterior);
//						maximoId = idAnterior;
//						flag = 1;
//					}
//
//				}
//
//		}
//		retorno = 0;
//		*ultimoId = maximoId;
//		printf("\nultimo id %d",maximoId);
//	}
//    return retorno;
//}

//int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger){
//	int retorno = -1;
//	int cantidad;
//
//	Passenger * pAux = NULL;
//	if(pFile != NULL && pArrayListPassenger != NULL){
//		while(!feof(pFile)){
//			pAux=Passenger_new();
//			if(pAux != NULL){
//				cantidad = fread(pAux, sizeof(Passenger),1,pFile);
//				if(cantidad == 1){
//					ll_add(pArrayListPassenger, pAux);
//					retorno = 0;
//				}
//				else{
//					Passenger_delete(pAux);
//				}
//			}
//		}
//	}
//    return retorno;
//}


