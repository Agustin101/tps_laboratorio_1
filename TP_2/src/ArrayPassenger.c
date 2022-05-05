/*
 * ArrayPassenger.c
 *
 *  Created on: 26 abr. 2022
 *      Author: Agustin
 */
#include "ArrayPassenger.h"


/** \brief To indicate that all position in the array are empty,* this function put the flag (isEmpty)
* in TRUE in all* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int initPassengers(Passenger * list, int len){
	int retorno;
	retorno = -1;

	if(list != NULL && len > 0){
		for(int i=0; i<len; i++){
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief add in a existing list of passengers the values received as parameters* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[]){
static int idPasajero = 1000;
int retorno;
int pudoAsignar;
int indiceVacio;
pudoAsignar =0;

	if(list != NULL && len>0 && name !=NULL && lastName != NULL && price >0 && typePassenger > 0 && flyCode != NULL ){
		indiceVacio = findFreeIndex(list,len);
		if(indiceVacio != -1){
				list[indiceVacio].isEmpty = 0;
				strcpy(list[indiceVacio].name, name);
				strcpy(list[indiceVacio].lastName, lastName);
				list[indiceVacio].id= idPasajero;
				idPasajero++;
				list[indiceVacio].price = price;
				list[indiceVacio].typePassenger = typePassenger;
				strcpy(list[indiceVacio].flycode, flyCode);
				pudoAsignar = 1;
			}
		else{
				printf("No se pudo cargar el pasajero ya que no hay posiciones disponibles.\n");
				retorno = -1;
				}

		}


	if(pudoAsignar == 1){
		printf("Pasajero cargado correctamente.\n");
		retorno =0;
	}

	return retorno;
}

/** \brief find a Passenger by Id en returns the index position in array.*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;
	retorno = -1;
	if(list != NULL && len > 0 && id>0){
		for(int i =0; i<len; i++){
			if(list[i].id == id){
				retorno = list[i].id;
			}
		}
	}
return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id){
int retorno;
int indiceVacio;
retorno = -1;

	if(list != NULL && len > 0 && id > 0){
		indiceVacio = searchIndexForId(list,len,id);
			if(indiceVacio != -1){
				list[indiceVacio].isEmpty = 1;
				retorno = 0;
				printf("Pasajero eliminado con exito.\n");
			}
			else{
				printf("El id no coincide con ningun pasajero cargado.\n");
			}
	}
return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int sortPassengersByName(Passenger* list, int len, int order){
	int retorno;
	int i;
	int estaOrdenado;
	retorno = -1;

	Passenger aux;

	if(list != NULL && len > 0 ){
		do{
			estaOrdenado =1;
			len--;
			for(i=0; i<len;i++){
				if(stricmp(list[i].lastName, list[i+1].lastName) < order){
					aux = list[i];
					list[i] = list[i+1];
					list[i+1] = aux;
					estaOrdenado=0;
				}
			}

			}while(estaOrdenado ==0);
			retorno = 0;
		}

	return retorno;
}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length)
{
	int indiceOcupado;

	if(list != NULL && length > 0){
		indiceOcupado = findOccupedIndex(list, length);
		if (indiceOcupado != -1){
			printf("\n\n  Nombre completo:%s %s Precio vuelo: %.2f Codigo de vuelo: %s tipo de pasajero: %i estado de vuelo:  id del pasajero: %i\n\n",list[indiceOcupado].lastName, list[indiceOcupado].name, list[indiceOcupado].price, list[indiceOcupado].flycode, list[indiceOcupado].typePassenger,list[indiceOcupado].id);
		}
	}
return 0;
}

/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*
*/
int sortPassengersByFlyCode(Passenger* list, int len, int order)
{
return 0;
}
/// @brief Finds a free index in the array of passengers
///
/// @param list Passenger*
/// @param len int
/// @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
int findFreeIndex(Passenger* list,int len){
	int retorno ;
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

int thereIsPassenger(Passenger * list, int len){
	int retorno;
	retorno = 0;

		if (list != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				if (list[i].isEmpty == 0) {
					retorno = 1;
					break;
				}
			}
		}
		return retorno;

}

int searchIndexForId(Passenger * list , int len, int id){
	int retorno ;
	retorno = -1;

		if (list != NULL && len > 0 && id > 0) {
			for (int i = 0; i < len; i++) {
				if (list[i].id == id && list[i].isEmpty == 0) {
					retorno = i;
					break;
				}
			}
		}
		return retorno;
}

int findOccupedIndex(Passenger* list,int len){
	int retorno ;
	retorno = -1;

	if (list != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				if (list[i].isEmpty == 0) {
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}

int printPassengers(Passenger* list, int len)
{
	int retorno;

	if(list != NULL && len > 0){
		 for(int i = 0; i< len; i++){
			printf("\n\n  Nombre completo:%s %s Precio vuelo: %.2f Codigo de vuelo: %s tipo de pasajero: %i estado de vuelo:  id del pasajero: %i\n\n",list[i].lastName, list[i].name, list[i].price, list[i].flycode, list[i].typePassenger,list[i].id);
		 }
	}
return 0;
}
