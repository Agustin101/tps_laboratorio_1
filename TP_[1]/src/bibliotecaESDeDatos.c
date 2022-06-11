/*
 * utn.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */
#include "bibliotecaESDeDatos.h"


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

int mostrarResultados(int kmsIngresados, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin, float precioUnitarioAerolineas,
		float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin, float precioUnitarioLatam, float diferenciaDePrecio){
	int retorno;

	retorno = -1;

	if(kmsIngresados > 0 && precioAerolineas > 0 && precioLatam > 0){
	printf("kms Ingresados: %i km\n\n",kmsIngresados);
	printf("Precio Aerolineas: $%.2f \n",precioAerolineas);
	printf("a)Precio con tarjeta de d�bito: $ %.2f\n",precioAerolineasDebito);
	printf("b)Precio con tarjeta de credito: $ %.2f \n",precioAerolineasCredito);
	printf("c)Precio pagando con bitcoin: %.2f BTC\n",precioAerolineasBitcoin);
	printf("d) Mostrar precio unitario: $ %.2f\n\n",precioUnitarioAerolineas);
	printf("Precio Latam: $%.2f \n",precioLatam);
	printf("a)Precio con tarjeta de d�bito: $ %.2f\n",precioLatamDebito);
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

/// @brief Funcion que se utiliza para obtener un numero decimal en un rango determinado por la misma.
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param pMensaje Es el mensaje a ser mostrado
/// @param pMensajeError Es el mensaje de error a ser mostrado
/// @param minimo El numero minimo a ser aceptado
/// @param maximo minimo El numero maximo a ser aceptado
/// @param reintentos Parametro que determina la cantidad de reintentos antes de que la funcion
/// finalice.
/// @return Retorna 0 si se obtuvo el numero y -1 si no
int utnGetFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	float buffer;

	retorno = -1;

	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0){
		while(reintentos>0){
			printf(pMensaje);
			if(getFloat(&buffer)==1){
				if(buffer<=maximo && buffer>=minimo){
					break;
				}
			}
			fflush(stdin);
			reintentos--;
			printf(pMensajeError);
		}
		if(reintentos==0){
			retorno=-1;
		}
		else{
		retorno=0;
		*pResultado = buffer;
		}
	}
	return retorno;
}

/// @brief Verifica si la cadena ingresada es numerica decimal
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return   Retorna 1 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
int getFloat(float* pResultado){
	int retorno;
	retorno = -1;
	char buffer[64];

	if(pResultado != NULL){
		if(myGets(buffer,sizeof(buffer)) ==0 && esNumericaDecimal(buffer)==1){
			*pResultado = atof(buffer);
			retorno = 1;
		}
	}
	return retorno;
}

/// @brief Verifica si la cadena ingresada es flotante
///
/// @param cadena Cadena de caracteres a ser analizada
/// @return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
int esNumericaDecimal(char* cadena)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL){
		while(cadena[i]!='\0')
		{
			if((cadena[i] >= '0' && cadena[i] <= '9') || cadena[i] == ',')
			{
				if(cadena[i] == ','){
					cadena[i]= '.';
				}
				i++;
			}
			else{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int myGets(char* cadena, int longitud){
	int retorno;
	retorno =-1;
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena){
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n'){
			cadena[strlen(cadena)-1] = '\0';
		}
	retorno=0;
	}

return retorno;
}






