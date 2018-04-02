//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_DOMINATIONVIEW_H
#define SMALL_WORLD_DOMINATIONVIEW_H


#include "ViewDecorator.h"

class DominationView : public ViewDecorator {

public:
    virtual void update(Player * inputPlayer);
    virtual void update(MapRegions * inputRegion);
    virtual void showInfo();

private:
    std::vector<double> playerRegionSharePercentage;
    std::vector<int> playerRegionShareList;

};


#endif //SMALL_WORLD_DOMINATIONVIEW_H
