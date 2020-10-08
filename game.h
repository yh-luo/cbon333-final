#ifndef GAME_H
#define GAME_H
#include "deck.h"

class Game {
  public:
    Game();
    Game(int level, int n_player);
    ~Game();
    void play();

  private:
    int *bets;
    int _difficulty;
    int _n_player;
    Deck decks;
};

#endif