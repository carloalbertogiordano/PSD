typedef struct libretto* Libretto;

Libretto newLibretto(char *n, char *s);
void addExam(Libretto l, char *ex, int s);
int searchExamByName(Libretto l, char *name;
