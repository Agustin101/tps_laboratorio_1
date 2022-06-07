#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "bibliotecaESDeDatos.h"

#define ARCHIVO_BIN "data.bin"
#define ARCHIVO_TXT "data.csv"

int main(){
	setbuf(stdout,NULL);

    int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    int flagGuardado=0;
    int flagArchivoCsv = 0;
    int flagArchivoBina = 0;
    int retorno;

    do{
    	fflush(stdin);
        if(utn_getInt(&option, "1)Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n2)Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n3)Alta de pasajero\n4)Modificar datos de pasajero\n5)Baja de pasajero.\n6)Listar pasajeros.\n7)Ordenar pasajeros\n8)Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n9)Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n10)Salir.", "Error introduza un numero dentro del rango", 1, 10, 2) == 0){
        	switch(option){
            case 1:
            	if(flagArchivoCsv == 0 && !controller_loadFromText(ARCHIVO_TXT,listaPasajeros)){
    				printf("El archivo se pudo leer y cerrar correctamente.\n");
    				flagArchivoCsv = 1;
            	}
            	else if(flagArchivoCsv == 1){
            		printf("No puede cargar el mismo archivo dos veces.\n");
            	}
            	else{
            		printf("Error al abrir el archivo.\n");
            	}
            break;
        	case 2:
        		if(flagArchivoBina == 0 && !controller_loadFromBinary(ARCHIVO_BIN,listaPasajeros)  ){
    				printf("\nEl archivo se pudo leer y cerrar correctamente.\n");
    				flagArchivoBina = 1;
        		}
        		else if(flagArchivoBina == 1){
            		printf("No puede cargar el mismo archivo dos veces.\n");
        		}
        		else{
        			printf("Error al abrir el archivo.\n");
        		}
        	break;
        	case 3:
        		if(!controller_addPassenger(listaPasajeros)){
					printf("\nPasajero dado de alta con exito.\n");
        		}
        		else{
        			printf("Hubo un error durante la carga del pasajero\n");
        		}
        	break;
        	case 4:
        		retorno = controller_editPassenger(listaPasajeros);
        		if(retorno==-1){
        			printf("El id ingresado no corresponde a ningun pasajero en la lista.\n");
        		}
        		else if (retorno==-2){
        			printf("Debe tener al menos un pasajero en la lista para poder modificar.\n");
        		}
        	break;
        	case 5:
        		retorno = controller_removePassenger(listaPasajeros);
        		if(retorno == 0){
					printf("Pasajero eliminado del sistema con exito.");
        		}
        		else if(retorno == -1){
    				printf("El id no coincide con ningun pasajero.\n");
        		}
        		else{
        			 printf("Debe tener al menos un pasajero en la lista para poder eliminar");
        		 }
        	break;
        	case 6:
        		retorno = controller_ListPassenger(listaPasajeros);
        		if(retorno == 0){
					printf("Lista impresa correctamente.\n");
        		}
        		else if(retorno == -1){
    				printf("Hubo un error durante la impresion de uno de los pasajeros.\n");
        		}
        		else{
        			 printf("Debe tener al menos un pasajero en la lista para poder listar.\n");
        		 }
        	break;
        	case 7:
        		retorno = controller_sortPassenger(listaPasajeros);
        		if(retorno == -2){
        			printf("Debe ingresar al menos un pasajero para ordenar la lista.\n");
        		}
        		else if(retorno==-1){
        			printf("Un error durante la seleccion del criterio de ordenamiento.\n");
        		}
        	break;
        	case 8:
        		if(!controller_saveAsText(ARCHIVO_TXT,listaPasajeros)){
        			printf("Archivo guardado correctamente.\n");
        			flagGuardado=1;
        		}
        	break;
        	case 9:
        		if(!controller_saveAsBinary(ARCHIVO_BIN,listaPasajeros)){
        			printf("Archivo guardado correctamente.\n");
        			flagGuardado=1;
        		}
        	break;
        	case 10:
        		if(flagGuardado== 0){
        			printf("No puede salir del programa sin guardar.");
        		}
        	break;
        	}
        }
    }while(option != 10);
    return 0;
}

