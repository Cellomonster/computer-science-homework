#include <algorithm>

#include <vector>

#include "card.h"
#include "rummy.h"
using namespace std;


bool Meld::addCard(Card card){
	int result = checkIfCompatible(card);

	if(result)
		(result > 0)? addCard_(card) : insertCard_(card);

	return result;

}

int Meld::checkIfCompatible(Card card){
	switch(type){

		case 0:
			if(!cards.size()){
				return 1;
			}else if(checkCardByValue_(card)){
				type = 1;
				return checkCardByValue_(card);
			}else if(checkCardBySuitSeries_(card)){
				type = 2;
				return 1;
			}else return -1;

		case 1:
			return checkCardByValue_(card);

		case 2:
			return checkCardBySuitSeries_(card);
	}
}


bool Meld::checkCardByValue_(Card card){
	if(card.value == cards[0].value){
		return true;
	}
	return false;
}


int Meld::checkCardBySuitSeries_(Card card){
	if(card.suit == cards[0].suit){
		if(card.value == cards.front().value - 1)
			return -1;
		else if(card.value == cards.back().value + 1)
			return 1;
	}
	return 0;
}


void Meld::addCard_(Card card){
	cards.push_back(card);
}

void Meld::insertCard_(Card card){
	cards.insert(cards.begin(), card);
}
