//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_HANDSVIEW_H
#define SMALL_WORLD_HANDSVIEW_H


#include "ViewDecorator.h"

class HandsView : public ViewDecorator{

private:
    std::vector<int> playerInHandCurrentRaceSoliderVector;
    std::vector<int> playerInHandDeclinedRaceSoliderVector;

public:
    virtual void update(Player * inputPlayer);
    virtual void update(MapRegions * inputRegion);
    virtual void showInfo();

};


#endif //SMALL_WORLD_HANDSVIEW_H
