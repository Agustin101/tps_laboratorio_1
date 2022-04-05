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
	float costoDelViajeAerolineas, costoDelViajeLatam, precioAerolineasDebito, precioLatamDebito,
	precioLatamCredito, precioAerolineasCredito, precioAerolineasBtc, precioLatamBtc;

	do{
		fflush(stdin);
	respuesta = utn_getNumero(&opcion,"Seleccione una opcion\n1 Ingresar Kilómetros: ( km = 0)\n2 Ingresar precio de vuelos\n3 Calcular todos los costos\n4 Informar resultados\n5 Carga forzada de datos\n6 Salir\n","No es una opcion valida\n",1,6,1);
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
					pedirCosto(&costoDelViajeAerolineas);
					printf("%f",costoDelViajeAerolineas);
					break;
				case 2:
					pedirCosto(&costoDelViajeLatam);
					printf("%f",costoDelViajeLatam);
					break;
				}
			}
			else{
				printf("Volviendo al menu principal.\n");
				break;
				}
			}while(opcionMenuAerolineas !=3 && respuestaMenuAerolineas != 0);

			break;
		case 3:
			break;
		case 4:
			printf("Los kilometros ingresados son: %d\nPrecio aerolineas: %.2f\nPrecio latam: %.2f\n",kmsDelViaje,costoDelViajeAerolineas,costoDelViajeLatam);
			break;
		}
	}
	else{
		printf("Opcion invalida. Debe ingresar un numero. \n");
	}
	}while(opcion != 6 && respuesta ==0);

	printf("Programa finalizado correctamente.");
	return 0;
}












