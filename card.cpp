#include "card.h"
#include <iostream>

using namespace std;

Card::Card() {
    _symbol = "joker";
    _number = 0;
}
Card::Card(string symbol, int number) {
    _symbol = symbol;
    _number = number;
}
void Card::show() {
    cout << _symbol << _number;
}