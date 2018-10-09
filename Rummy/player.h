#ifndef player_h
#define player_h

#include <vector>
#include "card.h"

class Player{
public:
  const bool bot_;
	vector<Card> hand;

public:
  Player(int suit, int value);
};

#endif
