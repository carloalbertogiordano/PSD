#include "punto.h"
#include <stdlib.h>
#include <math.h>

struct punto{
  int ascissa;
  int ordinata;
};

Punto creaPunto(int as, int or){
  struct punto *p = malloc(sizeof(struct punto));
  p->ascissa = as;
  p->ordinata = or;
  return p;
}

int ascissa(Punto p){
  return p->ascissa;
}

int ordinata(Punto p){
  return p->ordinata;
}

float distanza(Punto p1, Punto p2){
  return sqrt((ascissa(p2)-ascissa(p1))^2 + (ordinata(p2)-ordinata(p1))^2);
}

void sposta(Punto a, int as, int or){
  a->ascissa=as;
  a->ordinata=or;
}

Punto centroide(Punto punti[], int dim){
  int as=0, or=0;

  for(int i = 0; i < dim; i++){
    as+= punti[i]->ascissa;
    or+= punti[i]->ordinata;
  }
  as /= dim;
  or /= dim;
  Punto c = creaPunto(as, or);
  return c;
}
