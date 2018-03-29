#pragma once
#include "PlayerStrategy.h"
#include <iostream>

class PlayGame
{
public:
	PlayGame(PlayerStrategy*);
	~PlayGame();

	void setStrategy(PlayerStrategy* strat) { this->strategy = strat; }
	void play();


private:
	PlayerStrategy * strategy;
};

