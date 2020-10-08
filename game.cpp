#include "game.h"
#include "deck.h"
#include <iostream>

using namespace std;

Game::Game() {
    _difficulty = 1;
    _n_player = 1;
    bets = new int[_n_player];
}
Game::Game(int difficulty, int n_player) {
    if (difficulty < 1) {
        cout << "Invalid difficulty level, set to 1." << endl;
        _difficulty = 1;
    } else {
        _difficulty = difficulty;
    }
    if (n_player < 1 || n_player > 3) {
        cout << "Invalid number of players, set to 1." << endl;
        _n_player = 1;
    } else {
        _n_player = n_player;
    }

    bets = new int[_n_player];
}
Game::~Game() {
    delete[] bets;
}
// TODO: get real
void Game::play() {
    decks = Deck(_difficulty);
    decks.prepare();
}