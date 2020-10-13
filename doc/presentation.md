---
title: CBON333 Final Project
author: 羅鈺涵
theme: Copenhagen
colortheme: seahorse
CJKmainfont: Noto Serif CJK SC
---

## Goal

Utilize all the learned concepts.

## Blackjack

- If the player is dealt an Ace and a ten-value card (called a **blackjack** or **natural**), and the dealer does not, the player wins.
- If the player exceeds a sum of 21 (**busts**), the player loses, even if the dealer also exceeds 21.
- If the dealer exceeds a sum of 21 (**busts**) and the player does not, the player wins.
- If the player attains a final sum higher than the dealer and does not bust, the player wins.
- If both dealer and player receive a blackjack or any other hands with the same sum called a **push**, no one wins.

![blackjack](BlackJack6.jpg){width=30%}\


## Demo


+ [Game play](demo_1.mp4)\

+ [Load player from file](demo_2.mp4)\

+ [Overwrite the current player](demo_3.mp4)\

**John.txt**
```
John
95
0
1
0

```


## Design

::: {.columns}

:::: {.column width=0.5}

Directory structure

```
.
|-- card.cpp
|-- card.h
|-- deck.cpp
|-- deck.h
|-- game.cpp
|-- game.h
|-- main.cpp
|-- player.cpp
|-- player.h
```
::::

:::: {.column width=0.6}

Objects

```cpp
class Game
class Player
class Dealer : public Player
class Deck
class Card
```
::::

:::

## class Game (game.h)

```cpp
#include "deck.h"
#include "player.h"

class Game {
  public:
    void adjust(int n);  // not implemented for now
    void play(Player &plyr);
    void show_table(Player &plyr);

  private:
    Deck decks;
    Dealer dealer;
};
```

## class Player (Player.h)

::: {.columns}

:::: {.column width=0.5}

```cpp
#include "card.h"
#include <iostream>
#include <vector>
using namespace std;

class Player {
  public:
    Player();
    Player(string name);
    void show_cards();
    void hit(Card card);
    void stand();
    void save();
    void load(string fname);
    void show_info();
    int get_points();
    friend class Game;
```
::::

:::: {.column width=0.5}
```cpp
  protected:
    string _name;
    bool bet(int amount);
    void double_down();
    void split();
    void surrender();
    void win();
    void lose();

  private:
    int money;
    int bets;
    int wins;
    int loses;
    double win_rate;
    vector<Card> cards;
};
```
::::
:::

## class Dealer (Player.h)

```cpp
class Dealer : public Player {
  public:
    Dealer();
    Dealer(string name);
};
```

## class Deck (deck.h)

```cpp
#include "card.h"
#include <iostream>
#include <vector>

class Deck {
  public:
    Deck();
    Deck(int n);
    void prepare();
    void shuffle();
    Card deal();

  private:
    int n_decks;
    int card_numbers;
    vector<Card> cards;
};
```

## class Card (card.h)

```cpp
#include <iostream>

using namespace std;

class Card {
  public:
    Card();
    Card(string symbol, int number);
    void show();
    friend class Player;
    friend class Game;

  private:
    string _symbol;
    int _number;
    bool is_ace;
};
```