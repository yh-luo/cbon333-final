#include "game.h"
#include "player.h"
#include <iostream>

using namespace std;
int main() {
    char ch;
    string player_name = "John";
    Player player;
    Game game;
    // greetings
    cout << "Do you want to introduce yourself? (y/n)" << endl;
    cin >> ch;
    switch (ch) {
    case 'y':
        cout << "What's your name (1-80 characters)?" << endl;
        cin >> player_name;
        cout << "Hello, not world, but " << player_name << "!" << endl;
        break;
    default:
        cout << "Ok, let's call you " << player_name << "." << endl;
    }
    player = Player(player_name);
    // play
    game.play(player);
    return 0;
}