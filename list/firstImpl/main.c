#include "../list.h"
#include "../item.h"

int main(void){
    List l = newList();
    Item item;

    for(int i = 0; i < 10; i++){
      item = inputItem();
      addHead(l, item);
    }
    printList(l);
}
