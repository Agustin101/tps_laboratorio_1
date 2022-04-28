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
int idPasajero;
int retorno;
int pudoAsignar;

pudoAsignar =0;

	if(list != NULL && len>0 && name !=NULL && lastName != NULL && price >0 && typePassenger > 0 && flyCode != NULL ){
		for(int i=0; i<len;i++){
			if(list[i].isEmpty == 1){
				list[i].isEmpty = 0;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				idPasajero=i+1;
				list[i].id= idPasajero;
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flycode, flyCode);
				pudoAsignar = 1;
				break;
			}

		}
	}

	if(pudoAsignar == 1){
		printf("Pasajero cargado correctamente.\n");
		retorno =0;
	}
	else{
		printf("No se pudo cargar el pasajero ya que no hay posiciones disponibles.\n");
		retorno = -1;
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

retorno = -1;

	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i<len; i++){
			if(list[i].id == id){
				list[i].isEmpty = 1;
				retorno = 0;
			}
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
int sortPassengersByName(Passenger* list, int len, int order)
{
return 0;
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





