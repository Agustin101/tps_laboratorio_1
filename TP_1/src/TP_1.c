#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {
	setbuf(stdout, NULL);
	int kmsDelViaje;
	char opcion;
	float costoDelViajeAerolineas, costoDelViajeLatam, precioAerolineasDebito, precioLatamDebito,
	precioLatamCredito, precioAerolineasCredito, precioAerolineasBtc, precioLatamBtc;
	char respuesta;

	respuesta = 's';


	utn_getNumero(&opcion,"Seleccione una opcion\n1 Ingresar Kilometros\n2 Ingresar precio de vuelos\n3 Calcular todos los costos\n4 Informar costos\n5 Carga forzada de datos\n6 Salir","No es una opcion valida",1,6,2);

	printf("%s",opcion);




	return 0;

}












