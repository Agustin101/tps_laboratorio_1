/*
 * utn.c
 *
 *  Created on: 3 abr. 2022
 *      Author: Agustin
 */
#include "bibliotecaESDeDatos.h"

int utn_getInt(int * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	int buffer;

	retorno = -1;

	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		printf("%s",pMensaje);
		scanf("%i", &buffer);
		fflush(stdin);
		do{
		if(buffer >= minimo && buffer <= maximo && isdigit(buffer)==0){
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		else{
			printf("%s",pMensajeError);
			fflush(stdin);
			scanf("%i", &buffer);
			reintentos--;
		}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getFloat(float * pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	float buffer;

	retorno = -1;

	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		printf("%s",pMensaje);
		scanf("%f", &buffer);
		fflush(stdin);
		do{
		if(buffer >= minimo && buffer <= maximo && isdigit(buffer)==0){
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		else{
			printf("%s",pMensajeError);
			fflush(stdin);
			scanf("%f", &buffer);
			reintentos--;
		}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getString(char retString[], char * pMensaje, char *pMensajeError, int len){
	int retorno;
	int flag;
	int esNumero;
	int i;
	i=0;
	flag = 0;
	char buffer[51];

	if(retString != NULL && pMensaje != NULL && pMensajeError != NULL && len > 0){
		printf("%s",pMensaje);
		fflush(stdin);
		gets(buffer);
		while(i < strlen(buffer) && flag == 0){
			esNumero=isalpha(buffer[i]);
				if((esNumero != 0 &&strlen(buffer) < len) || buffer[i] == ' ' ){
					//while(i<len){
						//buffer[i] =  toupper((unsigned char) buffer[i]);
						//i++;
					//} Puedo usar para convertir en uppercase todos los caracteres a la hora del sort
					i++;
					retorno =0;
				}
				else{
					flag = 1;
					retorno = -1;
					}
		}
		if(retorno == 0){
			strcpy(retString, buffer);
		}
		else{
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}

int utn_getFlyCode(char retString[], char * pMensaje, char *pMensajeError, int len, int reintentos){
	int retorno;
	char buffer[10];
	retorno = -1;
	int i;
	i=0;

		if(retString != NULL && pMensaje != NULL && pMensajeError != NULL && len > 0 && reintentos > 0){
			printf("%s",pMensaje);
			fflush(stdin);
			gets(buffer);
				do{
					if(strlen(buffer) < len && strlen(buffer) > 0){
						while(i<len){
							buffer[i] =  toupper((unsigned char) buffer[i]);
							i++;
						}
						strcpy(retString, buffer);
						retorno =0;
						break;
					}
					else{
						printf("%s",pMensajeError);
						fflush(stdin);
						gets(buffer);
						reintentos--;
						}
				}while(reintentos >= 0);

		}
		return retorno;
}







