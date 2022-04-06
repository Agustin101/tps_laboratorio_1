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

int pedirCosto(float * pCosto, char*mensajeDeError, int reintentos){
	int retorno = -1;
	float costo = 0;

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
	int retorno = -1;
	float precioAux;
	precioAux = precioDelViaje - (precioDelViaje * 10) / 100;
	*precioFinalDebito = precioAux;
	return retorno;
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

int mostrarResultados(int kmsIngresados, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioBitcoin, float precioUnitarioAerolineas){

	printf("kms Ingresados: %i km\n\n",kmsIngresados);
	printf("Precio Aerolineas: $%.2f \n",precioAerolineas);
	printf("a)Precio con tarjeta de débito: $ %.2f\n",precioAerolineasDebito);
	printf("b)Precio con tarjeta de credito: $ %.2f \n",precioAerolineasCredito);
	printf("c)Precio pagando con bitcoin: %.4f BTC\n",precioBitcoin);
	printf("d) Mostrar precio unitario: $ %.2f\n",precioUnitarioAerolineas);



return 0;
}

int calcularPrecioUnitario(float precioDelViaje, int kmsIngresados, float *precioUnitario){
	float precioUnitarioAux;
	precioUnitarioAux = precioDelViaje / kmsIngresados;
	*precioUnitario = precioUnitarioAux;


	return 0;
}









