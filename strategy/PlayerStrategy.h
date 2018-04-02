#pragma once
#include "../Player.h"

class Player;
class PlayerStrategy {
public:
	PlayerStrategy() {}
	~PlayerStrategy() {}

	virtual void play() = 0;
	virtual void firstConquestByStrategy(Player*, int)= 0;
	virtual void picks_raceByStrategy(Player*, ComboList&) = 0;
	virtual void conquersByStrategy(Player*, int) = 0;
	virtual void declineComboByStrategy(Player*, ComboList &) = 0;
	virtual void redeployTokensByStrategy(Player*)=0;

};

