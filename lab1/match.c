#include "match.h"

#include <stdlib.h>
#include <stdio.h>

struct Match* getMatch()
{
  struct Match* ret = (struct Match*)malloc(sizeof(struct Match));
  ret->player1 = -1;
  ret->player2 = -1;
  ret->winner = -1;
  ret->prevMatch1 = NULL;
  ret->prevMatch2 = NULL;
  return ret;
}

int assignPlayer1(struct Match* match, struct Match* prev, int pno)
{
  if(pno > 0 && match->player1 == -1)
  {
    if(prev == NULL || pno == prev->winner)
    {
      match->prevMatch1 = prev;
      match->player1 = pno;
      return 1;
    }
    else
      return 0;
  }
  else
    return 0;
  return 1;
}


int assignPlayer2(struct Match* match, struct Match* prev, int pno)
{
  if(pno > 0 && match->player2 == -1)
  {
    if(prev == NULL || pno == prev->winner)
    {
      match->prevMatch2 = prev;
      match->player2 = pno;
      return 1;
    }
    else
      return 0;
  }
  else
    return 0;
  return 1;
}

int assignWinner(struct Match *match, int pno)
{
  if(match->player1 <= 0 || match->player2 <= 0)
    return 0;
  if(pno != match->player1 && pno != match->player2)
    return 0;
  match->winner = pno;
  return 1;
}

void printTournament(struct Match *match)
{
  if(match->prevMatch1 != NULL)
    printTournament(match->prevMatch1);
  if(match->prevMatch2 != NULL)
    printTournament(match->prevMatch2);

  if(match->player1 <= 0 || match->player2 <= 0)
  {
    printf("Match info incomplete!\n");
    return;
  }
  
  if(match->winner != match->player1 && match->winner != match->player2)
  {
    printf("Player %d plays Player %d. Match info incorrect or incomplete!\n", match->player1, match->player2);
    return;
  }
  
  printf("Player %d plays Player %d. Player %d wins\n", match->player1, match->player2, match->winner);
  }
