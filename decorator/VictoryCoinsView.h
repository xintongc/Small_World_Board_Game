//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_VICTORYCOINSVIEW_H
#define SMALL_WORLD_VICTORYCOINSVIEW_H


#include "ViewDecorator.h"

class VictoryCoinsView : ViewDecorator{

public:
    virtual void update(Player * inputPlayer);
    virtual void update(MapRegions * inputRegion);
    virtual void showInfo();

private:
    std::vector<int> playerVictoryCoinsList;

};


#endif //SMALL_WORLD_VICTORYCOINSVIEW_H
