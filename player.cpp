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
vector<Card> Player::get_cards() {
    return cards;
}
void Player::show_cards() {
    for (auto &this_card : get_cards()) {
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
void Player::bet(int amount) {
    bets += amount;
}
// TODO
void Player::double_down() {
    // check money
    if (money < bets) {
        cout << "You don't have enough money." << endl;
    } else {
        money -= bets;
        bets *= 2;
    }
}
// TODO
void Player::split() {
}
void Player::surrender() {
    money -= bets / 2;
    bets = 0;
    loses += 1;
    win_rate = (double)wins / (wins + loses);
    cout << "You lose half the bets due to surrender!" << endl;
}
void Player::win() {
    cout << "You win " << bets << "!" << endl;
    money += bets;
    bets = 0;
    wins += 1;
    win_rate = (double)wins / (wins + loses);
}
void Player::lose() {
    cout << "Busted! You lose " << bets << "!" << endl;
    money -= bets;
    bets = 0;
    loses += 1;
    win_rate = (double)wins / (wins + loses);
}

Dealer::Dealer() {
    _name = "Winner Dealer";
}
Dealer::Dealer(string name) {
    _name = name;
}
void Dealer::show_cards() {
    vector<Card> current_cards = get_cards();
    // first hand
    if (current_cards.size() == 2) {
        current_cards.front().show();
    } else {
        for (auto &this_card : get_cards()) {
            this_card.show();
            cout << " ";
        }
    }
    cout << endl;
}