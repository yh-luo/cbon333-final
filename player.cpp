#include "player.h"
#include "card.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Player::Player() {
    _name = "Unnamed";
    money = 100;
    bets = 0;
    wins = 0;
    loses = 0;
    win_rate = 0;
}
Player::Player(string name) {
    _name = name;
    money = 100;
    bets = 0;
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
void Player::save() {
    ofstream f;
    f.open(_name + ".txt");
    f << _name << endl;
    f << money << endl;
    f << wins << endl;
    f << loses << endl;
    f << win_rate << endl;
    f.close();
    cout << "Progress saved." << endl;
}
// TODO
void Player::load(string fname) {
    ifstream f(fname);
    string line;
    if (f.is_open()) {
        f >> _name >> money >> wins >> loses >> win_rate;
    }
    f.close();
}
int Player::get_points() {
    int total = 0;
    int tmp_total = 0;
    int aces = 0;
    int faces = 0;
    int i;
    // check for blackjack
    if (cards.size() == 2) {
        for (auto &this_card : cards) {
            if (this_card.is_ace) {
                aces++;
            } else if (this_card._number >= 10) {
                faces++;
            }
        }
        if (aces == 1 && faces == 1) {
            return -1;
        }
    }
    for (auto &this_card : cards) {
        if (this_card.is_ace) {
            aces++;
        }
        total += min(this_card._number, 10);
    }
    // check for aces
    if (aces == 0 && total > 21)
        return total;

    for (i = 0; i < aces; i++) {
        if (total > 11)
            break;
        total += 10;
    }

    return total;
}
bool Player::bet(int amount) {
    if (amount <= 0) {
        cout << "Invalid value" << endl;
        return false;
    }
    // check money
    if (amount > money) {
        cout << "You don't have enough money." << endl;
        return false;
    }
    bets += amount;
    return true;
}
void Player::double_down() {
    // check money
    if (money < bets * 2) {
        cout << "You don't have enough money. Only hit." << endl;
        return;
    }
    bets *= 2;
}
// TODO
void Player::split() {
}
void Player::surrender() {
    bets /= 2;
    cout << "You lose " << bets << " due to surrender!" << endl;
    money -= bets;
    bets = 0;
    loses += 1;
    win_rate = (double)wins / (wins + loses);
}
void Player::win() {
    cout << "You win " << bets << "!" << endl;
    money += bets;
    bets = 0;
    wins += 1;
    win_rate = (double)wins / (wins + loses);
}
void Player::lose() {
    cout << "You lose " << bets << "!" << endl;
    money -= bets;
    bets = 0;
    loses += 1;
    win_rate = (double)wins / (wins + loses);
}
void Player::show_info() {
    cout << "--------------------" << endl;
    cout << "Name: " << _name << endl;
    cout << "Money: " << money << endl;
    cout << "Wins: " << wins << endl;
    cout << "Loses: " << loses << endl;
    cout << "Win rate: " << win_rate << endl;
    cout << "--------------------" << endl;
}
Dealer::Dealer() {
    _name = "Winner Dealer";
}
Dealer::Dealer(string name) {
    _name = name;
}