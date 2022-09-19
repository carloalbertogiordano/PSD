typedef struct playlist *Playlist;
typedef struct song *Song;

Playlist newEmptyPlaylist(char *name);
Song newEmptySong();
void InitPlaylist(Playlist p, Song songs[], int nSongs);
void addHead(Playlist p, Song s);
void removeSongByName(Playlist p, char *song);
void orderByTitle(Playlist p);
