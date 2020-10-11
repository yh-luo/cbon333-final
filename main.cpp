#include "game.h"
#include "player.h"
#include <iostream>

using namespace std;

int main() {
    int playing = 1;
    string player_name = "John";
    Player player;
    Game game;
    // greetings
    cout << "What's your name?" << endl;
    cin >> player_name;
    cout << "Hello, not world, but " << player_name << "!" << endl
         << endl;
    player = Player(player_name);
    // play
    while (playing) {
        cout << "Start a new game?(1/0)" << endl;
        cin >> playing;
        switch (playing) {
        case 1:
            game.play(player);
            break;
        case 0:
            break;
        }
    }
    player.save();

    return 0;
}