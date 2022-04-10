#include "BibliotecaCalculos.h"

/// @brief Calcula el precio unitario por km del viaje
/// @param precioDelViaje Parametro que recibe el precio del viaje ingresado.
/// @param kmsIngresados Parametro que recibe la cantidad de kilometros.
/// @param precioUnitario Recibe como parametro un puntero tipo flotante.
/// al precio unitario y retorna un puntero a precio unitario.
/// @return Retorna 0 en caso de que pueda realizar las validaciones, si una de esta falla
/// el retorno es -1.
int calcularPrecioUnitario(float precioDelViaje, int kmsIngresados, float *pPrecioUnitario){
	float precioUnitarioAux;
	int retorno;

	retorno = -1;

	if(precioDelViaje > 0 && kmsIngresados > 0 && pPrecioUnitario != NULL){
		precioUnitarioAux = precioDelViaje / kmsIngresados;
		*pPrecioUnitario = precioUnitarioAux;
		retorno = 0;
	}

	return retorno;
}

int calcularPrecioConBitcoin(float precioDelViaje, float * pPrecioFinalBtc){
	float precioAux;
	float precioBtc;
	int retorno;

	precioBtc = 4606954.55;
	retorno = -1;

	if(precioDelViaje > 0 && pPrecioFinalBtc != NULL){
		precioAux = precioDelViaje / precioBtc;
		*pPrecioFinalBtc = precioAux;
		retorno = 0;
	}
	return retorno;
}

int calcularPrecioConCredito(float precioDelViaje, float * pPrecioFinalCredito){
	float precioAux;
	int retorno;

	retorno = -1;

	if(precioDelViaje > 0 && pPrecioFinalCredito != NULL){
		precioAux = precioDelViaje + (precioDelViaje / 100) * 25;
		*pPrecioFinalCredito = precioAux;
		retorno = 0;
	}
	return retorno;
}

int calcularPrecioConDebito(float precioDelViaje, float * pPrecioFinalDebito){
	int retorno;
	float precioAux;

	retorno = -1;

	if(precioDelViaje > 0 && pPrecioFinalDebito != NULL){
		precioAux = precioDelViaje - (precioDelViaje * 10) / 100;
		*pPrecioFinalDebito = precioAux;
		retorno = 0;
	}
	return retorno;
}

int calcularDiferenciaEntreDosFlotantes(float primerNumero, float segundoNumero, float * pDiferencia){
	int retorno;
	float diferenciaAux;
	retorno = -1;

	if(primerNumero > 0 && segundoNumero > 0 && pDiferencia != NULL){
		if(primerNumero > segundoNumero){
			diferenciaAux = primerNumero - segundoNumero;
			*pDiferencia = diferenciaAux;
			retorno = 0;
		}
		else{
			if(segundoNumero > primerNumero){
				diferenciaAux = segundoNumero - primerNumero;
				*pDiferencia = diferenciaAux;
				retorno = 0;
			}
		}
	}

	return retorno;
}

