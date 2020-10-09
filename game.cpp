#include "game.h"
#include "deck.h"
#include "player.h"
#include <iostream>

using namespace std;


void Game::play(Player &plyr) {
    int done = 0;
    int amt;
    int act;
    decks = Deck();
    decks.prepare();
    decks.shuffle();

    // bet
    cout << "Game started!" << endl;
    cout << "Place your bet:" << endl;
    cin >> amt;
    plyr.bet(amt);
    // initial hand
    plyr.hit(decks.deal());
    dealer.hit(decks.deal());
    plyr.hit(decks.deal());

    // TODO
    while (done != 1) {
        cout << "Dealer's cards: ";
        dealer.show_cards();
        cout << "Your cards: ";
        plyr.show_cards();
        cout << "Actions: 1=Hit, 2=Stand, 3=Double down, 4=Surrender: ";
        cin >> act;
        switch(act) {
            case 1:
                plyr.hit(decks.deal());
                break;
            case 2:
                done = 1;
                break;
            case 3:
                plyr.bet(plyr.bets);
                plyr.hit(decks.deal());
                break;
            case 4:
                plyr.surrender();
                done = 1;
                break;
            default:
                cout << "Invalid actions!" << endl;
                break;
        }
    }


    plyr.save();
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