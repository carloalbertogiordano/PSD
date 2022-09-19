link: esame.o studente.o item_esame.o list.o libretto.o main.o
	gcc oFiles/esame.o oFiles/studente.o oFiles/item_esame.o oFiles/list.o oFiles/libretto.o oFiles/main.o -o execute

esame.o:
	gcc -c myLib/esame.c -o oFiles/esame.o
studente.o:
	gcc -c myLib/studente.c -o oFiles/studente.o
item_esame.o:
	gcc -c myLib/item_esame.c -o oFiles/item_esame.o
list.o:
	gcc -c myLib/list.c -o oFiles/list.o
libretto.o:
	gcc -c myLib/libretto.c -o oFiles/libretto.o
main.o:
	gcc -c main.c -o oFiles/main.o

clean:
	rm -f oFiles/esame.o oFiles/studente.o oFiles/item_esame.o Files/list.o oFiles/libretto.o oFiles/main.o execute