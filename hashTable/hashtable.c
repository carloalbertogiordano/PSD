#include <stdlib.h>
#include "hashtable.h"
#include "entry.h"
#include "key.h"
#include "list.h"

struct hashtable{
  int size;
  List *entries;
};

HashTable newHashtable(int size){
  int i;
  HashTable h=malloc(sizeof(struct hashtable));
  h->entries=malloc(size*sizeof(List));
  h->size=size;

  for(i=0; i<size; i++)
    h->entries[i]=newList();

  return h;
}

int insertHash(HashTable h, Entry e){
  int index=hashValue(getKey(e), h->size);

  addHead(h->entries[index], e);
  return 1;
}

Entry searchHash(HashTable h, Key k){
  int n=0;
  int index=hashValue(k, h->size);

  Entry e=newEntry(k, NULL);
  return searchList(h->entries[index], e, &n);
}

Entry deleteHash(HashTable h, Key k){
  int index=hashValue(k, h->size);

  Entry e=newEntry(k, NULL);
  return removeListItem(h->entries[index], e);
}
