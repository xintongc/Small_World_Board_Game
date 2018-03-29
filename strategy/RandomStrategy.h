#pragma once
#include "PlayerStrategy.h"
class RandomStrategy : public PlayerStrategy
{
public:
	RandomStrategy();
	~RandomStrategy();

    void play();
};

