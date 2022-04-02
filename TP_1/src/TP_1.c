#include <stdio.h>
#include <stdlib.h>

int calcularPrecioConDebito(float precioDelViaje, float * precioFinalDebito);
int calcularPrecioConCredito(float precioDelViaje, float * precioFinalCredito);
int calcularPrecioConBitcoin(float precioDelViaje, float * precioFinalBtc);

int main(void) {
	setbuf(stdout, NULL);
	int kmsDelViaje;
	float costoDelViajeAerolineas, costoDelViajeLatam, precioAerolineasDebito, precioLatamDebito,
	precioLatamCredito, precioAerolineasCredito, precioAerolineasBtc, precioLatamBtc;
	char respuesta;

	respuesta = 's';



	while(respuesta == 's'){
	fflush(stdin);
	printf("Ingrese los kms totales del vuelo: \n");
	scanf("%i", &kmsDelViaje);
	printf("Ingrese el valor del vuelo en aerolineas: \n");
	scanf("%f", &costoDelViajeAerolineas);
	printf("Ingrese el valor del vuelo en latam: \n");
	scanf("%f", &costoDelViajeLatam);

	calcularPrecioConDebito(costoDelViajeAerolineas,&precioAerolineasDebito);
	calcularPrecioConDebito(costoDelViajeLatam,&precioLatamDebito);
	calcularPrecioConCredito(costoDelViajeAerolineas, &precioAerolineasCredito);
	calcularPrecioConCredito(costoDelViajeLatam, &precioLatamCredito);
	calcularPrecioConBitcoin(costoDelViajeAerolineas, &precioAerolineasBtc);


	fflush(stdin);
	printf("¿Desea agregar otro vuelo? s/n");
	scanf("%c", &respuesta);

	}

	printf("KMs Ingresados: %i km \n\n",kmsDelViaje);
	printf("Precio Aerolineas: $%.2f \n",costoDelViajeAerolineas);
	printf("a) Precio con tarjeta de debito: $ %.2f\n",precioAerolineasDebito);
	printf("b) Precio con tarjeta de credito: $ %.2f\n",precioAerolineasCredito);
	printf("c) Precio pagando con bitcoin: %.3f BTC \n\n",precioAerolineasBtc);

	printf("Precio Latam: $%.2f\n",costoDelViajeLatam);
	printf("a) Precio con tarjeta de debito: $ %.2f\n",precioLatamDebito);
	printf("b) Precio con tarjeta de credito: $ %.2f\n\n",precioLatamCredito);

	return 0;
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


















