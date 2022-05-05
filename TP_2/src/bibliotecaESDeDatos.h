/*
 * utn.h
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */


#ifndef BIBLIOTECAESDEDATOS_H_
#define BIBLIOTECAESDEDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief Funcion que se utiliza para obtener un numero en un rango determinado por la misma.
///
/// @param pResultado Recibe como parametro un puntero tipo entero
/// en el cual retorna el numero/opcion seleccionada.
/// @param pMensaje Recibe como parametro un mensaje que el usuario determina.
/// @param pMensajeError Recibe como parametro un mensaje de error que el usuario determina.
/// @param minimo Parametro que indica el numero minimo en el rango.
/// @param maximo Parametro que indica el numero maximo en el rango.
/// @param reintentos Parametro que determina la cantidad de reintentos antes de que la funcion
/// finalice.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int utn_getInt(int * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);
int utn_getString(char retString[], char * pMensaje, char *pMensajeError, int len);
int utn_getFlyCode(char retString[], char * pMensaje, char *pMensajeError, int len, int reintentos);
int mensajeErrorGenerico(char * mensajeError);
#endif /* BIBLIOTECAESDEDATOS_H_ */
