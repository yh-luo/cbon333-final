#include "game.h"
#include "deck.h"
#include "player.h"
#include <iostream>

using namespace std;

Game::Game() {
    _difficulty = 1;
}
Game::Game(int difficulty) {
    if (difficulty < 1) {
        cout << "Invalid difficulty level, set to 1." << endl;
        _difficulty = 1;
    } else {
        _difficulty = difficulty;
    }
}

// TODO: get real
void Game::play() {
    bet = 0;
    decks = Deck(_difficulty);
    decks.prepare();
    decks.shuffle();

}