#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "musicplayer.h"
#include "song.h"

typedef struct User user;
typedef struct MusicPlayer musicPlayer;
typedef struct Song song;

int main()
{
  song** songs = (song**)malloc(100 * sizeof(song*));
  int numSongs = 0;
  user** users = (user**)malloc(100 * sizeof(user*));
  int numUsers = 0;

  char command[100]; 
  while(1)
  {
    scanf(" %s", command);
    if(strcmp(command, "ADD_USER") == 0) 
    {
      char* name = (char*)malloc(100 * sizeof(char));
      scanf(" %s", name);
      users[numUsers++] = createUser(name);
      printf("User %s created successfully\n", name);
    }
    else if(strcmp(command, "ADD_SONG") == 0)
    {
      char *name = (char*)malloc(100 * sizeof(char));
      char *artist = (char*)malloc(100 * sizeof(char));
      float dur;
      scanf(" %s %s %f", name, artist, &dur);
      songs[numSongs++] = makeSong(name, artist, dur);
      printf("Song %s with artist %s and duration %f created\n", name, artist, dur);
    }
    else if(strcmp(command, "INSERT_SONG") == 0)
    {
      char userName[100];
      char songName[100];
      scanf(" %s %s", userName, songName);
      int userIdx = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName, users[a]->name) == 0)
          userIdx = a;
      if(userIdx == -1)
      {
        printf("No such user\n");
        continue;
      }
      int songIdx = -1;
      for(int a = 0; a < numSongs; a++)
        if(strcmp(songName, songs[a]->name) == 0)
          songIdx = a;
      if(songIdx == -1)
      {
        printf("No such song\n");
        continue;
      }
      if(addSongToQueueUser(users[userIdx], songs[songIdx]) == 0)
        printf("Song %s added to queue of user %s\n", songs[songIdx]->name, users[userIdx]->name);
      else
        printf("Song couldn't be added to queue\n");
    }
    else if(strcmp(command, "REMOVE_SONG") == 0)
    {
      char userName[100];
      int songIdx;
      scanf(" %s %d", userName, &songIdx);
      int userIdx = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName, users[a]->name) == 0)
          userIdx = a;
      if(userIdx == -1)
      {
        printf("No such user\n");
        continue;
      }
      if(removeSongFromQueueUser(users[userIdx], songIdx) == 0)
        printf("Song removed successfully\n");
      else
        printf("Song couldn't be removed\n");
    }
    else if(strcmp(command, "PLAY_SONG") == 0)
    {
      char userName[100];
      scanf(" %s", userName);
      int userIdx = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName, users[a]->name) == 0)
          userIdx = a;
      if(userIdx == -1)
      {
        printf("No such user\n");
        continue;
      }
      if(playSongUser(users[userIdx]) == 0)
        printf("Playing song\n");
      else
        printf("Couldn't play song\n");
    }
    else if(strcmp(command, "GET_SONG") == 0)
    {
      char userName[100];
      scanf(" %s", userName);
      int userIdx = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName, users[a]->name) == 0)
          userIdx = a;
      if(userIdx == -1)
      {
        printf("No such user\n");
        continue;
      }
      song* cur = getCurrentSongUser(users[userIdx]);
      if(cur == NULL)
        printf("No song playing\n");
      else
        printf("Song %s is playing\n", cur->name);
    }
    else if(strcmp(command, "LIKE_SONG") == 0)
    {
      char userName[100];
      char songName[100];
      scanf(" %s %s", userName, songName);
      int userIdx = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName, users[a]->name) == 0)
          userIdx = a;
      if(userIdx == -1)
      {
        printf("No such user\n");
        continue;
      }
      int songIdx = -1;
      for(int a = 0; a < numSongs; a++)
        if(strcmp(songName, songs[a]->name) == 0)
          songIdx = a;
      if(songIdx == -1)
      {
        printf("No such song\n");
        continue;
      }
      if(addLikedSong(users[userIdx], songs[songIdx]) == 0)
        printf("Song %s liked by user %s\n", songs[songIdx]->name, users[userIdx]->name);
      else
        printf("Song couldn't be liked\n");
    }
    else if(strcmp(command, "UNLIKE_SONG") == 0)
    {
      char userName[100];
      char songName[100];
      scanf(" %s %s", userName, songName);
      int userIdx = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName, users[a]->name) == 0)
          userIdx = a;
      if(userIdx == -1)
      {
        printf("No such user\n");
        continue;
      }
      int songIdx = -1;
      for(int a = 0; a < numSongs; a++)
        if(strcmp(songName, songs[a]->name) == 0)
          songIdx = a;
      if(songIdx == -1)
      {
        printf("No such song\n");
        continue;
      }
      if(removeLikedSong(users[userIdx], songs[songIdx]) == 0)
        printf("Song %s unliked by user %s\n", songs[songIdx]->name, users[userIdx]->name);
      else
        printf("Song couldn't be unliked\n");
    }
    else if(strcmp(command, "COMPATIBILITY") == 0)
    {
      char userName[100], userName2[100];
      scanf(" %s %s", userName, userName2);
      int userIdx = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName, users[a]->name) == 0)
          userIdx = a;
      if(userIdx == -1)
      {
        printf("No such user\n");
        continue;
      }
      int userIdx2 = -1;
      for(int a = 0; a < numUsers; a++)
        if(strcmp(userName2, users[a]->name) == 0)
          userIdx2 = a;
      if(userIdx2 == -1)
      {
        printf("No user user\n");
        continue;
      }
      printf("User compatibility is: %d\n", userCompatibility(users[userIdx], users[userIdx2]));
    }
    else if(strcmp(command, "EXIT") == 0)
      break;
    else
      printf("Invalid command\n");
  }
  return 0;
}
