// mpeisel CS201 Spring 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.mpeisel.h"

/*
    Creates a Song if: 1.) title and artist are not NULL, and 2.) artist and title have 0 < length <= MAXNAMELEN
    Returns a song if conditions are true, otherwise returns NULL.
*/
Song *createSong(char *title, char *artist, unsigned int year) {
    // check 1st condition
    if ((title == NULL) | (artist == NULL)) {
        return NULL;
    }
    // check 2nd condition
    if (((strlen(artist) > 0) & ((strlen(artist) < MAXNAMELEN))) & ((strlen(title) > 0) * (strlen(title) < MAXNAMELEN))) {
        // allocate space for Song
        Song *this_song = malloc(sizeof(Song));
        // assign variables
        strcpy(this_song->title, title);
        strcpy(this_song->artist, artist);
        this_song->year = year;
        return this_song;
    }
    return NULL;
}

/*
    Returns -1 if title of songOne precedes title of songTwo, 1 if songOne follows songTwo
    If the titles are the same: return -1 if artist of songOne precedes artist of songTwo, 1 if songOne follows songTwo
    If the artists are the same: return -1, 0, or 1 based on year values
*/
int compareSongs(const void *ptr1, const void *ptr2) {
    const Song *songOne = ptr1;
    const Song *songTwo = ptr2;
    if (strcmp(songOne->title, songTwo->title) < 0) {
        return -1;
    } 
    else if(strcmp(songOne->title, songTwo->title) > 0) {
        return 1;
    }
    if (strcmp(songOne->artist, songTwo->artist) < 0) {
        return -1;
    }
    else if (strcmp(songOne->artist, songTwo->artist) > 0) {
        return 1;
    }
    if (songOne->year < songTwo->year) {
        return -1;
    }
    else if (songOne->year > songTwo->year) {
        return 1;
    }
    return 0;
}

#define NUMSONGS 10
int buildSongArray(Song **songArray_p, int *numSongs) {
  *songArray_p = malloc(NUMSONGS * sizeof(Song));
  *numSongs = NUMSONGS;
  Song *songArray = *songArray_p;

  strcpy(songArray[0].title, "The Rain (Supa Dupa Fly");
  strcpy(songArray[0].artist, "Missy Elliott");
  songArray[0].year =  1997;

  strcpy(songArray[1].title, "I Can't Stand the Rain");
  strcpy(songArray[1].artist, "Ann Peebles");
  songArray[1].year = 1973;

  strcpy(songArray[2].title, "Ceremony");
  strcpy(songArray[2].artist, "New Order");
  songArray[2].year = 1981;

  strcpy(songArray[3].title, "Ceremony");
  strcpy(songArray[3].artist, "Radiohead");
  songArray[3].year = 2007;

  strcpy(songArray[4].title, "Fearless");
  strcpy(songArray[4].artist, "Taylor Swift");
  songArray[4].year = 2021;

  strcpy(songArray[5].title, "Fearless");
  strcpy(songArray[5].artist, "Taylor Swift");
  songArray[5].year = 2008;

  strcpy(songArray[6].title, "Good Will Come to You");
  strcpy(songArray[6].artist, "Fruit Bats");
  songArray[6].year = 2016;

  strcpy(songArray[7].title, "Take Me to the River");
  strcpy(songArray[7].artist, "Talking Heads");
  songArray[7].year = 1978;

  strcpy(songArray[8].title, "Take Me to the River");
  strcpy(songArray[8].artist, "Al Green");
  songArray[8].year = 1974;

  strcpy(songArray[9].title, "Long Black Veil");
  strcpy(songArray[9].artist, "Lefty Frizzell");
  songArray[9].year = 1959;

  return 0;
}


int main() {
    Song *songArray;
    int numSongs;
    buildSongArray(&songArray, &numSongs);

    printf("Unsorted:\n");
    int i;
    for (i = 0; i < numSongs; i++) {
        printf("Song #%d:\nTitle: %s\nArtist: %s\nYear: %d\n", i, songArray[i].title, songArray[i].artist, songArray[i].year);
    }

    printf("\nSorted:\n");
    qsort(songArray, numSongs, sizeof(Song), compareSongs);
    for (i = 0; i < numSongs; i++) {
        printf("Song #%d:\nTitle: %s\nArtist: %s\nYear: %d\n", i, songArray[i].title, songArray[i].artist, songArray[i].year);
    }
    printf("Done sorting!");
}