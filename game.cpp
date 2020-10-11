#include "game.h"
#include "deck.h"
#include "player.h"
#include <iostream>

using namespace std;

void Game::play(Player &plyr) {
    int amt;
    int act;
    int done = 0;
    decks = Deck();
    decks.prepare();
    decks.shuffle();

    // bet
    cout << "Game started!" << endl;
    cout << "Place your bet:" << endl;
    cin >> amt;
    plyr.bet(amt);
    // first hand
    plyr.hit(decks.deal());
    dealer.hit(decks.deal());
    plyr.hit(decks.deal());

    // TODO
    while (done != 1) {
        cout << "Dealer's cards: ";
        dealer.show_cards();
        cout << "Your cards: ";
        plyr.show_cards();
        // check first hand
        rst = check(plyr);
        switch (rst) {
        case 1:
            plyr.win();
            return;
        case -1:
            plyr.lose();
            return;
        case 0:
            break;
        }
        // action
        cout << "Actions: 1=Hit, 2=Stand, 3=Double down, 4=Surrender: ";
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
            plyr.bet(plyr.bets);
            plyr.hit(decks.deal());
            break;
        // surrender
        // FIXME: only first hand
        case 4:
            plyr.surrender();
            done = 1;
            break;
        default:
            cout << "Invalid actions!" << endl;
            break;
        }
    }
}
// TODO: reuse decks
void Game::play(Player &plyr, Deck &dk) {
    decks = dk;
    decks.prepare();
    decks.shuffle();
}
// TODO
void Game::adjust(int n) {
    decks = Deck(n);
}
int Game::check(Player &plyr) {
    int total = 0;
    int tmp_total = 0;
    int aces = 0;
    int faces = 0;
    int i;
    // check for blackjack
    if (plyr.cards.size() == 2) {
        for (auto &this_card : plyr.cards) {
            if (this_card.is_ace == 1) {
                aces++;
            } else if (this_card._number == 10) {
                faces++;
            }
        }
        if (aces == 1 && faces == 1)
            return 1;
    }
    for (auto &this_card : plyr.cards) {
        if (this_card.is_ace == 1) {
            aces++;
        }
        total += this_card._number;
    }
    // check for aces
    if (aces == 0 && total > 21)
        return -1;

    for (i = 0; i < aces; i++) {
        if (total > 11)
            break;
        total += 10;
    }

    return 0;
}