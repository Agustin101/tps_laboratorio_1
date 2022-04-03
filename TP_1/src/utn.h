/*
 * utn.h
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(char * pResultado, char*mensaje, char*mensajeError, char minimo, char maximo, int reintentos);
int calcularPrecioConDebito(float precioDelViaje, float * precioFinalDebito);
int calcularPrecioConCredito(float precioDelViaje, float * precioFinalCredito);
int calcularPrecioConBitcoin(float precioDelViaje, float * precioFinalBtc);

#endif /* UTN_H_ */
