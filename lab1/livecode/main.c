#include <stdio.h>

#include "match.h"

int makeMatch(struct Match *match)
{
  int p1, p2, w;
  printf("Enter p1, p2, w ");
  scanf("%d %d %d", &p1, &p2, &w);
  if(assignPlayers(match, p1, p2, (struct Match*)NULL, (struct Match *)NULL) == 0)
    return 0;
  if(assignWinner(match, w) == 0)
    return 0;
  return 1;
}

struct Match *createTournament(int h)
{
  if(h == 0)
    return (struct Match*)NULL;

  struct Match* m1 =  createTournament(h - 1);
  struct Match* m2 =  createTournament(h - 1);
  struct Match* m = getMatch();

  if ( assignPlayers(m, m1->winner, m2->winner, m1, m2) == 0)
    printf("Error: assignPlayers failed\n");
  if ( assignWinner(m, m->player1) == 0)
    printf("Error: assignWinner failed\n");
  return m;
}

int main()
{
  struct Match* m1 = getMatch();
  struct Match* m2 = getMatch();
  struct Match* m3 = getMatch();
  
  while(1)
    if(makeMatch(m3) == 1)
      break;
  printf("Got input for m3\n");
  while(1)
    if(makeMatch(m2) == 1)
      break;
  printf("Got input for m2\n");
  assignPlayers(m1, m2->winner, m3->winner,m2, m3);
  /* assignWinner(m1, m1->player1); */
  while(1)
  {
    printf("Enter m1 winner: ");
    int x;
    scanf("%d", &x);
    if(assignWinner(m1, x) == 1)
      break;
  }
  printTournament(m1);
  return 0;
}
