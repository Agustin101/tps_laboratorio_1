#include "Passenger.h"

/// @brief  asigna espacio de memoria para un nuevo pasajero
///
/// @return Devuelve el puntero a memoria
Passenger* Passenger_new(){
	Passenger * pasajeroAux = NULL;
	pasajeroAux = (Passenger *)malloc(sizeof(Passenger));
	if(pasajeroAux != NULL){
		 Passenger_setId(pasajeroAux,0);
		 Passenger_setNombre(pasajeroAux," ");
		 Passenger_setApellido(pasajeroAux," ");
		 Passenger_setPrecio(pasajeroAux,0);
		 Passenger_setTipoPasajero(pasajeroAux,0);
		 Passenger_setCodigoVuelo(pasajeroAux," ");
		 Passenger_setStatusFlight(pasajeroAux," ");
	}
	return pasajeroAux;
}

/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param tipoPasajeroStr
/// @param codigoVueloStr
/// @param estadoDeVueloStr
/// @return
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char * apellidoStr, char * precioStr, char* tipoPasajeroStr, char* codigoVueloStr,char*estadoDeVueloStr){
	Passenger * this = NULL;
	int idAux;
	float precioAux;
	int tipoPasajeroAux;

	this = Passenger_new();
	tipoPasajeroAux = Passenger_tipoPasajero(this,tipoPasajeroStr);

	if(this != NULL && tipoPasajeroAux != -1 && idStr != NULL && nombreStr !=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!= NULL && estadoDeVueloStr != NULL){
		idAux = atoi(idStr);
		precioAux = atof(precioStr);
		if(Passenger_setId(this, idAux) == -1 || Passenger_setPrecio(this, precioAux) == -1 || Passenger_setTipoPasajero(this, tipoPasajeroAux)	== -1 ||
			Passenger_setNombre(this, nombreStr) == -1 || Passenger_setApellido(this, apellidoStr) == -1 || Passenger_setCodigoVuelo(this, codigoVueloStr) ||
			Passenger_setStatusFlight(this, estadoDeVueloStr)==-1){
			Passenger_delete(this);
			this=NULL;
		}
	}
	return this;
}

/// @brief Borra un puntero a pasajero y libera el espacio de memoria.
///
/// @param Passenger * this
void Passenger_delete(Passenger * this){
	if(this != NULL){
		free(this);
	}
}

/// @brief asigna el id al campo del pasajero
///
/// @param Passenger* this
/// @param int id
/// @return int retorno -1 si falla 0 si puede
int Passenger_setId(Passenger* this,int id){
	int retorno = -1;

	if(this != NULL && id >0){
			this->id = id;
			retorno = 0;
	}
	return retorno;
}



/// @brief obtiene el id del campo del pasajero
///
/// @param Passenger* this
/// @param int* id
/// @return int retorno -1 si falla 0 si puede
int Passenger_getId(Passenger* this,int* id){
	int retorno = -1;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/// @brief asigna el nombre al campo del pasajero
///
/// @param Passenger* this
/// @param char* nombre
/// @return int retorno -1 si falla 0 si puede
int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		if(esNombre(nombre)){
			strcpy(this->nombre,nombre);
			retorno = 0;
		}
	}
	return retorno;
}
/// @brief obtiene el nombre del campo del pasajero
///
/// @param Passenger* this
/// @param char* nombre
/// @return int retorno -1 si falla 0 si puede
int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		retorno = 0;
		strcpy(nombre,this->nombre);
	}
	return retorno;
}

/// @brief asigna el apellido al campo del pasajero
///
/// @param Passenger* this
/// @param char* apellido
/// @return int retorno -1 si falla 0 si puede
int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno = -1;
	if(this != NULL && apellido != NULL){
		if(esNombre(apellido)){
			strncpy(this->apellido,apellido,sizeof(this->apellido));
			retorno = 0;
		}
	}
	return retorno;
}

/// @brief obtiene el apellido del campo del pasajero
///
/// @param Passenger* this
/// @param char* apellido
/// @return int retorno -1 si falla 0 si puede
int Passenger_getApellido(Passenger* this,char* apellido){
	int retorno = -1;
	if(this != NULL && apellido != NULL){
		retorno = 0;
		strcpy(apellido,this->apellido);
	}
	return retorno;
}

/// @brief asigna el codigo al campo del pasajero
///
/// @param Passenger*this
/// @param char* codigoVuelo
/// @return int retorno -1 si falla 0 si puede
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL){
		if(esCodigo(codigoVuelo)){
			strcpy(this->codigoVuelo,codigoVuelo);
			retorno = 0;
		}
	}
	return retorno;

}

/// @brief obtiene el codigo del campo del pasajero
///
/// @param Passenger*this
/// @param char* codigoVuelo
/// @return int retorno -1 si falla 0 si puede
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL){
		retorno = 0;
		strcpy(codigoVuelo,this->codigoVuelo);
	}
	return retorno;
}

/// @brief asigna el tipo al campo del pasajero
///
/// @param Passenger*this
/// @param int tipoPasajero
/// @return int retorno -1 si falla 0 si puede
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0){
			this->tipoPasajero = tipoPasajero;
			retorno = 0;
	}
	return retorno;
}

/// @brief Verifica el tipo de pasajero mediante la cadena ingresada
///
/// @param Passenger * this
/// @param char * tipoPasajeroStr
/// @return -1 si falla o un define del tipo si pudo asignarlo correctamente.
int Passenger_tipoPasajero(Passenger * this, char * tipoPasajeroStr){
	int retorno = -1;

	if(this != NULL && tipoPasajeroStr != NULL){
		if(strcmp(tipoPasajeroStr, "FirstClass")==0){
			retorno = FIRSTCLASS;
		}
		else if(strcmp(tipoPasajeroStr, "ExecutiveClass")==0){
			retorno = EXECUTIVECLASS;
		}
		else if(strcmp(tipoPasajeroStr, "EconomyClass")==0){
			retorno = ECONOMYCLASS;
		}
	}
	return retorno;
}

int Passenger_tipoPasajeroTxt(Passenger * this,int tipoPasajeroInt, char * tipoPasajeroStr){
	int retorno = -1;
	char bufferAux[50];

	if(this != NULL && tipoPasajeroStr != NULL){
		retorno = 0;
		if(tipoPasajeroInt == FIRSTCLASS){
			strcpy(bufferAux, "FirstClass");
			strcpy(tipoPasajeroStr,bufferAux);
		}
		else if(tipoPasajeroInt == EXECUTIVECLASS){
			strcpy(bufferAux, "ExecutiveClass");
			strcpy(tipoPasajeroStr,bufferAux);
		}
		else if(tipoPasajeroInt == ECONOMYCLASS){
			strcpy(bufferAux, "EconomyClass");
			strcpy(tipoPasajeroStr,bufferAux);
		}
	}
	return retorno;
}

/// @brief obtiene el tipo del campo del pasajero
///
/// @param Passenger* this
/// @param int* tipoPasajero
/// @return int retorno -1 si falla 0 si puede
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL){
		retorno = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return retorno;
}

/// @brief asigna el precio al campo del pasajero
///
/// @param Passenger* this
/// @param float precio
/// @return int retorno -1 si falla 0 si puede
int Passenger_setPrecio(Passenger* this,float precio){
	int retorno = -1;

	if(this != NULL && precio > 0){
			this->precio = precio;
			retorno = 0;
	}
	return retorno;
}

/// @brief obtiene el precio del campo del pasajero
///
/// @param Passenger* this
/// @param float* precio
/// @return int retorno -1 si falla 0 si puede
int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno = -1;
	if(this != NULL && precio >0){
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

/// @brief asigna el estado de vuelo al campo del pasajero
///
/// @param Passenger* this
/// @param char* estadoDeVueloStr
/// @return int retorno -1 si falla 0 si puede
int Passenger_setStatusFlight(Passenger* this,char*estadoDeVueloStr){
	int retorno = -1;
	if(this != NULL && estadoDeVueloStr != NULL){
		if(esNombre(estadoDeVueloStr)){
			strcpy(this->statusFlight,estadoDeVueloStr);
			retorno = 0;
		}
	}
	return retorno;
}

/// @brief obtiene el estado de vuelo del campo del pasajero
///
/// @param Passenger* this
/// @param estadoDeVueloStr
/// @return int retorno -1 si falla 0 si puede
int Passenger_getStatusFlight(Passenger* this,char*estadoDeVueloStr){
	int retorno = -1;
	if(this != NULL && estadoDeVueloStr != NULL){
		retorno = 0;
		strcpy(estadoDeVueloStr,this->statusFlight);
	}
	return retorno;
}


