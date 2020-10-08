#include "player.h"
#include <iostream>

using namespace std;

Player::Player() {
    _name = "John";
    _money = 1000;
    wins = 0;
    loses = 0;
    win_rate = 0;
}
Player::Player(string name, int money) {
    _name = name;
    _money = money;
    wins = 0;
    loses = 0;
    win_rate = 0;
}

// TODO
void Player::hit() {
}
void Player::stand() {
}
void Player::bet(int amount) {
}
void Player::double_down() {
}
void Player::split() {
}
void Player::surrender() {
}
void Player::win() {
    wins += 1;
    win_rate = (double)wins / (wins + loses);
}
void Player::lose() {
    loses += 1;
    win_rate = (double)wins / (wins + loses);
}

Dealer::Dealer(){
    _name = "Winner Dealer";
}
Dealer::Dealer(string name){
    _name = name;
}