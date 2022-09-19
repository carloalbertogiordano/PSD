#include "key.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

int equals(Key a, Key b)
{
  char *s1, *s2;
  s1 = a;
  s2 = b;
  if(strcmp(s1, s2) == 0)
    return 1;
  else
    return 0;
}

int hashValue(Key k, int dim)
{
  char *s;
  s = k;
  int h = 0, a = 128;
  for (; *s != '\0'; s++)
    h = (h*a + *s) % dim;
  return h;
}

Key inputKey()
{
  char *s;
  s = malloc(sizeof(char) * 30);
  scanf("%s", s);
  return s;
}

void outputKey(Key k)
{
  char *s;
  s = k;
  printf("%s ", s);
}
