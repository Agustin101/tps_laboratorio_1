/*
 * utn.h
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int * pResultado, char*mensaje, char*mensajeError, int minimo, int maximo, int reintentos);
int calcularPrecioConDebito(float precioDelViaje, float * precioFinalDebito);
int calcularPrecioConCredito(float precioDelViaje, float * precioFinalCredito);
int calcularPrecioConBitcoin(float precioDelViaje, float * precioFinalBtc);
int pedirKilometros(int * kilometrosIngresados);
int pedirCosto(float * pCosto);

#endif /* UTN_H_ */
