#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "player.h"
class Game {
  public:
    void play(Player &plyr);
    void play(Player &plyr, Deck &dk);
    void adjust(int n);
    int check(Player &plyr); // 0=nothing 1=blackjack -1=bust
  private:
    int rst; // 0=not finished 1=player win -1=player lose
    Deck decks;
    Dealer dealer;
};

#endif