#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"

class Game {
  public:
    void adjust(int n);
    void play(Player &plyr);
    void play(Player &plyr, Deck &dk);
    void show_table(Player &plyr);
  private:
    Deck decks;
    Dealer dealer;
};

#endif