typedef struct string *Nome;
typedef struct string *Cognome;
typedef struct matrix *Matrix;
typedef struct string *String;

Nome creaNome(int);
Cognome creaCognome(int);
void stampa(Nome, Cognome);
Matrix buildMatrix(Nome, Cognome);
void stampaMatrice(Matrix);
String Merge(Nome, Cognome);
void printString(String);
String incastona(Matrix);
void inverti(Matrix);
void crea(Matrix);
void ordina(String);
