//
// Created by xintong cheng on 2018-02-27.
//

#ifndef SMALL_WORLD_TWOPLAYERREGIONS_H
#define SMALL_WORLD_TWOPLAYERREGIONS_H
#include <vector>
#include "Region.h"

class MapRegions {
private:
    vector<Region*> regions;
public:
    MapRegions();
    virtual ~MapRegions();

    void display();
    void twoPlayerRegions();
    void info();
};


#endif //SMALL_WORLD_TWOPLAYERREGIONS_H
