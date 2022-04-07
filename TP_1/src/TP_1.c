#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void){
	setbuf(stdout, NULL);
	int kmsDelViaje;
	int opcion;
	int opcionMenuAerolineas;
	int respuesta;
	int respuestaMenuAerolineas;
	float costoDelViajeAerolineas, costoDelViajeLatam,precioLatamDebito,
	precioLatamCredito, precioAerolineasBtc, precioLatamBtc;
	float precioAerolineasCredito;
	float precioAerolineasDebito;
	float precioUnitarioAerolineas;


	precioAerolineasCredito = 0;
	precioAerolineasDebito = 0;
	kmsDelViaje = 0;

	do{
		printf("Seleccione una opcion\n");
		printf("1 Ingresar Kil�metros: ( km = %i)\n",kmsDelViaje);
		printf("2 Ingresar Precio de Vuelos: (Aerol�neas=%.2f, Latam=%.2f)\n- Precio vuelo Aerol�neas:\n- Precio vuelo Latam:\n",costoDelViajeAerolineas,costoDelViajeLatam);
		printf("3 Calcular todos los costos\na) Tarjeta de d�bito (descuento 10)\nb) Tarjeta de cr�dito (inter�s 25%)\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nd) Mostrar precio por km (precio unitario)\ne) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)\n");
		printf("4 Informar Resultados\n�Latam:\na) Precio con tarjeta de d�bito: r\nb) Precio con tarjeta de cr�dito: r\nc) Precio pagando con bitcoin : r\nd) Precio unitario: r\nAerol�neas:\na) Precio con tarjeta de d�bito: r\nb) Precio con tarjeta de cr�dito: r\nc) Precio pagando con bitcoin :\n"
				"d) Precio unitario: r \nLa diferencia de precio es : r �\n");
		printf("5 Carga forzada de datos\n");
		printf("6 Salir\n");
		fflush(stdin);
		scanf("%i",&opcion);
		switch(opcion){
		case 1:
			do{
				respuesta = pedirKilometros(&kmsDelViaje);
				if(respuesta == 0){
					break;
				}
				else{
					printf("El valor ingresado no es valido.(Debe ser un numero y mayor a 0)\n");
				}
			}while(respuesta !=0);
				break;
		case 2:
			do{
				fflush(stdin);
			respuestaMenuAerolineas = utn_getNumero(&opcionMenuAerolineas,"Seleccione una opcion\n1 Ingresar precio Aerolineas\n2 Ingresar precio latam\n3 Volver a menu principal", "Ingrese una opcion valida\n",1,3,1);
			if(respuestaMenuAerolineas == 0){
				switch(opcionMenuAerolineas){
				case 1:
					fflush(stdin);
					pedirCosto(&costoDelViajeAerolineas, "Debe ser un numero y mayor a 0.\n",1);
					break;
				case 2:
					fflush(stdin);
					 pedirCosto(&costoDelViajeLatam, "Debe ser un numero y mayor a 0.\n",1);
					break;
				case 3:
					break;
				}
			}
			else{
				printf("Reintentos finalizados, volviendo al menu principal.\n");
				break;
				}
			}while(respuestaMenuAerolineas == 0 && opcionMenuAerolineas != 3);
			break;
		case 3:
			calcularPrecioConDebito(costoDelViajeAerolineas, &precioAerolineasDebito);
			calcularPrecioConCredito(costoDelViajeAerolineas, &precioAerolineasCredito);
			calcularPrecioConBitcoin(costoDelViajeAerolineas,&precioAerolineasBtc);
			calcularPrecioUnitario(costoDelViajeAerolineas, kmsDelViaje, &precioUnitarioAerolineas);
			break;
		case 4:
			mostrarResultados(kmsDelViaje, costoDelViajeAerolineas, precioAerolineasDebito,precioAerolineasCredito,precioAerolineasBtc,precioUnitarioAerolineas);
			break;
		case 5:
			kmsDelViaje = 7090;
			costoDelViajeAerolineas = 162965;
			costoDelViajeLatam = 159339;
			calcularPrecioConDebito(costoDelViajeAerolineas, &precioAerolineasDebito);
			calcularPrecioConCredito(costoDelViajeAerolineas, &precioAerolineasCredito);
			calcularPrecioConBitcoin(costoDelViajeAerolineas,&precioAerolineasBtc);
			calcularPrecioUnitario(costoDelViajeAerolineas, kmsDelViaje, &precioUnitarioAerolineas);

			break;
		case 6:
			printf("Programa finalizado correctamente.");
			exit(0);
			break;
		}
	}while(opcion !=6);

	return 0;
}












