//
// Created by xintong cheng on 2018-02-27.
//

#ifndef SMALL_WORLD_TWOPLAYERREGIONS_H
#define SMALL_WORLD_TWOPLAYERREGIONS_H
#include <vector>
#include "Region.h"

class MapRegions {
private:

    static MapRegions* mapRegions;
    vector<Region*> regions;
    MapRegions();

public:
    virtual ~MapRegions();
    static MapRegions* getMapRegions();
    void display();
    void createTwoPlayerRegions();
    void info();
    Region* getRegion(int i);
};


#endif //SMALL_WORLD_TWOPLAYERREGIONS_H
