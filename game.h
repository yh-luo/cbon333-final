#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"
class Game {
  public:
    void play(Player &plyr);
    void play(Player &plyr, Deck &dk);
    void adjust(int n);

  private:
    int act(Player &plyr);
    Deck decks;
    Dealer dealer;
};

#endif