//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_VIEWDECORATOR_H
#define SMALL_WORLD_VIEWDECORATOR_H


#include "../Player.h"

class ViewDecorator : public Observer {

private:
    Observer* basicView;
public:
    virtual void update(Player * inputPlayer);
    virtual void update(MapRegions * inputRegion);
    virtual void showInfo();



};


#endif //SMALL_WORLD_VIEWDECORATOR_H
