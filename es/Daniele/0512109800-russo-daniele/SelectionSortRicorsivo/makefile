link : array utils main item_int
	gcc array.o utils.o item_int.o main.o -o eseguibile.exe

array :
	gcc -c array.c -o array.o

utils :
	gcc -c utils.c -o utils.o

main : 
	gcc -c -Wall main.c -o main.o

item_int :
	gcc -c item_int.c -o item_int.o

clean : 
	del array.o utils.o main.o item_int.o eseguibile.exe