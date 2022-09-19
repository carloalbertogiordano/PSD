link: list.o main.o item_int.o stack.o
	gcc list.o main.o item_int.o stack.o -o a.out

main.o:
	gcc -c main.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c

stack.o:
	gcc -c stack.c

list.o:
	gcc -c list.c

clean:
	rm *.o a.out
