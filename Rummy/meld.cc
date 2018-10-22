/*
File: meld.cc
-----------------
Meld class.

Author: Julian Triveri
10/08/18
*/

#include <algorithm>
#include <iostream>

#include <vector>

#include "card.h"
#include "rummy.h"
using namespace std;

Meld::Meld(int t){
	type = t;
}

/* Function: addCard
 * Usage: addCard(<card>)
 * Returns: true if the card is added, false if not
 * ---------------------------------------------------------------------------
 * Checks if a card fits within the meld, and adds it if so */
bool Meld::addCard(Card card){
	int result = checkIfCompatible(card);

	if(result)
		(result > 0)? addCard_(card) : void(cards.insert(cards.begin(), card));

		cout << result << endl;

	return result;
}

/* Function: checkIfCompatible
 * Usage: checkIfCompatible(<card>)
 * Returns: if false: 0. if true: -1 or 1 depending on if the card comes at the
 * beginning or end of a potential consecutive series
 * ---------------------------------------------------------------------------
 * Checks if a card fits within the meld */
int Meld::checkIfCompatible(Card card){
	switch(type){
		//Undetermined relationship type
		case 0:
			//If there are no cards in the meld, anything can be added
			if(!cards.size())
				return 1;

			//Make sure second card is either the same value, or a consecutive value
			//of the same suit. The second card determines the card relationship type
			//of which the meld will against all future cards
			else if(card.value == cards.back().value){
				type = 1;
				return true;

			}else if(checkCardBySuitSeries_(card)){
				type = 2;
				return 1;
			}

			else return 0;

		//Value based relationship
		case 1:
			return card.value == cards.back().value;

		//Consecutive suit series relationship
		case 2:
			return checkCardBySuitSeries_(card);
	}
}

/* Function: checkCardBySuitSeries_
 * Usage: checkCardBySuitSeries_(<card>)
 * Returns: if false: 0. if true: -1 or 1 depending on if it comes at the
 * beginning or end of the consecutive series
 * ---------------------------------------------------------------------------
 * Checks if a card fits within a series of cards consecutive by value and
 * of the same suit */
int Meld::checkCardBySuitSeries_(Card card){
	if(card.suit == cards.front().suit)
		if(card.value == cards.front().value - 1)
			return -1;
		else if(card.value == cards.back().value + 1)
			return 1;
	return 0;
}

/* Function: addCard_
 * Usage: addCard_(<card>)
 * ---------------------------------------------------------------------------
 * Add a card to the meld */
void Meld::addCard_(Card card){
	cards.push_back(card);
}
