#include "game.h"
#include "player.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int tmp_input;
    bool playing = true;
    string player_name;
    string fname;
    Player player;
    Game game;
    // greetings
    cout << "What's your name?" << endl;
    while (true) {
        cin >> player_name;
        break;
    }

    // check whether there is already a file
    fname = player_name + ".txt";
    ifstream f(fname);
    if (f.good()) {
        cout << player_name << "'s file is already created." << endl
             << "Do you want to load the progress?(1/0)" << endl;
        check_input(tmp_input);
        switch (tmp_input) {
        case 1:
            player.load(fname);
            // sanity check
            cout << "Player loaded:" << endl;
            player.show_info();
            break;
        case 0:
            cout << "Did not load the file. The file will be overwritten." << endl;
            player = Player(player_name);
            break;
        default:
            cout << "Invalid value. The file will be overwritten." << endl;
            player = Player(player_name);
            break;
        }
    } else {
        cout << "Hello, not world, but " << player_name << "!" << endl
             << endl;
        player = Player(player_name);
    }

    // play
    while (playing) {
        cout << "Start a new game?(1/0)" << endl;
        check_input(tmp_input);
        switch (tmp_input) {
        case 1:
            game.play(player);
            break;
        case 0:
            playing = false;
            break;
        default:
            cout << "Invalid value. Quit the game now." << endl;
            playing = false;
            break;
        }
    }
    player.save();

    return 0;
}