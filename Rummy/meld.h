/*
File: meld.h
-----------------
Meld class.

Author: Julian Triveri
10/08/18
*/

#ifndef meld_h
#define meld_h

#include <algorithm>
#include <vector>
#include "card.h"
#include "rummy.h"
using namespace std;

/* Class: Meld
 * ---------------------------------------------------------------------------
 * Represents a meld of cards. Handles checking and adding of cards*/
class Meld{
public:
	vector<Card> cards;
	int type;

public:

	bool addCard(Card card);
	int checkIfCompatible(Card card);

private:
	int checkCardBySuitSeries_(Card card);
	void addCard_(Card card);
};

#endif
