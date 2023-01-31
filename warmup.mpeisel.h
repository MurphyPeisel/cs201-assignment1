// mpeisel CS201 Spring 2023

#define MAXNAMELEN 63

typedef struct {
    char title[1+MAXNAMELEN];
    char artist[1+MAXNAMELEN];
    unsigned int year;
} Song;

/*
    Creates a Song if: 1.) title and artist are not NULL, and 2.) artist and title have 0 < length <= MAXNAMELEN
    Returns a song if conditions are true, otherwise returns NULL.
*/
Song *createSong(char *title, char *artist, unsigned int year);

/*
    Returns -1 if title of songOne precedes title of songTwo, 1 if songOne follows songTwo
    If the titles are the same, return -1 if artist of songOne precedes artist of songTwo, 1 if songOne follows songTwo
    If the artists are the same, return -1, 0, or 1 based on year values
*/
int compareSongs(const void *ptr1, const void *ptr2);

