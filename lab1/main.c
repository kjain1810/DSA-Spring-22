#include <stdio.h>
#include "match.h"

struct Match* createTournament(int depth, int* idx)
{
  if(depth == 0)
  {
    struct Match* match = getMatch();
    if ( assignPlayer1(match, NULL, *idx) != 1)
      printf("Assign player1 failed!\n");
    (*idx)++;
    if ( assignPlayer2(match, NULL, *idx) != 1)
      printf("Assign player2 failed!\n");
    (*idx)++;
    if ( assignWinner(match, (*idx) - 2) != 1)
      printf("Assign winner failed!\n");
    return match;
  }
  struct Match* match = getMatch();
  struct Match* m1 = createTournament(depth - 1, idx);
  struct Match* m2 = createTournament(depth - 1, idx);
  if ( assignPlayer1(match, m1, m1->winner) != 1)
    printf("Assign player1 failed!\n");
  if ( assignPlayer2(match, m2, m2->winner) != 1)
    printf("Assign player2 failed!\n");
  if ( assignWinner(match, match->player1) != 1)
    printf("Assign winner failed!\n");
  return match;
}

int main()
{
  int* idx;
  (*idx) = 1;
  struct Match* tournament = createTournament(5, idx);
  printTournament(tournament);
  return 0;
}
