#pragma once
#include "PlayerStrategy.h"
#include "../Player.h"
class RandomStrategy : public PlayerStrategy
{
public:
	RandomStrategy();
	~RandomStrategy();

    void play();

	void firstConquestByStrategy(Player*, int i) override;
	void picks_raceByStrategy(Player*, ComboList &combo) override;
	void conquersByStrategy(Player*, int playerNum) override;
	void declineComboByStrategy(Player*, ComboList &combo) override;
};

