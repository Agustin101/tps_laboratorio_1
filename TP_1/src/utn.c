/*
 * utn.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int * pResultado, char*mensaje, char*mensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	int buffer;

	retorno = -1;

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

int pedirCosto(float * pCosto, char*mensajeDeError, int reintentos){
	int retorno;
	float costo;

	retorno = -1;
	costo = 0;

	if(pCosto != NULL && mensajeDeError != NULL && reintentos >=0)
	{
	do
	{
	printf("Introduzca el costo: \n");
	fflush(stdin);
	scanf("%f", &costo);
	if(costo > 0){
		retorno = 0;
		*pCosto = costo;
		break;
	}
	else{
		reintentos--;
		printf("%s",mensajeDeError);
	}
	}while(reintentos >= 0);
	}
	return retorno;
}

int calcularPrecioConDebito(float precioDelViaje, float * precioFinalDebito){
	int retorno;
	float precioAux;

	retorno = -1;

	if(precioDelViaje > 0 && precioFinalDebito != NULL){
		precioAux = precioDelViaje - (precioDelViaje * 10) / 100;
		*precioFinalDebito = precioAux;
		retorno = 0;
	}
	return retorno;
}

int calcularPrecioConCredito(float precioDelViaje, float * precioFinalCredito){
	float precioAux;
	int retorno;

	retorno = -1;

	if(precioDelViaje > 0 && precioFinalCredito != NULL){
		precioAux = precioDelViaje + (precioDelViaje / 100) * 25;
		*precioFinalCredito = precioAux;
		retorno = 0;
	}
	return retorno;
}

int calcularPrecioConBitcoin(float precioDelViaje, float * precioFinalBtc){
	float precioAux;
	float precioBtc;
	int retorno;

	precioBtc = 4606954.55;
	retorno = -1;

	if(precioDelViaje > 0 && precioFinalBtc != NULL){
		precioAux = precioDelViaje / precioBtc;
		*precioFinalBtc = precioAux;
		retorno = 0;
	}
	return retorno;
}

int pedirKilometros(int * kilometrosIngresados){
	int retorno;
	int kmsDelViajeAux;

	retorno = -1;

	if(kilometrosIngresados != NULL){
	printf("Ingrese los km del viaje: \n");
	fflush(stdin);
	scanf("%d", &kmsDelViajeAux);
		if(kmsDelViajeAux > 0 ){
			*kilometrosIngresados = kmsDelViajeAux;
			retorno = 0;
		}
	}
	return retorno;
}

int calcularPrecioUnitario(float precioDelViaje, int kmsIngresados, float *precioUnitario){
	float precioUnitarioAux;
	int retorno;

	retorno = -1;

	if(precioDelViaje > 0 && kmsIngresados > 0 && precioUnitario != NULL){
		precioUnitarioAux = precioDelViaje / kmsIngresados;
		*precioUnitario = precioUnitarioAux;
		retorno = 0;
	}

	return retorno;
}

int mostrarResultados(int kmsIngresados, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioBitcoin, float precioUnitarioAerolineas){
	int retorno = -1;



	if(kmsIngresados > 0 && precioAerolineas > 0){
	printf("kms Ingresados: %i km\n\n",kmsIngresados);
	printf("Precio Aerolineas: $%.2f \n",precioAerolineas);
	printf("a)Precio con tarjeta de débito: $ %.2f\n",precioAerolineasDebito);
	printf("b)Precio con tarjeta de credito: $ %.2f \n",precioAerolineasCredito);
	printf("c)Precio pagando con bitcoin: %.4f BTC\n",precioBitcoin);
	printf("d) Mostrar precio unitario: $ %.2f\n",precioUnitarioAerolineas);
	}
	else{
		printf("No se ingresaron valores, no se pueden mostrar resultados.\n");
	}


return retorno;
}








