#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"

class Game {
  public:
    void adjust(int n);
    void play(Player &plyr);
    void show_table(Player &plyr);

  private:
    Deck decks;
    Dealer dealer;
};
// helper function
void sleep(float seconds);
void check_input(int &var);
#endif