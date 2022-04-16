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
int utn_getNumero(int * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);
/// @brief Funcion que solicita los kilometros.
///
/// @param pKilometrosIngresados Recibe como parametro un puntero tipo entero en el cual retorna
///  los kms ingresados.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int pedirKilometros(int * pKilometrosIngresados);
/// @brief Funcion que se utiliza para obtener un costo.
///
/// @param pCosto Recibe como parametro un puntero tipo float en el cual retorna el valor indicado.
/// @param pMensajeDeError Recibe como parametro un mensaje de error que el usuario determina.
/// @param reintentos Parametro que determina la cantidad de reintentos antes de que la funcion
/// finalice.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int pedirCosto(float * pCosto, char*pMensajeDeError, int reintentos);
/// @brief Funcion que imprime por pantalla los resultados de los calculos.
///
/// @param kmsIngresados Parametro que recibe los kms del viaje ingresado.
/// @param precioAerolineas Parametro que recibe el precio del viaje ingresado
///  en aerolineas.
/// @param precioAerolineasDebito Parametro que recibe el precio del viaje de
/// aerolineas con debito.
/// @param precioAerolineasCredito Parametro que recibe el precio del viaje de
///  aerolineas con credito.
/// @param precioAerolineasBitcoin Parametro que recibe el precio del viaje de
/// aerolineas con BTC.
/// @param precioUnitarioAerolineas Parametro que recibe el precio del viaje de
/// aerolineas por cada km.
/// @param precioLatam Parametro que recibe el precio del viaje ingresado en latam.
/// @param precioLatamDebito Parametro que recibe el precio del viaje de latam con
///  debito.
/// @param precioLatamCredito Parametro que recibe el precio del viaje de latam con
/// credito.
/// @param precioLatamBitcoin  Parametro que recibe el precio del viaje de latam con BTC.
/// @param precioUnitarioLatam Parametro que recibe el precio del viaje de latam
///  por cada km.
/// @param diferenciaDePrecio  Parametro que recibe la diferencia de precio entre ambos viajes.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int mostrarResultados(int kmsIngresados, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin, float precioUnitarioAerolineas,
		float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioUnitarioLatam, float diferenciaDePrecio);
#endif /* BIBLIOTECAESDEDATOS_H_ */
