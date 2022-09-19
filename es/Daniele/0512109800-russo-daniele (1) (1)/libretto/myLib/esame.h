#include <stdbool.h>

typedef struct data *Data;
typedef struct voto *Voto;
typedef struct esame *Esame;

/*---------------COSTRUTTORI-----------------*/
Data newData(int gg, int mm, int aaaa);
Voto newVoto(int voto, bool isLode);
Esame newEsame(char *denominazione, Data data, Voto voto);
/*-------------------------------------------*/
Data inputData();
Voto inputVoto();
Esame inputEsame();

int getGiorno(Esame es);
int getMese(Esame es);
int getAnno(Esame es);
int getVoto(Esame es);
bool getLode(Esame es);
char *getDenominazione(Esame es);