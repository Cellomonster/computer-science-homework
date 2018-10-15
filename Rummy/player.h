#ifndef player_h
#define player_h

#include <vector>
#include "card.h"
#include "rummy.h"
using namespace std;

class Player{
private:
	int isBot_;
	vector<Card> hand_;
	Card cardNecessaryToPlay_;
	bool mustPlayParticularCard_ = false;

public:
	Player(bool b);

	void makeTurn();
	void takeCard(Card card);

private:
	void displayTable();
	void displayHand();

	void drawCards();
	void playCards();

	void buildMeld();
	void addToMeld();

	bool checkIfCardIsPlayable(Card card);
	void discardCard(int n);
};

#endif
