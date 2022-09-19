#include <stdio.h>
#include "list.h"
#include "item.h"
#include "car.h"

#define n 3


int main()
{
    List cars=newList();
    Item item;
    char targa[10];

    for(int i=0; i<n; i++)
    {
        printf("REGISTRAZIONE NUOVO VEICOLO:\n");
        addHeadList(cars, inputItem());
        printf("\n");
    }

    printf("\n\nEcco il catalogo (i veicoli sono ordinati per anno di produzione):\n");
    selectionSort(cars);
    outputList(cars);

    printf("\n\nInserire la targa del veicolo da eliminare:\t");
    scanf("%s", targa);
    if((item=removeCar(targa, cars))==NULL)
        printf("Eliminazione non riuscita. Verificare la correttezza della targa inserita.\n");
    else
    {
        printf("E' stato eliminato il veicolo seguente.");
        outputItem(item);
    }

    printf("\n\nInserire la targa del veicolo da cercare:\t");
    scanf("%s", targa);
    if((item=searchCar(targa, cars))==NULL)
        printf("Veicolo non trovato.\n");
    else outputItem(item);

    return 0;
}