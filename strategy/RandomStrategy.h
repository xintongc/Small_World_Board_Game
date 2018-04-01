#pragma once
#include "PlayerStrategy.h"
#include "../Player.h"
class RandomStrategy : public PlayerStrategy, Player
{
public:
	RandomStrategy();
	~RandomStrategy();

    void play();
};

