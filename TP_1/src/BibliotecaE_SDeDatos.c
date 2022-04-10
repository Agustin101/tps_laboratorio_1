/*
 * utn.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */
#include "BibliotecaE_SDeDatos.h"

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
int utn_getNumero(int * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	int buffer;

	retorno = -1;

	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
		printf("%s",pMensaje);
		scanf("%i", &buffer);
		fflush(stdin);
		if(buffer >= minimo && buffer <= maximo){
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		else{
			printf("%s",pMensajeError);
			reintentos--;
		}
		}while(reintentos >= 0);
	}
	return retorno;
}

/// @brief Funcion que se utiliza para obtener un costo.
///
/// @param pCosto Recibe como parametro un puntero tipo float en el cual retorna el valor indicado.
/// @param pMensajeDeError Recibe como parametro un mensaje de error que el usuario determina.
/// @param reintentos Parametro que determina la cantidad de reintentos antes de que la funcion
/// finalice.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int pedirCosto(float * pCosto, char*pMensajeDeError, int reintentos){
	int retorno;
	float costo;

	retorno = -1;
	costo = 0;

	if(pCosto != NULL && pMensajeDeError != NULL && reintentos >=0)
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
		printf("%s",pMensajeDeError);
	}
	}while(reintentos >= 0);
	}
	return retorno;
}

/// @brief Funcion que solicita los kilometros.
///
/// @param pKilometrosIngresados Recibe como parametro un puntero tipo entero en el cual retorna
///  los kms ingresados.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int pedirKilometros(int * pKilometrosIngresados){
	int retorno;
	int kmsDelViajeAux;

	retorno = -1;

	if(pKilometrosIngresados != NULL){
	printf("Ingrese los km del viaje: \n");
	fflush(stdin);
	scanf("%d", &kmsDelViajeAux);
		if(kmsDelViajeAux > 0 ){
			*pKilometrosIngresados = kmsDelViajeAux;
			retorno = 0;
		}
	}
	return retorno;
}

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
		float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioUnitarioLatam, float diferenciaDePrecio){
	int retorno;

	retorno = -1;



	if(kmsIngresados > 0 && precioAerolineas > 0 && precioLatam > 0){
	printf("kms Ingresados: %i km\n\n",kmsIngresados);
	printf("Precio Aerolineas: $%.2f \n",precioAerolineas);
	printf("a)Precio con tarjeta de débito: $ %.2f\n",precioAerolineasDebito);
	printf("b)Precio con tarjeta de credito: $ %.2f \n",precioAerolineasCredito);
	printf("c)Precio pagando con bitcoin: %.2f BTC\n",precioAerolineasBitcoin);
	printf("d) Mostrar precio unitario: $ %.2f\n\n",precioUnitarioAerolineas);
	printf("Precio Latam: $%.2f \n",precioLatam);
	printf("a)Precio con tarjeta de débito: $ %.2f\n",precioLatamDebito);
	printf("b)Precio con tarjeta de credito: $ %.2f \n",precioLatamCredito);
	printf("c)Precio pagando con bitcoin: %.2f BTC\n",precioLatamBitcoin);
	printf("d) Mostrar precio unitario: $ %.2f\n\n",precioUnitarioLatam);
	printf("La diferencia de precio es: $ %.2f\n\n", diferenciaDePrecio);
	retorno = 0;
	}
	else{
		printf("No se ingresaron valores, no se pueden mostrar resultados.\n");
	}


return retorno;
}








