#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"
class Game {
  public:
    Game();
    Game(int level);
    void play();

  private:
    int bet;
    int _difficulty;

    Deck decks;
};

#endif