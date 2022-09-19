#include <stdlib.h>
#include "entry.h"
#include "item.h"
#include "key.h"

struct entry
{
  Key k;
  Item value;
};

Entry newEntry(Key k, Item value)
{
  Entry e;
  e = malloc(sizeof(struct entry));
  e->k = k;
  e->value = value;
  return e;
}

Key getKey(Entry e)
{
  if(e != NULL)
    return e->k;
  return NULL;
}

Item getValue(Entry e)
{
  if(e != NULL)
    return e->value;
  return NULL;
}
