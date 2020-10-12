#ifndef CARD_H
#define CARD_H
#include <iostream>

using namespace std;

class Card {
  public:
    Card();
    Card(string symbol, int number);
    void show();
    friend class Player;

  private:
    string _symbol;
    int _number;
    bool is_ace;
};

#endif