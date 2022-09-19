link: item_int.o list.o stack_list.o main.o
	gcc item_int.o list.o stack_list.o main.o -o execute

item_int.o:
	gcc -c item_int.c -o item_int.o

list.o:
	gcc -c list.c -o list.o

stack_list.o:
	gcc -c stack_list.c -o stack_list.o

main.o:
	gcc -c main.c -o main.o

clean:
	del item_int.o list.o stack_list.o main.o execute