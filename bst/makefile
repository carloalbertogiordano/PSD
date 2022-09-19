link: bst.o main.o item_int.o
	gcc bst.o main.o item_int.o -o a.out

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item_int.c

bst.o:
	gcc -c bst.c

clean:
	rm *.o a.out
