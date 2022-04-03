/*
 * utn.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(char * pResultado, char*mensaje, char*mensajeError, char minimo, char maximo, int reintentos){
	int retorno = -1;
	char buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
		printf("%s",mensaje);
		scanf("%c", &buffer);
		if(buffer >= minimo && buffer <= maximo){
			*pResultado = buffer;
			retorno = 0;
		}
		else{
			printf("%s",mensajeError);
			reintentos--;
		}
		}while(reintentos >= 0);
	}
	return retorno;
}

int calcularPrecioConDebito(float precioDelViaje, float * precioFinalDebito){
	float precioAux;
	precioAux = precioDelViaje - (precioDelViaje * 10) / 100;
	*precioFinalDebito = precioAux;
	return 0;
}

int calcularPrecioConCredito(float precioDelViaje, float * precioFinalCredito){
	float precioAux;
	precioAux = precioDelViaje + (precioDelViaje / 100) * 25;
	*precioFinalCredito = precioAux;
	return 0;
}

int calcularPrecioConBitcoin(float precioDelViaje, float * precioFinalBtc){
	float precioAux;
	float precioBtc;
	precioBtc = 4606954.55;
	precioAux = precioDelViaje / precioBtc;
	*precioFinalBtc = precioAux;
	return 0;
}






