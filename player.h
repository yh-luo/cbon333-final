#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include <iostream>
#include <vector>

using namespace std;

class Player {
  public:
    Player();
    Player(string name);
    void show_cards();
    void hit(Card card);
    void stand();
    void save();
    void load(string fname);
    int get_points();
    friend class Game;

  protected:
    string _name;
    bool bet(int amount);
    void double_down();
    void split();
    void surrender();
    void win();
    void lose();
    void show_info();

  private:
    int money;
    int bets;
    int wins;
    int loses;
    double win_rate;
    vector<Card> cards;
};

class Dealer : public Player {
  public:
    Dealer();
    Dealer(string name);
};

#endif