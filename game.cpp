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
    int plyr_total;
    int dlyr_total;
    int amt;
    int act;
    int done = 0;

    decks = Deck();
    decks.prepare();
    decks.shuffle();

    // bet
    plyr.show_info();
    while (1) {
        cout << "Place your bet: ";
        cin >> amt;
        if (plyr.bet(amt))
            break;
    }

    // first hand
    plyr.hit(decks.deal());
    dealer.hit(decks.deal());
    plyr.hit(decks.deal());

    // player's action
    while (done != 1) {
        show_table(plyr);
        plyr_total = plyr.get_points();
        if (plyr_total == -1) {
            done = 1;
        } else if (plyr_total > 21) {
            cout << "Busted! ";
            plyr.lose();
            // clean-up
            plyr.cards.clear();
            dealer.cards.clear();
            return;
        } else if (plyr_total == 21) {
            done = 1;
        } else {
            cout << "1=Hit, 2=Stand, 3=Double down";
            if (plyr.cards.size() == 2) {
                cout << ", 4=Surrender: ";
            } else {
                cout << ": ";
            }
            cin >> act;
            switch (act) {
            // hit
            case 1:
                plyr.hit(decks.deal());
                break;
            // stand
            case 2:
                done = 1;
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
                    // clean-up
                    plyr.cards.clear();
                    dealer.cards.clear();
                    return;
                } else {
                    cout << "Invalid actions!" << endl;
                    break;
                }
                break;
            default:
                cout << "Invalid actions!" << endl;
                break;
            }
        }
    }
    // dealer's action
    done = 0;
    while (done != 1) {
        show_table(plyr);
        sleep(1);
        dlyr_total = dealer.get_points();
        if (dlyr_total == -1 && plyr_total != -1) {
            plyr.lose();
            // clean-up
            plyr.cards.clear();
            dealer.cards.clear();
            return;
        } else if (dlyr_total > 21) {
            plyr.win();
            // clean-up
            plyr.cards.clear();
            dealer.cards.clear();
            return;
        } else if (dlyr_total >= 17) {
            done = 1;
        } else {
            dealer.hit(decks.deal());
        }
    }
    // final check
    sleep(1);
    if (plyr_total == dlyr_total) {
        cout << "No one wins." << endl;
    } else if (plyr_total > dlyr_total) {
        plyr.win();
    } else if (plyr_total < dlyr_total) {
        plyr.lose();
    }

    // clean-up
    plyr.cards.clear();
    dealer.cards.clear();
}
void Game::show_table(Player &plyr) {
    cout << endl;
    cout << "Dealer's cards: ";
    dealer.show_cards();
    cout << "Your cards: ";
    plyr.show_cards();
}
void sleep(float seconds) {
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while (clock() < startClock + secondsAhead) {
    };
}