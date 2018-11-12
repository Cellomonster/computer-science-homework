/*
File: rummy.cc
-----------------
Manages the game.

Author: Julian Triveri
10/08/18
*/

#include <iostream>

#include <vector>
#include <stack>

#include <algorithm>
#include <random>

#include "card.h"
#include "player.h"
#include "rummy.h"

using namespace std;

stack<Card> deck;
vector<Card> discardPile;
vector<Meld> melds;
vector<Player> players;

bool gameOver = false;

/* Main function */
int main(void){
	srand(time(NULL));
  initializeGame();

	//Continue game until somebody runs out of cards
  while(!gameOver){
    for(Player &player : players)
      player.makeTurn();
  }

  return 0;
}

/* Function: initializeGame
 * Usage: initializeGame()
 * ---------------------------------------------------------------------------
 * Initializes players, generates deck, and deals cards */
void initializeGame(){
	//Single human player
  players.push_back(Player(false));

  int bots;
  cout << "How many bots would you like to play against?" << endl;
  cin >> bots;
	//0 bots for testing. Max of 3 bots.
	if(bots < 0 || bots > 3) bots = 3;

  for(int i = 0; i < bots; i++)
    players.push_back(Player(true));

  initializeDeck();
  dealDeck();
}

/* Function: initializeDeck
 * Usage: initializeDeck()
 * ---------------------------------------------------------------------------
 * Creates and shuffles card deck */
void initializeDeck(){
	//Since deck is a stack, we need to first use a vector to shuffle cards
  vector<Card> cards;
  for(int i = 0; i < 52; i++)
     cards.push_back(Card{i/13, i%13});

  //Shuffle cards
  shuffle(begin(cards), end(cards), default_random_engine{});

  //Move shuffled cards to the deck
  for(int i = 0; i < 52; i++){
    deck.push(cards.back());
    cards.pop_back();
  }
}

/* Function: dealDeck
 * Usage: dealDeck()
 * ---------------------------------------------------------------------------
 * Gives each player 7 cards, and adds a single card to the discard pile */
void dealDeck(){
  for(int i = 0; i < players.size() * 7; i++){
    players[i / 7].takeCard(deck.top());
    deck.pop();
  }

	//Add initial first card to discard pile
  discardPile.push_back(deck.top());
  deck.pop();
}
