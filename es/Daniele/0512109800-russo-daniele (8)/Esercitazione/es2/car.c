#include <stdlib.h>
#include "car.h"

#define DIMTARGA 7
#define MAXCHARS 30


typedef struct car
{
    char *targa;
    int annoImmatricolazione;
    char *modello;
    int annoProduzione;
}car;



Car newCar(char* targa, int annoImmatricolazione, char* modello, int annoProduzione)
{
    Car new=malloc(sizeof(car));

    if(new==NULL)
        return NULL;

    new->targa=targa;
    new->annoImmatricolazione=annoImmatricolazione;
    new->modello=modello;
    new->annoProduzione=annoProduzione;

    return new;
}




char* getTarga(Car car)
{
    return car->targa;
}




int getAnnoImmatricolazione(Car car)
{
    return car->annoImmatricolazione;
}




char* getModello(Car car)
{
    return car->modello;
}




int getAnnoProduzione(Car car)
{
    return car->annoProduzione;
}




Car removeCar(char *targa, List cars)
{
    Car tmp=newCar(targa, -1, NULL, -1);
    Car res=removeListForValue(cars, tmp);
    free(tmp);
    return res;
}




Car searchCar(char* targa, List cars)
{
    Car tmp=newCar(targa, -1, NULL, -1);
    int pos;
    Car res=searchList(cars, tmp, &pos);
    free(tmp);
    return res;
}