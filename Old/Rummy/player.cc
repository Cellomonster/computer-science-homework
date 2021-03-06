/*
File: player.cc
-----------------
Player class.
Manages and limits player's actions.

Author: Julian Triveri
10/08/18
*/

#include <iostream>
#include <unistd.h>

#include <string>
#include <vector>

#include <algorithm>
#include <memory>

#include "card.h"
#include "rummy.h"
#include "player.h"
using namespace std;

//Notification seen at the top of the screen when player does something wrong
string notification;

void displayCardPile(vector<Card> pile);
void displayMelds();
void displayNotification();

bool checkIfNumber(string s);
bool compareValue(Card a, Card b);

/* Function: Player
 * Usage: Player(<bot/not bot>)
 * ---------------------------------------------------------------------------
 * Constructor for Player class */
Player::Player(bool isBot) {
	isBot_ = isBot;
	//ai = AI();
}

/* Function: makeTurn
 * Usage: makeTurn()
 * ---------------------------------------------------------------------------
 * Has the player draw and play cards */
void Player::makeTurn(){
	drawCards();
	playCards();
}

/* Function: drawCards
 * Usage: drawCards()
 * ---------------------------------------------------------------------------
 * Handles non-computer player's actions in respect to drawing cards from the
 * deck and discard pile */
void Player::drawCards(){
	if(!isBot_)
		//Human player
		while(true){
			displayTable();

			//Player choices
			cout << "deck ------- draw from deck" << endl;
			cout << "<number> --- draw n cards from discard pile" << endl;
			string argument;
			cin >> argument;

			//Take from deck
			if(argument == "deck"){
				takeCard(deck.top());
				deck.pop();
				break;
			}

			//Take *argument* cards from top of discard pile if a number
			else if(checkIfNumber(argument)){
				int cardsToTake = stoi(argument);

				if(cardsToTake <= discardPile.size() && cardsToTake > 0){
					//The player needs to play the last card they take from the discard pile
					//therefore, the game makes sure that card is possible to play
					//considering both existing and potential melds, or else the player
					//wouldn't be able to end their turn
					if(checkIfCardIsPlayable(discardPile[discardPile.size() - cardsToTake - 1], cardsToTake)){

						drawFromDiscardPile(cardsToTake);

						cardNecessaryToPlay_ = hand_.back();
						mustPlayParticularCard_ = true;
						break;

					}//else notification = "You aren't able to play that last card!";
				}else notification = "There aren't that many cards in the discard pile!";

			}

			else notification = "That isn't a valid argument!";
		}
	//
	else{
		//Computer Player
		while(true){
			displayTable();

			int cardsToTake = 0;
			int nonPlayableCards = 0;

			for(int i = 1; i <= discardPile.size(); i++){
				int checkResult = checkIfCardIsPlayable(discardPile[discardPile.size() - i], i);
				if(checkResult){
					cardsToTake = i;
				}else nonPlayableCards++;

				if(nonPlayableCards >= 2)
					break;
			}

			if(cardsToTake > 0){
				drawFromDiscardPile(cardsToTake);
				displayTable();
				//botActionHistory_ += "Bot drew " + cardsToTake + " card" + ((cardsToTake > 1)? "s" : "") + " from the discard pile\n";
				break;
			}else{
				drawFromDeck();
				displayTable();
				//botActionHistory_ += "Bot drew a card from the deck\n";
				break;
			}

		}
	}
}

void Player::drawFromDeck(){
	takeCard(deck.top());
	deck.pop();
}

void Player::drawFromDiscardPile(int n){
	for(int i = 0; i < n; i++){
		takeCard(discardPile.back());
		discardPile.pop_back();
	}
}

/* Function: playCards
 * Usage: playCards()
 * ---------------------------------------------------------------------------
 * Handles non-computer player's actions in respect to playing cards into the
 * discard pile and new/existing melds */
void Player::playCards(){
	if(!isBot_){
		//Human player
		while(true){
			displayTable();

			//Player choices
			if(mustPlayParticularCard_)								cout << "!! You must play a " << cardNecessaryToPlay_.toString() << " !!" << endl;
			if(hand_.size() > 3)											cout << "build ------ build a meld" << endl;
			if(melds.size())													cout << "add -------- add cards to melds" << endl;
																								cout << "sort ------- sort the cards in your hand" << endl;
			if(!mustPlayParticularCard_)							cout << "<number> --- discard a card and end your turn" << endl;

			string argument;
			cin >> argument;

			//Build meld
			if(hand_.size() > 3 && argument == "build") buildMeld();

			//Add to existing melds
			else if(melds.size() > 0 && argument == "add") addToMeld();

			//Sort hand
			//(This could be done automatically, but to make the game seem a tad bit
			//more authentic, I decided to make it manual, like a player would
			//sometimes rearrange his hand)
			else if(argument == "sort") sort(hand_.begin(), hand_.end(), compareValue);

			//Discard card
			else if(!mustPlayParticularCard_ && checkIfNumber(argument)){
				int cardIndex = stoi(argument);

				if(cardIndex < hand_.size()){
					discardPile.push_back(hand_[cardIndex]);
					removeCard(cardIndex);
					break;
				}else notification = "That isn't a valid card number!";

			}

			else notification = "That isn't a valid argument!";
		}

	}else{
		//Robots always like to keep everything neat and in order
		//(also important to keep sorted for building melds)
		sort(hand_.begin(), hand_.end(), compareValue);

		if(mustPlayParticularCard_){
			aiPlayCard(cardNecessaryToPlay_);
			mustPlayParticularCard_ = false;
		}

		for(Card card : hand_)
			aiPlayCard(card);
	}
}



/* Function: buildMeld
 * Usage: buildMeld()
 * ---------------------------------------------------------------------------
 * Handles non-computer player's actions in respect to creating a new meld */
void Player::buildMeld(){
	//Used to determine
	bool aboutToPlayNecessaryCard = !mustPlayParticularCard_;

	Meld buildingMeld = Meld();

	while(true){
		clearDisplay();
		cout << "Meld:" << endl;
		displayCardPile(buildingMeld.cards);
		cout << endl;
		displayHand();
		cout << endl;

		//Player choices
																				cout << "<number> --- add card at number to the new meld" << endl;
																				cout << "cancel ----- cancel building the meld" << endl;
		if(buildingMeld.cards.size() >= 3)	cout << "done ------- add the meld to the table" << endl;

		string argument;
		cin >> argument;

		//Finish building meld, and add to table
		//Player can only finish building if the meld is 3 or more cards
		if(buildingMeld.cards.size() >= 3 && argument == "done"){
			melds.push_back(buildingMeld);

			//If the player finishes the meld having used a card required to be played
			//the player will no longer need to play the card
			mustPlayParticularCard_ = !aboutToPlayNecessaryCard;
			break;
		}

		//Cancel building the meld
		else if(argument == "cancel"){
			for(Card card : buildingMeld.cards)
			hand_.push_back(card);

			//If the player cancels the meld having used a card required to be played
			//it will not count
			aboutToPlayNecessaryCard = !mustPlayParticularCard_;
			break;
		}

		else if(checkIfNumber(argument)){
			int cardIndex = stoi(argument);

			//The player may potentially play a card which they are required to play
			//if they do not cancel the meld
			if(hand_[cardIndex] == cardNecessaryToPlay_)
				aboutToPlayNecessaryCard = true;

			if(buildingMeld.addCard(hand_[cardIndex]))
				removeCard(cardIndex);
			else
				notification = "You can't add that card to this meld!";
		}

		else notification = "That isn't a valid argument!";

	}
}

/* Function: addToMeld
 * Usage: addToMeld()
 * ---------------------------------------------------------------------------
 * Handles non-computer player's actions in respect to adding cards to existing
 * melds */
void Player::addToMeld(){
	while(true){
		clearDisplay();
		displayMelds();
		cout << endl;
		displayHand();
		cout << endl;

		//Player choices
		cout << "<number of card> <number of meld to place into> --- place desired card in desired meld" << endl;
		cout << "done ---------------------------------------------- finish placing cards in the melds" << endl;

		int cardNumber;
		int meldNumber;
		if(scanf("%i %i", &cardNumber, &meldNumber))
			//Make sure both inputs are valid
			if(cardNumber >= 0 && meldNumber >= 0 && cardNumber < hand_.size() && meldNumber < melds.size())
				if(melds[meldNumber].addCard(hand_[cardNumber])){

					//Check if a card required to be played was played
					if(hand_[cardNumber] == cardNecessaryToPlay_)
						mustPlayParticularCard_ = false;

					removeCard(cardNumber);
				}else notification = "That card doesn't belong in that meld!";
			else notification = "That isn't a valid card/meld number!";

		//In this case, the game checks wether or not two integers were entered. if
		//not, the game assumes the player meant to finish, rather than explicitely
		//checking for 'done'
		else break;
	}
}

void Player::aiPlayCard(Card card){

	//Check if card fits into any melds
	for(Meld meld : melds)
		if(meld.addCard(card))
			return;

	//Count cards of the same values
	vector<Card> valueCards = {card};

	for(Card consideredCard : hand_){
		//Don't check the card being checked for playability against itself
		if(consideredCard.value == card.value && card != consideredCard)
				valueCards.push_back(consideredCard);
	}

	if(valueCards.size() > 2){
		Meld meld = Meld();
		meld.cards = valueCards;
		melds.push_back(meld);
		for(Card card : valueCards)
			removeCard(card);
		return;
	}

	//Count consecutive cards of a suit
	vector<Card> suitSeriesCards = {card};
	ptrdiff_t pos = find(hand_.begin(), hand_.end(), card) - hand_.begin();

			// if(consideredCard.suit == card.suit && (consideredCard.value == suitSeriesMin || consideredCard.value == suitSeriesMax)){
			// 	suitSeriesCount ++;
			// 	(consideredCard.value == suitSeriesMin)? suitSeriesMin-- : card.value == suitSeriesMax++;
			// }

}

/* Function: checkIfCardIsPlayable
 * Usage: checkIfCardIsPlayable(<card to check>, <cards from the end of the
 * 	discard pile to consider>)
 * ---------------------------------------------------------------------------
 * Checks wether or not it is possible to play a given card, considering both
 * existing and future melds */
bool Player::checkIfCardIsPlayable(Card card, int cardsToConsiderFromDiscardPile){

	//Check if card fits into any melds
	for(Meld meld : melds)
		if(meld.checkIfCompatible(card)){
			cout << "playable 3" << endl;
			return 3;
		}

	//If not, check for potential melds

	//Combine hand and cards being drawn from discard pile into a single vector
	//to check through
	vector<Card> consideredCards;
	consideredCards.reserve(hand_.size()+cardsToConsiderFromDiscardPile);
	consideredCards.insert(consideredCards.end(), hand_.begin(), hand_.end());
	consideredCards.insert(consideredCards.end(), discardPile.end() - cardsToConsiderFromDiscardPile, discardPile.end());
	//To prevent possible issues with finding consecutive cards
	sort(consideredCards.begin(), consideredCards.end(), compareValue);

	//Count cards of the same values
	int valueCount = 0;

	for(Card consideredCard : consideredCards){
		//Don't check the card being checked for playability against itself
		if(consideredCard.value == card.value && card != consideredCard){
			notification += "found compatible card";
			valueCount++;
		}


		if(valueCount > 1){
			notificatoin 
			return true;
		}
	}

	//Used to find consecutive cards in a suit
	int suitSeriesMin = card.value - 1;
	int suitSeriesMax = card.value + 1;
	int suitSeriesCount = 0;

	int cardIndex = distance(consideredCards.begin(), find(consideredCards.begin(), consideredCards.end(), card));

	for(int i = cardIndex - 1; i >= 0; i--){
		if(hand_[i].suit == card.suit){
			if(hand_[i].value == suitSeriesMin){
				suitSeriesCount++;
				suitSeriesMin--;
			}else if(hand_[i].suit < suitSeriesMin) break;

			if(suitSeriesCount > 1) return true;
		}
	}

	for(int i = cardIndex + 1; i < hand_.size(); i--){
		if(hand_[i].suit == card.suit){
			if(hand_[i].value == suitSeriesMax){
				suitSeriesCount++;
				suitSeriesMax++;
			}else if(hand_[i].suit > suitSeriesMax) break;

			if(suitSeriesCount > 1) return true;
		}
	}

	return false;
}

/* Function: removeCard
 * Usage: removeCard(<card>)
 * ---------------------------------------------------------------------------
 * Removes card from the player hand */
void Player::removeCard(Card card){
	for(int i = 0; i < hand_.size(); i++)
		if(hand_[i].suit == card.suit && hand_[i].value == card.value){
			removeCard(i);
			break;
		}
}

/* Function: removeCard
 * Usage: removeCard(<index of card>)
 * ---------------------------------------------------------------------------
 * Removes a card at index *n* from the player hand */
void Player::removeCard(int n){
	hand_.erase(hand_.begin() + n);
}

/* Function: takeCard
 * Usage: takeCard(<card>)
 * ---------------------------------------------------------------------------
 * Adds a card to the player hand */
void Player::takeCard(Card card){
	hand_.push_back(card);
}

/* Function: displayTable
 * Usage: displayTable()
 * ---------------------------------------------------------------------------
 * Displays melds, discard pile, and player's hand (if it's their own hand)  */
void Player::displayTable(){
	clearDisplay();

	cout << "Discard pile: (" << discardPile.size() << " card(s) in pile)" << endl;
	displayCardPile(discardPile);
	cout << endl << endl;

	displayMelds();
	cout << endl;

	if(true){//!isBot_){
		displayHand();
		cout << endl << endl;
		cout << "It's your turn!" << endl;
		cout << endl << endl;
	}else{
		cout << botActionHistory_ << endl;
	}
}

/* Function: displayMelds
 * Usage: displayMelds()
 * ---------------------------------------------------------------------------
 * Displays melds in a horizontal numbered list  */
void displayMelds(){
	cout << "Melds:" << endl;
	//Numbers
	for(int i = 0; i< melds.size(); i++){
		cout << i;
		//Correct spacing based on number text width
		for(int s = 0; s < 5 + melds[i].cards.size() * 6 - to_string(i).length(); s++)
			cout << " ";
	}
	cout << endl;
	//Melds TODO: toString() method in Meld class
	for(Meld meld : melds){
		cout << "{ ";
		displayCardPile(meld.cards);
		cout << "}  ";
	}
	cout << endl;
}

/* Function: displayMelds
 * Usage: displayMelds()
 * ---------------------------------------------------------------------------
 * Displays melds in a horizontal numbered list  */
void Player::displayHand(){
	cout << "Your hand_:" << endl;
	//Numbers
	for(int i = 0; i< hand_.size(); i++){
		cout << i;
		//Correct spacing based on number text width
		for(int s = 0; s < 6 - to_string(i).length(); s++)
			cout << " ";
	}
	cout << endl;

	displayCardPile(hand_);
}

/* Function: displayCardPile
 * Usage: displayCardPile(<vector of cards>)
 * ---------------------------------------------------------------------------
 * Prints each card in a   */
void displayCardPile(vector<Card> pile){
	for(Card card : pile)
		cout << card.toString() << " ";
}

/* Function: checkIfNumber
 * Usage: checkIfNumber(<string>)
 * ---------------------------------------------------------------------------
 * Checks if the contents of a string could represent an unsigned int  */
bool checkIfNumber(const string s){
	return s.find_first_not_of( "0123456789" ) == string::npos;
}

/* Function: compareValue
 * Usage: checkIfNumber(<card> <card>)
 * ---------------------------------------------------------------------------
 * Used when sorting cards  */
bool compareValue(Card a, Card b){
	return a.value < b.value;
}

/* Function: clearDisplay
 * Usage: clearDisplay()
 * ---------------------------------------------------------------------------
 * Clears the terminal window  */
void Player::clearDisplay(){
	//Only works on unix-like OSs
	cout << "\033[2J";

	//Print notification string at the top
	if(!isBot_ && notification != ""){
		cout << "!! " << notification << " !!" << endl;
		notification = "";
	}
}