#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void){
	setbuf(stdout, NULL);
	int kmsDelViaje = 0;
	int opcion;
	int valorPedirCosto;
	int opcionMenuAerolineas;
	int respuesta;
	int respuestaMenuAerolineas;
	float costoDelViajeAerolineas, costoDelViajeLatam, precioAerolineasDebito, precioLatamDebito,
	precioLatamCredito, precioAerolineasCredito, precioAerolineasBtc, precioLatamBtc;

	do{
		fflush(stdin);
	respuesta = utn_getNumero(&opcion,"Seleccione una opcion\n1 Ingresar Kilómetros: ( km = 0)\n2 Ingresar precio de vuelos\n3 Calcular todos los costos\n4 Informar resultados\n5 Carga forzada de datos\n6 Salir\n","No es una opcion valida.\n",1,6,1);
	if(respuesta == 00){
		switch(opcion){
		case 1:
			pedirKilometros(&kmsDelViaje);
				break;
		case 2:
			do{
				fflush(stdin);
			respuestaMenuAerolineas = utn_getNumero(&opcionMenuAerolineas,"Seleccione una opcion\n1 Ingresar precio Aerolineas\n2 Ingresar precio latam\n3 Volver a menu principal", "Ingrese una opcion valida\n",1,3,1);
			if(respuestaMenuAerolineas == 0){
				switch(opcionMenuAerolineas){
				case 1:
					fflush(stdin);
					valorPedirCosto = pedirCosto(&costoDelViajeAerolineas, "Debe ser un numero y mayor a 0.\n",1);

					break;
				case 2:

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
			break;
		case 4:
			mostrarResultados(kmsDelViaje, costoDelViajeAerolineas, precioAerolineasDebito,precioAerolineasCredito,precioAerolineasBtc);
			break;
		case 5:
			break;
		case 6:
			printf("Programa finalizado correctamente.");
			exit(-1);
			break;
		}
	}
	else{
		printf("Debe ingresar un numero. \n");
	}
	}while(respuesta ==0);


	return 0;
}












