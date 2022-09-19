#include <stdio.h>
#include "punto.h"
#include <math.h>

int main(void) {

  Punto p1 = creaPunto(1, 2);
  Punto p2 = creaPunto(3, 4);

  printf("dist: %.2f\n", distanza(p1, p2));

  sposta(p2, 100, 293);
  printf("dist: %.2f\n", distanza(p1, p2));

  return 0;
}
