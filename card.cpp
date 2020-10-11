#include "card.h"
#include <iostream>

using namespace std;

Card::Card() {
    _symbol = "joker";
    _number = 0;
    is_ace = 0;
}
Card::Card(string symbol, int number) {
    _symbol = symbol;
    _number = number;
    if (symbol == "♠" && number == 1) {
        is_ace = 1;
    } else {
        is_ace = 0;
    }
}
void Card::show() {
    if (_number == 11) {
        cout << _symbol << "J";
    } else if(_number == 12) {
        cout << _symbol << "Q";
    } else if (_number == 13) {
        cout << _symbol << "K";
    } else {
        cout << _symbol << _number;
    }
    
}