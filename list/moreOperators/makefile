link : item_int list main
	gcc item.o list.o main.o -o a.out

linkStr : item_string list main
	gcc item.o list.o main.o -o a.out

item_int :
	gcc -o item.o -c ../item_int.c

item_string :
	gcc -o item.o  -c ../item_string.c

list :
	gcc -c ../list.c

main :
	gcc -c main.c

clean :
	rm item.o list.o main.o a.out
