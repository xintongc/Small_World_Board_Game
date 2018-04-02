#pragma once
#include "PlayerStrategy.h"
#include "../Player.h"
#include "../Game.h"
#include "../regions/MapRegions.h"
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
	void redeployTokensByStrategy(Player*) override ;

	void conqueredRegion(Player*, int regionID);
	void followingConquest(Player*);
	void enemyLossesWithdrawals(Player*, int regionID, int requiredTokens);
};

