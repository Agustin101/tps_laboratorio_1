/*
 * utn.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int * pResultado, char*mensaje, char*mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
		printf("%s",mensaje);
		scanf("%i", &buffer);
		fflush(stdin);
		if(buffer >= minimo && buffer <= maximo){
			*pResultado = buffer;
			retorno = 0;
			break;
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

int pedirKilometros(int * kilometrosIngresados){
	int retorno = -1;
	int kmsDelViajeAux;
	printf("Ingrese los km del viaje: \n");
	scanf("%d", &kmsDelViajeAux);
	if(kmsDelViajeAux > 0){
		retorno = 0;
		*kilometrosIngresados = kmsDelViajeAux;
	}
	return retorno;
}

int pedirCosto(float * pCosto){
	int retorno = -1;
	float costo;
	printf("Introduzca el costo");
	scanf("%f", &costo);
	if(costo > 0){
		retorno = 0;
		*pCosto = costo;
	}


	return retorno;
}

