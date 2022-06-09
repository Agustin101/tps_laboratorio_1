#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "bibliotecaESDeDatos.h"

int main(){
	setbuf(stdout,NULL);
    int option = 0;
    int flagGuardado=0;
    int flagArchivo = 0;
    int retorno;
    int respuesta = 1;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	option = menuPrincipal();
        switch(option){
           case 1:
        	   respuesta = 0;
            	if(flagArchivo == 0 && !controller_loadFromText(ARCHIVO_TXT,listaPasajeros)){
    				printf("El archivo se pudo leer y cerrar correctamente.\n");
    				flagArchivo = 1;
            	}
            	else if(flagArchivo == 1){
            		printf("No puede cargar el archivo de pasajeros dos veces.\n");
            	}
            	else{
            		printf("Error al abrir el archivo.\n");
            	}
            break;
        	case 2:
        		respuesta = 0;
        		if(flagArchivo == 0 && !controller_loadFromBinary(ARCHIVO_BIN,listaPasajeros)  ){
    				printf("\nEl archivo se pudo leer y cerrar correctamente.\n");
    				flagArchivo = 1;
        		}
        		else if(flagArchivo == 1){
            		printf("No puede cargar el archivo de pasajeros dos veces.\n");
        		}
        		else{
        			printf("Error al abrir el archivo.\n");
        		}
        	break;
        	case 3:
        		respuesta = 0;
        		if(!controller_addPassenger(listaPasajeros)){
					printf("\nPasajero dado de alta con exito.\n");
        		}
        		else{
        			printf("Hubo un error durante la carga del pasajero\n");
        		}
        	break;
        	case 4:
        		respuesta = 0;
        		retorno = controller_editPassenger(listaPasajeros);
        		if(retorno==-1){
        			printf("El id ingresado no corresponde a ningun pasajero en la lista.\n");
        		}
        		else if (retorno==-2){
        			printf("Debe tener al menos un pasajero en la lista para poder modificar.\n");
        		}
        	break;
        	case 5:
        		respuesta = 0;
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
        		respuesta = 0;
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
        		respuesta = 0;
        		retorno = controller_sortPassenger(listaPasajeros);
        		if(retorno == -2){
        			printf("Debe ingresar al menos un pasajero para ordenar la lista.\n");
        		}
        		else if(retorno==-1){
        			printf("Un error durante la seleccion del criterio de ordenamiento.\n");
        		}
        	break;
        	case 8:
        		respuesta = 0;
        		if(!controller_saveAsText(ARCHIVO_TXT,listaPasajeros)){
        			printf("Archivo guardado correctamente.\n");
        			flagGuardado=1;
        		}
        	break;
        	case 9:
        		respuesta = 0;
        		if(!controller_saveAsBinary(ARCHIVO_BIN,listaPasajeros)){
        			printf("Archivo guardado correctamente.\n");
        			flagGuardado=1;
        		}
        	break;
        	case 10:
        		if(flagGuardado== 0 && respuesta == 0){
        			controller_CerrarPrograma(listaPasajeros, &respuesta, flagArchivo);
        		}
        		else{
        			utn_getInt(&respuesta, "¿Esta seguro que desea salir?\n1)Si.\n2)No.", "Ingrese un numero entre los especificados.\n", 1, 2, 2);
        			if(respuesta == 1){
        				ll_deleteLinkedList(listaPasajeros);
        			}
        		}
        	break;
        	}
    }while(respuesta != 1);
    return 0;
}

