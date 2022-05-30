// MusicPlayer only code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musicplayer.h"
#include "song.h"

typedef struct MusicPlayer musicPlayer;
typedef struct Song song;


int main()
{
  // CHANGE OUTPUT COLOR TO GREEN
  // THIS IS DONE ONLY FOR CLARITY, YOU ARE NOT REQUIRED TO DO THIS IN YOUR OWN DRIVER CODE
  printf("\033[0;32m");
  // THERE WILL BE ONLY 1 MUSIC PLAYER!
  musicPlayer* mp = createMusicPlayer();
  // AS MANY AS 1000 SONGS COULD BE THERE
  song** songs = (song**)malloc(1000 * sizeof(song*));
  // COUNTER TO KEEP NUMBER OF SONGS
  int numSongs = 0; 
  while(1)
  {
    char command[100];
    // INPUT COMMAND TYPE
    scanf(" %s", command);
    if(strcmp(command, "ADD") == 0)
    {
      // CREATE NEW SONG
      char *name = (char*)malloc(100 * sizeof(char));
      char *artist = (char*)malloc(100 * sizeof(char));
      float dur;
      scanf(" %s %s %f", name, artist, &dur);
      songs[numSongs++] = makeSong(name, artist, dur);
      printf("Song %s with artist %s and duration %f created\n", name, artist, dur);
    }
    else if(strcmp(command, "INSERT") == 0)
    {
      // INSERT SONG TO QUEUE OF MUSIC PLAYER
      char name[100];
      scanf(" %s", name);
      // FIND THE SONG IN THE LIST
      // NOTE: 2 SONGS WILL NOT HAVE THE SAME NAME IN OUR CODES!
      int idx = -1;
      for(int a = 0; a < numSongs; a++)
        if(strcmp(name, songs[a]->name) == 0)
          idx = a;
      // NO SUCH SONG
      if(idx == -1)
      {
        printf("No song found with name %s\n", name);
        continue;
      }
      // FOUND SONG, ADD TO MUSIC PLAYER
      if(addSongToQueue(mp, songs[idx]) == 1)
        // UNSUCCESSFUL OPERATION
        printf("Song %s couldn't be added to the music player\n", name);
      else
        // SUCCESSFUL OPERATION
        printf("Song %s added successfully\n", name);
    }
    else if(strcmp(command, "REMOVE") == 0)
    {
      // REMOVE SONG FROM MUSIC PLAYER
      int idx;
      scanf("%d", &idx);
      // REMOVE SONG FROM THE INDEX ASKED
      if(removeSongFromQueue(mp, idx) == 1)
        printf("Song at index %d couldn't be removed\n", idx);
      else
        printf("Song at index %d removed successfully\n", idx);
    }
    else if(strcmp(command, "PLAY") == 0)
    {
      // PLAY THE SONG
      if(playSong(mp) == 0)
        printf("Playing song\n");
      else
        printf("Couldn't play song\n");
    }
    else if(strcmp(command, "GET") == 0)
    {
      // GET THE CURRENT SONG PLAYING
      song* s = getCurrentSong(mp);
      if(s == NULL)
        printf("No song playing\n");
      else
        printf("Song %s is playing right now\n", s->name);
    }
    else if(strcmp(command, "EXIT") == 0)
      break;
    else
      printf("Invalid command\n");
  }
  return 0;
}
