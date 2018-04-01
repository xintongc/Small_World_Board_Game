#pragma once
#include "../Player.h"

class Player;
class PlayerStrategy
{
public:
	PlayerStrategy() {}
	~PlayerStrategy() {}

	virtual void play() = 0;

};

