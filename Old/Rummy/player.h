/*
File: player.h
-----------------
Player class.
Manages and limits player's actions.

Author: Julian Triveri
10/08/18
*/

#ifndef player_h
#define player_h

#include <vector>
#include "card.h"
//#include "playerAI.h"
#include "rummy.h"
using namespace std;

/* Class: Player
 * ---------------------------------------------------------------------------
 * Represents a human or computer player. Handles player actions */
class Player{
private:
	bool isBot_;
	Card cardNecessaryToPlay_;
	bool mustPlayParticularCard_ = false;

	string botActionHistory_;
	vector<Card> hand_;

public:
	Player(bool b);

	void makeTurn();
	void takeCard(Card card);

private:

	void displayTable();
	void displayHand();

	void drawCards();
	void playCards();
	void aiPlayCard(int cardIndex);

	void drawFromDeck();
	void drawFromDiscardPile(int n);

	void buildMeld();
	void addToMeld();

	bool checkIfCardIsPlayable(Card card, int cardsToConsiderFromDiscardPile);
	void aiPlayCard(Card card);
	void removeCard(Card card);
	void removeCard(int n);

	void clearDisplay();
};

#endif
