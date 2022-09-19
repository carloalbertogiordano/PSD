#include "list.h"

typedef struct car* Car;


Car newCar(char* targa, int annoImmatricolazione, char* modello, int annoProduzione);
char* getTarga(Car car);
int getAnnoImmatricolazione(Car car);
char* getModello(Car car);
int getAnnoProduzione(Car car);
Car removeCar(char *targa, List cars);
Car searchCar(char* targa, List cars);