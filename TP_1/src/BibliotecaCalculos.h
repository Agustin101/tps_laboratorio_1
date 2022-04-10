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

int calcularPrecioUnitario(float precioDelViaje, int kmsIngresados, float *pPrecioUnitario);
int calcularPrecioConBitcoin(float precioDelViaje, float * pPrecioFinalBtc);
int calcularPrecioConCredito(float precioDelViaje, float * pPrecioFinalCredito);
int calcularPrecioConDebito(float precioDelViaje, float * pPrecioFinalDebito);
int calcularDiferenciaEntreDosFlotantes(float primerNumero, float segundoNumero, float * pDiferencia);

#endif /* BIBLIOTECACALCULOS_H_ */
