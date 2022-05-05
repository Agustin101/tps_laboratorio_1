/*
 * ArrayPassenger.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Agustin
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct
{
int   id;
char  name[51];
char  lastName[51];
float price;
char  flycode[10];
int   typePassenger;
int   isEmpty;
}typedef Passenger;
/*
struct {
    char flyCode[10];
    char flightStatus[10];
    int  isEmpty;
} typedef Flight;
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[]);
int sortPassengersByFlyCode(Passenger* list, int len, int order);
int printPassenger(Passenger* list, int length);
int sortPassengersByName(Passenger* list, int len, int order);
int removePassenger(Passenger* list, int len, int id);
int findPassengerById(Passenger* list, int len,int id);
int initPassengers(Passenger* list, int len);

int findFreeIndex(Passenger* list,int len);
int thereIsPassenger(Passenger * list, int len);
int searchIndexForId(Passenger * list , int len, int id);



#endif /* ARRAYPASSENGER_H_ */
