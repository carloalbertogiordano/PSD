link : BTree main item_string queue_list list stack_list
	gcc BTree.o main.o item_string.o queue_list.o list.o stack_list.o -o BTree.exe

linkInt : BTree main item_int queue_list list
	gcc BTree.o main.o item_int.o queue_list.o list.o stack_list.o-o BTree.exe
	
queue_list :
	gcc -c queue_list.c

stack_list :
	gcc -c stack_list.c

BTree :
	gcc -c BTree.c

item_int :
	gcc -c item_int.c

item_string :
	gcc -c item_string.c

main :
	gcc -c main.c

list :
	gcc -c list.c

clean :
	del BTree.o main.o item_int.o item_string.o queue_list.o list.o stack_list.o BTree.exe
