str-int: list main item-int key-string hashtable entry item-entry
	gcc list.o main.o item-int.o key-string.o hashtable.o entry.o item-entry.o -o a.out

list :
	gcc -c list.c

main :
	gcc -c main.c

key-string :
	gcc -c key-string.c

hashtable :
	gcc -c hashtable.c

entry :
	gcc -c entry.c

item-int :
	gcc -c item-int.c

item-entry :
	gcc -c item-entry.c

clean:
	rm  *.o *.out
