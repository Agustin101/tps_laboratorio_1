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
		if (order == 0 ){
			do{
				estaOrdenado =1;
				len--;
				for(i=0; i<len;i++){
					if(stricmp(list[i].lastName, list[i+1].lastName) < 1){
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;
						estaOrdenado=0;
					}
					else if (stricmp(list[i].lastName,list[i + 1].lastName) == 0 && list[i].typePassenger < list[i + 1].typePassenger) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			}while(estaOrdenado ==0);
			retorno = 0;
		}
		else if (order == 1){
			do{
				estaOrdenado =1;
				len--;
				for(i=0; i<len;i++){
					if(stricmp(list[i].lastName, list[i+1].lastName) > 1){
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;
						estaOrdenado=0;
					}
					else if (stricmp(list[i].lastName,list[i + 1].lastName) == 0 && list[i].typePassenger > list[i + 1].typePassenger) {
						aux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = aux;
						estaOrdenado = 0;
					}
				}
			}while(estaOrdenado ==0);
		}
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
	if(list != NULL && length > 0){
		for(int i =0; i<length; i++){
			if (list[i].isEmpty == 0){
				printf("\n\n  Nombre completo:%s %s Precio vuelo: %.2f Codigo de vuelo: %s tipo de pasajero: %i estado de vuelo:  id del pasajero: %i\n\n",list[i].lastName, list[i].name, list[i].price, list[i].flycode, list[i].typePassenger,list[i].id);
			}
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

int modifyPassenger(Passenger * list,int len, int id){
	int retorno = -1;
	int indiceAModificar;
	int opcion;

	char nombreAux[51];
	char apellidoAux[51];
	float precioAux;
	char flyCodeAux[10];
	int typePassengerAux;



	if(list != NULL && len >0 && id>0 ){
		indiceAModificar = searchIndexForId(list,len,id);
		if(indiceAModificar !=-1){
			do{
				if(utn_getInt(&opcion,"¿Que desea modificar?\n1)Nombre\n2)Apellido\n3)Precio\n4)Tipo de pasajero\n5)Codigo de vuelo.\n6)Volver al menu principal", "Por favor, ingrese una opcion valida.",1, 6, 2)==0){
					switch(opcion){
					case 1:
						if(getString(nombreAux,"Introduzca el nuevo nombre del pasajero:\n", "El nombre no pudo ser validado, ingreselo nuevamente:\n", 2)==0){
							strcpy(list[indiceAModificar].name, nombreAux);
							mensajeGenerico("Nombre actualizado.\n");
						}
						else{
							mensajeGenerico("La modificacion fallo.\n");
						}
						break;
					case 2:
						if(getString(apellidoAux,"Introduzca el nuevo apellido del pasajero:\n", "El apellido no pudo ser validado, ingreselo nuevamente:\n", 2)==0){
							strcpy(list[indiceAModificar].lastName, apellidoAux);
							mensajeGenerico("Apellido actualizado.\n");
						}
						else{
							mensajeGenerico("La modificacion fallo.\n");
						}
						break;
					case 3:
						if(utnGetFloat(&precioAux,"Ingrese el nuevo precio del viaje:", "El valor es incorrecto, ingreselo nuevamente:\n", 10000, 1000000, 2)==0){
							list[indiceAModificar].price = precioAux;
							mensajeGenerico("Precio actualizado.\n");
						}
						else{
							mensajeGenerico("La modificacion fallo.\n");
						}
						break;
					case 4:
						if(utn_getInt(&typePassengerAux, "Ingrese el nuevo tipo de pasajero:\n1-Primera clase.\n2-Clase ejecutiva.\n3-Clase turista", "Por favor, ingrese una opcion valida.",1,3,2)==0){
							list[indiceAModificar].typePassenger = typePassengerAux;
							mensajeGenerico("Tipo de pasajero actualizado.\n");
						}
						else{
							mensajeGenerico("La modificacion fallo.\n");
						}
						break;
					case 5:
						if(utn_getFlyCode(flyCodeAux, "Ingrese el nuevo codigo de vuelo:\n", "Error, ingrese un codigo alfanumerico:", 2)==0){
							strcpy(list[indiceAModificar].flycode, flyCodeAux);
							mensajeGenerico("Codigo de vuelo actualizado.\n");
						}
						else{
							mensajeGenerico("La modificacion fallo.\n");
						}
						break;
					case 6:
						mensajeGenerico("Volviendo al menu principal...\n\n");
						break;
					}
				}
				retorno = 0;
			}while(opcion!=6);
		}
		else{
			mensajeGenerico("El id no pertence a ningun pasajero cargado.\n");
		}

	}
	return retorno;
}
