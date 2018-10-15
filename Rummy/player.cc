#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include "card.h"
#include "rummy.h"
#include "player.h"
using namespace std;

string notification;

void displayCardPile(vector<Card> pile);
void displayCardPile(vector<Card> pile, bool indent);
void displayMelds();
void clearDisplay();
void displayNotification();

bool checkIfNumber(string s);
bool compareValue(Card a, Card b);





Player::Player(bool isBot) {
	isBot_ = isBot;
}





void Player::makeTurn(){
	drawCards();

	if(!isBot_)
		playCards();

}




void Player::drawCards(){

	while(true){
		displayTable();


		cout << "deck ------- draw from deck" << endl;
		cout << "<number> --- draw n cards from discard pile" << endl;
		string argument;
		cin >> argument;


		if(argument == "deck"){
			takeCard(deck.top());
			deck.pop();
			break;
		}

		else if(checkIfNumber(argument)){
			int cardsToTake = stoi(argument);

			if(cardsToTake <= discardPile.size()){
				for(int i = 0; i < cardsToTake; i++){
					takeCard(discardPile.back());
					discardPile.pop_back();
				}
				cardNecessaryToPlay_ = hand_.back();
				mustPlayParticularCard_ = true;
				break;
			}else notification = "There aren't that many cards in the discard pile!";

		}

		else notification = "That isn't a valid argument!";
	}
}


void Player::playCards(){
	while(true){
		displayTable();

		if(mustPlayParticularCard_)								cout << "!! You must play a " << cardNecessaryToPlay_.toString() << " !!" << endl;
		if(hand_.size() > 3)											cout << "build ------ build a meld" << endl;
		if(melds.size() > 0 && hand_.size() > 1)	cout << "add -------- add a card to an existing meld" << endl;
																							cout << "sort ------- sort the cards in your hand" << endl;
		if(!mustPlayParticularCard_)							cout << "<number> --- discard a card and end your turn" << endl;

		string argument;
		cin >> argument;


		if(hand_.size() > 3 && argument == "build") buildMeld();

		else if(melds.size() > 0 && argument == "add") addToMeld();

		else if(argument == "sort") sort(hand_.begin(), hand_.end(), compareValue);

		else if(!mustPlayParticularCard_ && checkIfNumber(argument)){
			int cardIndex = stoi(argument);

			if(cardIndex < hand_.size()){
				discardPile.push_back(hand_[cardIndex]);
				discardCard(cardIndex)
				break;
			}else notification = "That isn't a valid card number!";

		}

		else notification = "That isn't a valid argument!";

	}
}

void Player::buildMeld(){
	bool aboutToPlayNecessaryCard = !mustPlayParticularCard_;

	Meld buildingMeld = Meld();

	while(true){
		clearDisplay();
		cout << "Meld:" << endl;
		displayCardPile(buildingMeld.cards);
		cout << endl;
		displayHand();
		cout << endl << endl;

																				cout << "<number> --- add card at number to the meld" << endl;
																				cout << "cancel ----- cancel building the meld" << endl;
		if(buildingMeld.cards.size() >= 3)	cout << "done ------- add the meld to the table" << endl;

		string argument;
		cin >> argument;

		if(buildingMeld.cards.size() >= 3 && argument == "done"){
			melds.push_back(buildingMeld);
			mustPlayParticularCard_ = !aboutToPlayNecessaryCard;
			break;
		}

		else if(argument == "cancel"){
			for(Card card : buildingMeld.cards)
			hand_.push_back(card);
			aboutToPlayNecessaryCard = !mustPlayParticularCard_;
			break;
		}

		else if(checkIfNumber(argument)){
			int cardIndex = stoi(argument);
			if(hand_[cardIndex].suit == cardNecessaryToPlay_.suit && hand_[cardIndex].value == cardNecessaryToPlay_.value)
			aboutToPlayNecessaryCard = true;
			if(buildingMeld.addCard(hand[cardIndex]))
				hand_.erase(hand_.begin() + cardIndex);
			else
				notification = "You can't add that card to this meld!";
		}

		else notification = "That isn't a valid argument!";

	}
}

void Player::addToMeld(){

	while(true){
		clearDisplay();
		displayMelds();
		cout << endl;
		displayHand();
		cout << endl;

		cout << "<number of card> <number of meld to place into> --- place desired card in desired meld" << endl;
		cout << "done ---------------------------------------------- finish placing cards in the melds" << endl;

		int cardNumber;
		int meldNumber;
		if(scanf("%i %i", &cardNumber, &meldNumber))
			if(cardNumber < hand_.size() && meldNumber < melds.size())
				if(melds[meldNumber].addCard(hand_[cardNumber])){
					if(hand_[cardIndex].suit == cardNecessaryToPlay_.suit && hand_[cardIndex].value == cardNecessaryToPlay_.value){
						mustPlayParticularCard_ = false;
						discardCard(cardIndex);
					}
				}else notification = "That card doesn't belong in that meld!";
			else notification = "That isn't a valid card/meld number!";
		else break;
	}
}

bool Player::checkIfCardIsPlayable(Card card){

}


void Player::discardCard(int n){
	hand_.erase(hand_.begin() + n);
}

void Player::takeCard(Card card){
	hand_.push_back(card);
}


void Player::displayTable(){
	clearDisplay();

	cout << "Discard pile: (" << discardPile.size() << " card(s) in pile)" << endl;
	displayCardPile(discardPile);
	cout << endl << endl;

	displayMelds();
	cout << endl;

	if(!isBot_){
		displayHand();
		cout << endl << endl;
		cout << "It's your turn!" << endl;
		cout << endl << endl;
	}
}

void displayMelds(){
	cout << "Melds:" << endl;
	for(int i = 0; i< melds.size(); i++){
		cout << i;
		for(int s = 0; s < 5 + melds[i].cards.size() * 6 - to_string(i).length(); s++)
			cout << " ";
	}
	cout << endl;
	for(Meld meld : melds){
		cout << "{ ";
		displayCardPile(meld.cards, false);
		cout << "}  ";
	}
	cout << endl;
}

void Player::displayHand(){
	cout << "Your hand_:" << endl;
	for(int i = 0; i< hand_.size(); i++){
		cout << i;
		for(int s = 0; s < 6 - to_string(i).length(); s++)
			cout << " ";
	}
	cout << endl;

	displayCardPile(hand_);
}


void displayCardPile(vector<Card> pile){
	for(Card card : pile)
		cout << card.toString() << " ";
	cout << endl;
}

void displayCardPile(vector<Card> pile, bool indent){
	for(Card card : pile)
		cout << card.toString() << " ";
	if(indent) cout << endl;
}


bool checkIfNumber(const string s){
  return s.find_first_not_of( "0123456789" ) == string::npos;
}

bool compareValue(Card a, Card b){
	return a.value < b.value;
}

void clearDisplay(){
	printf("\033[2J");

	if(notification != ""){
		cout << "!! " << notification << " !!" << endl;
		notification = "";
	}
}
