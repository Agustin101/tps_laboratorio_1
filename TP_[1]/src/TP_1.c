#include <stdio.h>
#include <stdlib.h>

#include "bibliotecaCalculos.h"
#include "bibliotecaESDeDatos.h"

int main(void){
	setbuf(stdout, NULL);
	float kmsDelViaje;

	int opcion;
	int opcionMenuAerolineas;
	int respuestaMenuAerolineas;
	float costoDelViajeAerolineas;
	float precioAerolineasCredito;
	float precioAerolineasDebito;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaDePrecio;
	float precioLatamDebito;
	float precioLatamCredito;
	float precioAerolineasBtc;
	float precioLatamBtc;
	float costoDelViajeLatam;
	int validacionRetorno;

	kmsDelViaje = 0;
	costoDelViajeAerolineas = 0;
	costoDelViajeLatam = 0;

	do{
		printf("1 Ingresar Kilometros: ( km = %.2f)\n2 Ingresar Precio de Vuelos: (Aerolineas=%.2f, Latam=%.2f)\n3 Calcular todos los costos\na) Tarjeta de debito (descuento 10%%)\nb) Tarjeta de credito (interes 25%%)\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\nd) Mostrar precio por km (precio unitario)\ne) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n4 Informar Resultados\n5 Carga forzada de datos\n6 Salir\n",kmsDelViaje,costoDelViajeAerolineas,costoDelViajeLatam);
		validacionRetorno = utn_getNumero(&opcion,"Seleccione una opcion:\n", "Ingrese una opcion valida\n",1,6,1);
		if(validacionRetorno == 0){
		switch(opcion){
		case 1:
				if(!utnGetFloat(&kmsDelViaje, "Ingrese los kilometros del viaje:\n", "Error ingrese un valor numerico mayor a 0.\n", 0, 150000, 2)){
					printf("Kilometros ingresados con exito.\n");
				}
				else{
					printf("La toma de datos de los kilometros fallo.\n");
				}
			break;
		case 2:
			do{
			respuestaMenuAerolineas = utn_getNumero(&opcionMenuAerolineas,"Seleccione una opcion\n1 Ingresar precio Aerolineas\n2 Ingresar precio latam\n3 Volver a menu principal", "Ingrese una opcion valida\n",1,3,1);
			if(respuestaMenuAerolineas == 0){
				switch(opcionMenuAerolineas){
				case 1:
					pedirCosto(&costoDelViajeAerolineas, "Debe ser un numero y mayor a 0.\n",1);
					break;
				case 2:
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
			if(costoDelViajeAerolineas >= 1 && costoDelViajeLatam >= 1 && kmsDelViaje >= 1){
			calcularPrecioConDebito(costoDelViajeAerolineas, &precioAerolineasDebito);
			calcularPrecioConCredito(costoDelViajeAerolineas, &precioAerolineasCredito);
			calcularPrecioConBitcoin(costoDelViajeAerolineas,&precioAerolineasBtc);
			calcularPrecioUnitario(costoDelViajeAerolineas, kmsDelViaje, &precioUnitarioAerolineas);
			calcularPrecioConDebito(costoDelViajeLatam, &precioLatamDebito);
			calcularPrecioConCredito(costoDelViajeLatam, &precioLatamCredito);
			calcularPrecioConBitcoin(costoDelViajeLatam,&precioLatamBtc);
			calcularPrecioUnitario(costoDelViajeLatam, kmsDelViaje, &precioUnitarioLatam);
			calcularDiferenciaEntreDosFlotantes(costoDelViajeAerolineas, costoDelViajeLatam, &diferenciaDePrecio);
			}
			else{
				printf("Para realizar calculos debe ingresar todos los valores.\n");
			}
			break;
		case 4:
			if(costoDelViajeAerolineas >= 1 && costoDelViajeLatam >= 1 && kmsDelViaje >= 1){
			mostrarResultados(kmsDelViaje, costoDelViajeAerolineas, precioAerolineasDebito,precioAerolineasCredito,precioAerolineasBtc,precioUnitarioAerolineas,
					costoDelViajeLatam, precioLatamDebito, precioLatamCredito, precioLatamBtc, precioUnitarioLatam, diferenciaDePrecio);}
			else{
				printf("Para ver los resultados debe ingresar valores y realizar calculos.\n");
			}
			printf("Presione enter para continuar...");
			fflush(stdin);
			break;
		case 5:
			kmsDelViaje = 7090;
			costoDelViajeAerolineas = 162965;
			costoDelViajeLatam = 159339;
			calcularPrecioConDebito(costoDelViajeAerolineas, &precioAerolineasDebito);
			calcularPrecioConCredito(costoDelViajeAerolineas, &precioAerolineasCredito);
			calcularPrecioConBitcoin(costoDelViajeAerolineas,&precioAerolineasBtc);
			calcularPrecioUnitario(costoDelViajeAerolineas, kmsDelViaje, &precioUnitarioAerolineas);
			calcularPrecioConDebito(costoDelViajeLatam, &precioLatamDebito);
			calcularPrecioConCredito(costoDelViajeLatam, &precioLatamCredito);
			calcularPrecioConBitcoin(costoDelViajeLatam,&precioLatamBtc);
			calcularPrecioUnitario(costoDelViajeLatam, kmsDelViaje, &precioUnitarioLatam);
			calcularDiferenciaEntreDosFlotantes(costoDelViajeAerolineas, costoDelViajeLatam, &diferenciaDePrecio);
			mostrarResultados(kmsDelViaje, costoDelViajeAerolineas, precioAerolineasDebito,precioAerolineasCredito,precioAerolineasBtc,precioUnitarioAerolineas,
								costoDelViajeLatam, precioLatamDebito, precioLatamCredito, precioLatamBtc, precioUnitarioLatam, diferenciaDePrecio);
			printf("Presione enter para continuar...");
			fflush(stdin);
			getchar();
			break;
		case 6:
			printf("Programa finalizado correctamente.");
			break;
		}
	}
	}while(opcion !=6);
	return 0;
}













