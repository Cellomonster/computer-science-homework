/*
File: rummy.h
-----------------
Manages the game.

Author: Julian Triveri
10/08/18
*/

#ifndef rummy_h
#define rummy_h

#include <stack>
#include <vector>
#include "meld.h"

extern stack<Card> deck;
extern vector<Card> discardPile;
extern vector<Meld> melds;

void initializeGame();
void initializeDeck();
void dealDeck();

#endif
