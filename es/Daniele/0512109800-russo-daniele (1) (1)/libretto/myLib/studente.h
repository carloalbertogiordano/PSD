typedef struct studente *Studente;

Studente newStudente(char *nome, char *cognome, char *matricola);
char *getNome(Studente std);
char *getCognome(Studente std);
char *getMatricola(Studente std);