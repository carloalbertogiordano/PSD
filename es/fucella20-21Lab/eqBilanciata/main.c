#include <stdio.h>
#include "eqTester.h"

int main(void){
  char *s1 = "(4 + a) * {[1 – (2/x)] * (8 – a)}";
  char* s2 = "[x – (4y + 3] * (1 – x))";

  if(checkBalance(s1))
    printf("bilanciata\n");
  else
    printf("Not balanced\n");
}
