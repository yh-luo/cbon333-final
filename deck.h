#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <vector>

class Deck {
  public:
    Deck();
    Deck(int n);
    void prepare();
    void shuffle();
    Card deal();

  private:
    int n_decks;
    int card_numbers;
    vector<Card> cards;
};

#endif