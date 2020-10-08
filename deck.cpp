#include "deck.h"
#include "card.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

Deck::Deck() {
    n_decks = 1;
}
Deck::Deck(int n) {
    if (n < 1) {
        cout << "Invalid number of decks, set to 1." << endl;
        n_decks = 1;
    } else {
        n_decks = n;
    }
}

void Deck::prepare() {
    vector<string> symbols{"clubs", "diamonds", "hearts", "spades"};
    int i, j;
    card_numbers = n_decks * 52;
    // allocate memory for cards
    cards.reserve(card_numbers);

    // make cards
    for (i = 0; i < n_decks; i++) {
        for (auto &this_symbol : symbols) {
            for (j = 1; j < 14; j++) {
                cards.push_back(Card(this_symbol, j));
            }
        }
    }
    // DEBUG
    // for (auto &this_card : cards) {
    //     this_card.show();
    // }
}
// TODO
void Deck::shuffle() {
    auto rng = default_random_engine{};
    // explicit to avoid confusion
    std::shuffle(begin(cards), end(cards), rng);
    // DEBUG
    // for (auto &this_card : cards) {
    //     this_card.show();
    // }
}
// TODO
// Card Deck::deal() {
// }