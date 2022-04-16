/*
 * BibliotecaCalculos.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Agustin
 */

#ifndef BIBLIOTECACALCULOS_H_
#define BIBLIOTECACALCULOS_H_

#include <stdio.h>
#include <stdlib.h>

/// @brief Calcula el precio unitario por km del viaje
/// @param precioDelViaje Parametro que recibe el precio del viaje ingresado.
/// @param kmsIngresados Parametro que recibe la cantidad de kilometros.
/// @param precioUnitario Recibe como parametro un puntero tipo flotante
/// en el cual retorna un puntero con el valor calculado.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int calcularPrecioUnitario(float precioDelViaje, int kmsIngresados, float *pPrecioUnitario);
/// @brief Calcula el precio del viaje en bitcoin.
///
/// @param precioDelViaje Parametro que recibe el precio del viaje ingresado.
/// @param pPrecioFinalBtc Recibe como parametro un puntero tipo flotante
/// y retorna un puntero con el valor calculado.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int calcularPrecioConBitcoin(float precioDelViaje, float * pPrecioFinalBtc);
/// @brief Calcula el precio del viaje con tarjeta de credito.
///
/// @param precioDelViaje Parametro que recibe el precio del viaje ingresado.
/// @param pPrecioFinalCredito Recibe como parametro un puntero tipo flotante
/// y retorna un puntero con el valor calculado.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int calcularPrecioConCredito(float precioDelViaje, float * pPrecioFinalCredito);
/// @brief Calcula el precio del viaje con tarjeta de debito.
///
/// @param precioDelViaje Parametro que recibe el precio del viaje ingresado.
/// @param pPrecioFinalDebito Recibe como parametro un puntero tipo flotante
/// y retorna un puntero con el valor calculado.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int calcularPrecioConDebito(float precioDelViaje, float * pPrecioFinalDebito);
/// @brief Calcula la diferencia entre dos numeros tipo float.
///
/// @param primerNumero Parametro que recibe el primer numero.
/// @param segundoNumero Parametro que recibe el segundo numero.
/// @param pDiferencia Recibe como parametro un puntero tipo flotante
/// y retorna un puntero con la diferencia entre ambos numeros.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int calcularDiferenciaEntreDosFlotantes(float primerNumero, float segundoNumero, float * pDiferencia);

#endif /* BIBLIOTECACALCULOS_H_ */
