#include "card.h"
#include <iostream>

using namespace std;

Card::Card() {
    _symbol = "*";
    _number = 0;
    is_ace = false;
}
Card::Card(string symbol, int number) {
    _symbol = symbol;
    _number = number;
    if (number == 1) {
        is_ace = true;
    } else {
        is_ace = false;
    }
}
void Card::show() {
    if (_number == 1) {
        cout << _symbol << "A";
    } else if (_number == 11) {
        cout << _symbol << "J";
    } else if (_number == 12) {
        cout << _symbol << "Q";
    } else if (_number == 13) {
        cout << _symbol << "K";
    } else {
        cout << _symbol << _number;
    }
}