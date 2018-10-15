#ifndef meld_h
#define meld_h

#include <algorithm>
#include <vector>
#include "card.h"
#include "rummy.h"
using namespace std;

class Meld{
public:
	vector<Card> cards;
	int type;

public:

	bool addCard(Card card);
	int checkIfCompatible(Card card);

private:
	bool checkCardByValue_(Card card);
	int checkCardBySuitSeries_(Card card);
	void addCard_(Card card);
	void insertCard_(Card card);
};

#endif
