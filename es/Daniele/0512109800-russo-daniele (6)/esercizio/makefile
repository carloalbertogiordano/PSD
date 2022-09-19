link : BTree main item_string 
	gcc BTree.o main.o item_string.o -o BTree.exe
	
linkInt : BTree main item_int 
	gcc BTree.o main.o item_int.o -o BTree.exe

BTree :
	gcc -c BTree.c

item_int :
	gcc -c item_int.c

item_string :
	gcc -c item_string.c

main :
	gcc -c main.c


clean :
	del BTree.o main.o item_int.o item_string.o BTree.exe
