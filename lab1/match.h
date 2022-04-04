#ifndef MATCH_H
#define MATCH_H

struct Match {
  int player1;
  int player2;
  int winner;
  struct Match *prevMatch1;
  struct Match *prevMatch2;

};

int assignPlayer1(struct Match*, struct Match*, int);
int assignPlayer2(struct Match*, struct Match*, int);
int assignWinner(struct Match*, int);

struct Match* getMatch();

void printTournament(struct Match*);

#endif

