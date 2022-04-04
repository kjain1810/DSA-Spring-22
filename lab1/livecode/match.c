#include "match.h"

#include <stdlib.h>
#include <stdio.h>

struct Match* getMatch()
{
  struct Match* match = (struct Match*)malloc(sizeof(struct Match));

  match -> player1 = -1;
  match -> player2 = -1;
  match -> winner = -1;
  match -> prevMatch1 = NULL;
  match -> prevMatch2 = NULL;

  return match;
}

int assignPlayers(struct Match * match, int p1, int p2, struct Match *pM1, struct Match *pM2)
{
  // if assigned successfully, return 1
  // otherwise 0
  if(match == NULL)
    return 0;
  if(p1 <= 0 || p2 <= 0)
    return 0;
  if(p1 == p2)
    return 0;
  if (pM1 != NULL && pM1 == pM2)
    return 0;
  if(pM1 != NULL && pM1 -> winner != p1)
    return 0;
  if(pM2 != NULL && pM2 -> winner != p2)
    return 0;
  match -> player1 = p1;
  match -> player2 = p2;
  match -> prevMatch1 = pM1;
  match -> prevMatch2 = pM2;
  return 1;
}

int assignWinner(struct Match *match, int w)
{
  // return 1 if assignment is valid
  // return 0 otherwise
  if (match == NULL)
    return 0;
  if(w <= 0)
    return 0;
  if(w != match->player1 && w != match->player2)
    return 0;
  match->winner = w;
  return 1;
}

void printTournament(struct Match *match)
{
  if(match == NULL)
    return;
  if(match -> prevMatch1 != NULL)
    printTournament(match->prevMatch1);
  if(match -> prevMatch2 != NULL)
    printTournament(match->prevMatch2);
  printf("Player %d plays Player %d. Player %d wins\n", match->player1, match->player2, match->winner);  
}
