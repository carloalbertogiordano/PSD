#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "item.h"
#include "car.h"



Item inputItem()
{
    char *targa=malloc(sizeof(char)*10);
    int annoImmatricolazione;
    int annoProduzione;
    char *modello=malloc(sizeof(char)*30);

    printf("Targa:\t\t\t\t");
    scanf("%s", targa);

    printf("Anno di immatricolazione:\t");
    scanf("%d", &annoImmatricolazione);
    getchar();

    printf("Modello:\t\t\t");
    scanf("%[^\n]", modello);

    printf("Anno di produzione:\t\t");
    scanf("%d", &annoProduzione);

    return newCar(targa, annoImmatricolazione, modello, annoProduzione);
}




void outputItem(Item item)
{
    Car car=item;

    printf("\n\nTarga:\t\t\t\t%s", getTarga(car));
    printf("\nAnno di immatricolazione:\t%d", getAnnoImmatricolazione(car));
    printf("\nModello:\t\t\t%s", getModello(car));
    printf("\nAnno di produzione:\t\t%d", getAnnoProduzione(car));
}




int cmpItemsAnnoP(Item item1, Item item2)
{
    Car a=item1, b=item2;
    return getAnnoProduzione(a)-getAnnoProduzione(b);
}




int cmpItemsTarga(Item item1, Item item2)
{
    Car a=item1, b=item2;
    return strcmp(getTarga(a), getTarga(b));
}