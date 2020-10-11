#include "player.h"
#include "card.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Player::Player() {
    _name = "Unnamed";
    money = 100;
    wins = 0;
    loses = 0;
    win_rate = 0;
}
Player::Player(string name) {
    _name = name;
    money = 100;
    wins = 0;
    loses = 0;
    win_rate = 0;
}

void Player::show_cards() {
    for (auto &this_card : cards) {
        this_card.show();
        cout << " ";
    }
    cout << endl;
}
void Player::hit(Card card) {
    cards.push_back(card);
}

// TODO
void Player::save() {
    ofstream f;
    f.open(_name + ".txt");
    f << "name:" << _name << endl;
    f << "money:" << money << endl;
    f << "wins:" << wins << endl;
    f << "loses:" << loses << endl;
    f << "win_rate:" << win_rate << endl;
    f.close();
    cout << "Progress saved" << endl;
}
// TODO
void Player::load(string fname) {
}
// TODO
void Player::bet(int amount) {
    bets += amount;
}
// TODO
void Player::double_down() {
}
// TODO
void Player::split() {
}
void Player::surrender() {
    money -= bets / 2;
    bets = 0;
    loses += 1;
    win_rate = (double)wins / (wins + loses);
}
void Player::win() {
    money += bets;
    bets = 0;
    wins += 1;
    win_rate = (double)wins / (wins + loses);
    cout << "You win!" << endl;
}
void Player::lose() {
    money -= bets;
    bets = 0;
    loses += 1;
    win_rate = (double)wins / (wins + loses);
    cout << "You lose!" << endl;
}

Dealer::Dealer() {
    _name = "Winner Dealer";
}
Dealer::Dealer(string name) {
    _name = name;
}