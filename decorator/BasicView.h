//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_BASICVIEW_H
#define SMALL_WORLD_BASICVIEW_H


#include "../Player.h"

class BasicView : public Observer {
public:

    virtual ~BasicView();

    BasicView();
    virtual void update(Player * inputPlayer);
    virtual void update(MapRegions * inputRegion);
    virtual void showInfo();

private:
    int turnRun = 0;
};


#endif //SMALL_WORLD_BASICVIEW_H
