link: item_int.o list.o stack_list.o main.o
	gcc oFiles/item_int.o oFiles/list.o oFiles/stack_list.o oFiles/main.o -o execute

item_int.o:
	gcc -c myLib/item_int.c -o oFiles/item_int.o

list.o:
	gcc -c myLib/list.c -o oFiles/list.o

stack_list.o:
	gcc -c myLib/stack_list.c -o oFiles/stack_list.o

main.o:
	gcc -c main.c -o oFiles/main.o

clean:
	rm -f oFiles/item_int.o oFiles/list.o oFiles/stack_list.o oFiles/main.o execute