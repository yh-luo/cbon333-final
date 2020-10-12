#include "game.h"
#include "deck.h"
#include "player.h"
#include <algorithm> // std::min
#include <ctime>
#include <iostream>

using namespace std;

void Game::adjust(int n) {
    decks = Deck(n);
}
void Game::play(Player &plyr) {
    int plyr_total = 0;
    int dlyr_total = 0;
    int amt;
    int act;
    bool plyr_done = false;
    bool dlyr_done = false;
    bool need_check = false;
    decks = Deck();
    decks.prepare();
    decks.shuffle();

    // bet
    plyr.show_info();
    if (plyr.money <= 0) {
        cout << "You don't have any money to play now." << endl;
        cout << "Maybe go get some money (wink)?" << endl;
        return;
    }
    while (true) {
        cout << "Place your bet: ";
        // make sure got integer
        check_input(amt);
        if (plyr.bet(amt))
            break;
    }

    // first hand
    plyr.hit(decks.deal());
    dealer.hit(decks.deal());
    plyr.hit(decks.deal());

    // player's action
    while (!plyr_done) {
        show_table(plyr);
        plyr_total = plyr.get_points();
        sleep(0.5);
        if (plyr_total == -1) {
            cout << "You got Blackjack!" << endl;
            // check if the dealer has blackjack too
            if (!(dealer.cards.front().is_ace || dealer.cards.front()._number >= 10)) {
                plyr.win();
                dlyr_done = true;
            } else {
                need_check = true;
            }
            plyr_done = true;
        } else if (plyr_total > 21) {
            cout << "Busted!" << endl;
            plyr.lose();
            dlyr_done = true;
            plyr_done = true;
        } else if (plyr_total == 21) {
            need_check = true;
            plyr_done = true;
        } else {
            cout << "1=Hit, 2=Stand, 3=Double down";
            if (plyr.cards.size() == 2) {
                cout << ", 4=Surrender: ";
            } else {
                cout << ": ";
            }
            // make sure got integer
            check_input(act);
            switch (act) {
            // hit
            case 1:
                plyr.hit(decks.deal());
                break;
            // stand
            case 2:
                need_check = true;
                plyr_done = true;
                break;
            // double down
            case 3:
                plyr.double_down();
                plyr.hit(decks.deal());
                break;
            // surrender (only first hand)
            case 4:
                if (plyr.cards.size() == 2) {
                    plyr.surrender();
                    dlyr_done = true;
                    plyr_done = true;
                } else {
                    cout << "You can only surrender in the first hand." << endl;
                    break;
                }
                break;
            default:
                cout << "Invalid action." << endl;
                break;
            }
        }
    }

    // dealer's action
    while (!dlyr_done) {
        show_table(plyr);
        dlyr_total = dealer.get_points();
        sleep(0.5);
        if (dlyr_total == -1 && plyr_total == -1) {
            cout << "No one wins." << endl;
            need_check = false;
            dlyr_done = true;
        } else if (dlyr_total == -1 && plyr_total != -1) {
            plyr.lose();
            need_check = false;
            dlyr_done = true;
        } else if (dlyr_total != -1 && plyr_total == -1) {
            plyr.win();
            need_check = false;
            dlyr_done = true;
        } else if (dlyr_total > 21) {
            plyr.win();
            need_check = false;
            dlyr_done = true;
        } else if (dlyr_total >= 17) {
            need_check = true;
            dlyr_done = true;
        } else {
            dealer.hit(decks.deal());
        }
    }

    if (need_check) {
        // final check
        if (plyr_total == dlyr_total) {
            cout << "No one wins." << endl;
        } else if (plyr_total > dlyr_total) {
            plyr.win();
        } else if (plyr_total < dlyr_total) {
            plyr.lose();
        }
    }

    // clean-up
    plyr.cards.clear();
    dealer.cards.clear();
}
void Game::show_table(Player &plyr) {
    cout << endl;
    cout << "Current bets: " << plyr.bets << endl;
    cout << "Dealer's cards: ";
    dealer.show_cards();
    cout << "Your cards: ";
    plyr.show_cards();
}
// helper functions
void sleep(float seconds) {
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while (clock() < startClock + secondsAhead) {
    };
}
void check_input(int &var) {
    // make sure got integer
    cin >> var;
    while (cin.fail()) {
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> var;
    }
}