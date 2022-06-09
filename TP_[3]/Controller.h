int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_sortById(void* primerElemento, void* segundoElemento);
int controller_sortByName(void* primerElemento, void* segundoElemento);
int controller_sortByLastName(void* primerElemento, void* segundoElemento);
int controller_sortByPrice(void* primerElemento, void* segundoElemento);
int controller_sortByFlyCode(void* primerElemento, void* segundoElemento);
int controller_sortByTypePassenger(void* primerElemento, void* segundoElemento);
int controller_sortByFlightStatus(void* primerElemento, void* segundoElemento);

#define ARCHIVO_BIN "data.bin"
#define ARCHIVO_TXT "data.csv"
int controller_CerrarPrograma(LinkedList* pArrayListPassenger, int * respuesta);


int controller_generarId( LinkedList* pArrayListPassenger);
//int controller_generarId( LinkedList* pArrayListPassenger, char * pathCsv, char * pathBinary);
//int controller_generarIdFromText(char* path , LinkedList* pArrayListPassenger);
//int controller_generarId(char* pathCsv , LinkedList* pArrayListPassenger, char * pathBina);


