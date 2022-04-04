#ifndef MATCH_H
#define MATCH_H

struct Match {
  int player1;
  int player2;
  int winner;

  struct Match* prevMatch1;
  struct Match* prevMatch2;
};

struct Match* getMatch();

int assignPlayers(struct Match*, int, int, struct Match*, struct Match*);
int assignWinner(struct Match*, int);

void printTournament(struct Match* match);

#endif

