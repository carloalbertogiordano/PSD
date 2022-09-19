typedef struct punto *Punto;

Punto creaPunto(int, int);
int ascissa(Punto);
int ordinata(Punto);
float distanza(Punto, Punto);
void sposta(Punto, int, int);
