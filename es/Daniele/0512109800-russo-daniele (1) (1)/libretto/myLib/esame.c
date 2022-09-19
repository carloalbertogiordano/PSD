#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esame.h"

#define MAX 50

struct data {
    int giorno;
    int mese;
    int anno;
};

struct voto {
    int voto;
    bool isLode; 
};

struct esame {
    char denominazione[MAX];
    Data data;
    Voto voto;
};

Data newData(int gg, int mm, int aaaa) {

    Data dt = malloc(sizeof(struct data));

    dt->giorno = gg;
    dt->mese = mm;
    dt->anno = aaaa;

    return dt;
}

Voto newVoto(int voto, bool isLode) {

    Voto vt = malloc(sizeof(struct voto));

    vt->voto = voto;
    vt->isLode = isLode;

    return vt;

}

Esame newEsame(char *denominazione, Data data, Voto voto) {

    Esame exam = malloc(sizeof(struct esame));

    strcpy(exam->denominazione, denominazione);
    exam->data = data;
    exam->voto = voto;

    return exam;

}


Data inputData() {

    int giorno, mese, anno;
    bool flag = true;

    printf("Inserisci la data!\n");

    do {
        printf("Inserisci l'anno -> ");
        scanf("%d", &anno);
        if (anno < 0)
            printf("L'anno non puo' essere negativo!\n");
    }while(anno < 0);

    do {
        printf("Inserisci il mese -> ");
        scanf("%d", &mese);
        if (mese < 1 || mese > 12)
            printf("Mese non valido!\n");
    }while(mese < 1 || mese > 12);

    do {
        flag = true;
        printf("Inserisci il giorno -> ");
        scanf("%d", &giorno);
        if (giorno < 1 || giorno > 31){ 
            printf("Giorno non valido!\n");
            flag = false;
        }
        else if (giorno == 31 && !(mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10 || mese == 12)) {
            printf("Il giorno 31 non e' presente in questo mese!\n");
            flag = false;
        }
        else if (giorno == 30 && !(mese == 4 || mese == 6 || mese == 9 || mese == 11)) {
            printf("Il giorno 30 non e' presente in questo mese!\n");
            flag = false;
        }
        else if (mese == 2 && (giorno < 1 || giorno > 29)) {
            printf("Giorno non valido!\n");
            flag = false;
        }
        else if (mese == 2 && giorno == 29 && !(anno % 400 == 0 || (anno % 4 == 0 && anno % 100 == 0))) {
            printf("Non puoi inserire 29 perchè l'anno non è bisestile\n");
            flag = false;
        }
    }while(flag == false);

    return newData(giorno, mese, anno);

}

Voto inputVoto() {

    int voto, lode;
    bool isLode;

    do {
        printf("Inserisci il voto dell'esame -> ");
        scanf("%d", &voto);
        if (voto < 18)
            printf("Voto non sufficiente per confermare l'esame!\n");
        else if (voto > 30)
            printf("Il voto e' troppo alto!\n");
        else if (voto == 30) {
            do {
                printf("Vuoi aggiungere la lode (0 => NO || 1 => SI) -> ");
                scanf("%d", &lode);
                if (lode < 0 || lode > 1)
                    printf("Hai sbagliato ad inserire!\n");
            }while(lode < 0 || lode > 1);
        }
    }while(voto < 18 || voto > 30);

    if (lode == 1)
        isLode = true;
    else
        isLode = false;

    return newVoto(voto, isLode);

}

Esame inputEsame() {

    char denominazione[MAX];
    Data dt;
    Voto vt;

    printf("Inserisci la denominazione dell'esame -> ");
    scanf("%s", denominazione);

    dt = inputData();
    vt = inputVoto();

    return newEsame(denominazione, dt, vt);

}

int getGiorno(Esame es) {
    return es->data->giorno;
}

int getMese(Esame es) {
    return es->data->mese;
}

int getAnno(Esame es) {
    return es->data->anno;
}

int getVoto(Esame es) { 
    return es->voto->voto;
}

bool getLode(Esame es) {
    return es->voto->isLode;
}

char *getDenominazione(Esame es) {
    char *denominazione = (char *) malloc((strlen(es->denominazione) + 1) * sizeof(char));
    strcpy(denominazione, es->denominazione);

    return denominazione;
}