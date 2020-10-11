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
    if (symbol == "spade" && number == 1) {
        is_ace = 1;
    } else {
        is_ace = 0;
    }
}
void Card::show() {
    cout << _symbol << _number;
}