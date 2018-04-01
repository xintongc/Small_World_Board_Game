#pragma once
#include "../Player.h"

class Player;
class PlayerStrategy
{
public:
//	PlayerStrategy() {}
//	~PlayerStrategy() {}

	virtual void play() = 0;
	virtual void firstConquestByStrategy(int)= 0;
//	virtual void picks_raceByStrategy(ComboList& combo) = 0;

};

