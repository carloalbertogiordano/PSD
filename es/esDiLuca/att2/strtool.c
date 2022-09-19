#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strtool.h"

struct string{
  char *v;
};

struct matrix{
  /*struct string* nome;
  struct string* cognome;*/
  char **v;
  int size;
};

struct string* buildString(int l){
  struct string *st = malloc(sizeof(struct string));
  st->v = malloc(sizeof(char)*l);
  scanf("%s", st->v);
  fflush(stdin);
  return st;
}

Nome creaNome(int l){
  printf("Inserisci il nome: ");
  Nome n = buildString(l);
  return n;
}

Cognome creaCognome(int l){
  printf("Inserisci il cognome: ");
  Cognome c = buildString(l);
  return c;
}

Matrix buildMatrix(Nome n, Cognome c){
  Matrix m = malloc(sizeof(struct matrix));
  int sN = sizeof(n->v);
  int sC = sizeof(c->v);

  int len = (sN > sC) ? sN:sC;

  m->v = malloc(sizeof(char)*2);

  m->v[0] = malloc(sizeof(char) * (len));
  m->v[1] = malloc(sizeof(char) * (len));

  strcpy(m->v[0], n->v);
  strcpy(m->v[1], c->v);

  m->size=2;
  /*
  m->nome = n; //malloc(sizeof(struct string));
  m->cognome = c; //malloc(sizeof(struct string));*/
  return m;
}

void stampa(Nome no, Cognome co){
  printf("Nome: %s\tCognome: %s\n",no->v,co->v);
}

void stampaMatrice(Matrix m){

  for(int i = 0; i < m->size; i++)
    printf("matrix size%d \trow:%d val%s\n", m->size, i, m->v[i]);

  //String nome = malloc(sizeof(struct string));
  //nome->v = malloc(sizeof(char)*m->size);
  //String cognome = malloc(sizeof(struct string));
  //cognome->v = malloc(sizeof(char)*m->size);

  //strcpy(nome->v, m->v[0]);
  //strcpy(cognome->v, m->v[1]);

  //printf("MATRIX: Nome:%s\tCognome%s\n",nome->v, cognome->v);
}

String Merge(Nome n, Cognome c){
  int sizeN = sizeof(n->v);
  int sizeC = sizeof(c->v);
  String s = malloc(sizeof(struct string));
  s->v = malloc((sizeof(char)*(sizeC+sizeN))+1);
  strcpy(s->v, n->v);
  strcat(s->v, c->v);
  return s;
}

void printString(String s){
  printf("%d ", strlen(s->v));
  printf("%s", s->v);
}

String stringIncas(String f, String s, int sf/*bigger string*/, int ss){
  String res = malloc(sizeof(struct string));
  res->v = malloc(sizeof(char)*sf);
  printf("sf:%d, ss:%d\n",sf, ss);
  int part = (sf/2)-(ss/2);
  printf("part:%d\n", part);
    res->v[0]=f->v[0];
    for(int i = 1; i< part; i++){
      char tmp[2];
      tmp[0]=f->v[i];
      tmp[1]='\0';
      strcat(res->v, tmp);
    }
    strcat(res->v, s->v);//centre
    for(int i = strlen(res->v); i< sf; i++){//what is left
      char tmp[2];
      tmp[0] = f->v[strlen(res->v)];
      tmp[1] = '\0';
      strcat(res->v, tmp);
    }
  return res;
}

String incastona(Matrix m){
  String nome = malloc(sizeof(struct string));
  nome->v = malloc(sizeof(char)*m->size);
  String cognome = malloc(sizeof(struct string));
  cognome->v = malloc(sizeof(char)*m->size);
  String res;

  strcpy(nome->v, m->v[0]);
  strcpy(cognome->v, m->v[1]);

  int sizeN = strlen(nome->v);
  int sizeC = strlen(cognome->v);

  if(sizeN==sizeC){
    printf("stringhe della stella lunghezza, impossibile concatenare\n");
    return NULL;
  }

  if(sizeN>sizeC){//Nome > cognome
      res = stringIncas(nome, cognome, sizeN, sizeC);
  }
  else{
    res = stringIncas(cognome, nome, sizeC, sizeN);
  }
  return res;
}

void inverti(Matrix m){
  for(int i = 0; i < m->size; i++){
    char tmp = m->v[0][i];
    m->v[0][i] = m->v[1][i];
    m->v[1][i] = tmp;
  }
}

void crea(Matrix m){
  m->v[2] = malloc(sizeof(char)*7);

  char tmp[7];
  tmp[7] = '\0';
  for(int i = 0; i<3; i++)
    tmp[i] = m->v[0][i];
  for(int j = 6; j>3; j--)
    tmp[j] = m->v[1][ strlen(m->v[1])-j ];
  printf("exp: %s\n", tmp);
  strcpy(m->v[2], tmp);
  m->size=3;
}

void ordina(String str){
  char *a = str->v;
  int size = strlen(a);

  for(int i = 0; i < size; i++){
    for(int j = 0; j<i; j++){
      if(a[j] > a[j+1]){
        char tmp = a[j+1];
        a[j+1] = a[j];
        a[j] = tmp;
      }
    }
  }
}
