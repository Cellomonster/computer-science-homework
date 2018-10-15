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
vector<Player> players;
vector<Meld> melds;

bool gameOver = false;

void initializeGame();

int main(void){
  initializeGame();

  while(!gameOver){
    for(Player &player : players)
      player.makeTurn();
  }

  return 0;
}

void initializeDeck();
void dealDeck();

void initializeGame(){
  players.push_back(Player(false));

  int bots;
  cout << "How many bots would you like to play against?" << endl;
  cin >> bots;
  if(bots > 4) bots = 4;

  for(int i = 0; i < bots; i++){
    players.push_back(Player(true));
  }

  initializeDeck();
  dealDeck();
}

void initializeDeck(){
  vector<Card> cards;
  for(int s = 0; s < 4; s++)
    for(int v = 0; v < 13; v++)
      cards.push_back(Card{s, v});

  //Shuffle cards
  auto rng = default_random_engine{};
  shuffle(begin(cards), end(cards), rng);

  //Move cards to the deck
  for(int i = 0; i < 52; i++){
    deck.push(cards.back());
    cards.pop_back();
  }
}

void dealDeck(){
  for(int i = 0; i < players.size() * 7; i++){
    players[i / 7].takeCard(deck.top());
    deck.pop();
  }

  discardPile.push_back(deck.top());
  deck.pop();
}
