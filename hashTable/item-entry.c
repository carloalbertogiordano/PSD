#include "item.h"
#include "entry.h"
#include "key.h"

int compareItem(Item i1, Item i2){
  Entry e1, e2;
  e1=i1;
  e2=i2;

  return !equals(getKey(e1), getKey(e2));
}
