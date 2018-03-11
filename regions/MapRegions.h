//
// Created by xintong cheng on 2018-02-27.
//

#ifndef SMALL_WORLD_TWOPLAYERREGIONS_H
#define SMALL_WORLD_TWOPLAYERREGIONS_H
#include <vector>
#include "Region.h"
#include "RegionBuilder.h"

class MapRegions {
private:

    static MapRegions* mapRegions;
    vector<Region*> regions;
    MapRegions();
    vector <RegionBuilder*> regionBuilder;

public:
    virtual ~MapRegions();
    static MapRegions* getMapRegions();
    void display();
    void createTwoPlayerRegions();
    void createThreePlayerRegions();
    void createFourPlayerRegions();
    void createFivePlayerRegions();
    void info();
    Region* getRegion(int i);
    int getRegionsSize();
};


#endif //SMALL_WORLD_TWOPLAYERREGIONS_H
