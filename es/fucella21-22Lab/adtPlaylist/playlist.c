#include "playlist.h"
#include <string.h>
#include <stdlib.h>

struct song{
  char *title;
  char *singerName;
  int length;
};

struct node{
  struct node *next;
  struct song *s;
};

struct playlist{
  char *name;
  struct node *head;
  int size;
};

Playlist newEmptyPlaylist(char *name){
  Playlist play = malloc(sizeof(struct playlist));
  play->name = malloc(sizeof(char)*strlen(name));
  strcpy(play->name, name);
  free(name);
  play->size = 0;
  return play;
}

Song newEmptySong(){
  Song s = malloc(sizeof(struct song));
  return s;
}

struct node* newEmptyNode() {
  struct node *n = malloc(sizeof(struct node));
  n->s = newEmptySong();
  return n;
}

void InitPlaylist(Playlist p, Song songs[], int nSongs) {
  for(int i = 0; i < nSongs; i++){
    addHead(p, songs[i]);
  }
}

void addHead(Playlist p, Song s){
  struct node *n = newEmptyNode();
  n->s = s;
  if(n->next != NULL)
    n->next = p->head;
  p->head = n;
  p->size++;
}

void removeSongByName(Playlist p, char *song){
  struct node *n = p->head;
  struct node *nprev = n;

  for(int i = 0; i < p->size; i++){
    if(n->s->title == song){
      if(i == 0) p->head = n->next;
      else nprev->next = n->next;
      free(n);
    }
    nprev = n;
    n = n->next;
  }
}

Song cpySong(Song old){
  Song s = malloc(sizeof(struct song));

  s->title = malloc(sizeof(char)*strlen(old->title));
  strcpy(s->title, old->title);
  s->singerName = malloc(sizeof(char)*strlen(old->singerName));
  strcpy(s->singerName, old->singerName);
  s->length = old->length;

  return s;
}

void songBubbleSort(Song *s, int size) {
  for(int i = 0; i < size; i++){
    for(int j = 0; j < i; j++){
      if(strcmp(s[i]->title, s[i+1]->title)>0){
        Song tmp = s[i];
        s[i] = s[i+1];
        s[i+1] = tmp;
      }
    }
  }
}

void freePlaylist(Playlist p){
  struct node *n = p->head;

  if(p->size == 0){}
  else{
    do{
      struct node *nprev = n;
      n = n->next;
      free(nprev);
    }while(n != NULL);
  }
  p->size = 0;
}

void orderByTitle(Playlist p){
  int size = p->size;
  Song *s = malloc(sizeof(struct song) * size);
  struct node *n = p->head;

  for(int i = 0; i < size; i++){
    s[i] = cpySong(n->s);
    n = n->next;
  }
  songBubbleSort(s, size);
  InitPlaylist(p, s, size);
  free(s);
}
