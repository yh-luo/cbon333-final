#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

class Player {
  public:
    Player();
    Player(string name, int money);
    ~Player();
    void hit();
    void stand();

  protected:
    string name;
    void bet(int amount);
    void double_down();
    void split();
    void surrender();

  private:
    int money;
    int wins;
    int loses;
    double win_rate;
};

class Dealer : public Player {
  public:
    Dealer();
    Dealer(string name);
    ~Dealer();
};

#endif