/*
File: card.h
-----------------
Card struct.
(Card is a struct rather than a class because lack of any need for private variables)

Author: Julian Triveri
10/08/18
*/

#ifndef card_h
#define card_h

#include <string>
using namespace std;

struct Card{
	int suit;
	int value;
	string toString(){

		string suitIcons[4] = {"♠","♥","♦","♣"};

		string values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "X", "J", "Q", "K"};

		return "[" + suitIcons[suit] + " " + values[value] + "]";
	};
};

#endif
