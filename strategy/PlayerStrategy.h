#pragma once
#include "../Player.h"

//Strategy Abstract Class
//The classes that implement a concrete strategy should inherit this.
//The Player class uses this to use a concrete strategy.
class Player;
class PlayerStrategy {
public:
	PlayerStrategy() {}
	~PlayerStrategy() {}

	//Method whose implementation varies depending on the strategy adopted.
	virtual void play() = 0;
	virtual void firstConquestByStrategy(Player*, int)= 0;
	virtual void picks_raceByStrategy(Player*, ComboList&) = 0;
	virtual void conquersByStrategy(Player*, int) = 0;
	virtual void declineComboByStrategy(Player*, ComboList &) = 0;
	virtual void redeployTokensByStrategy(Player*)=0;

};

