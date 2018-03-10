//
// Created by xintong cheng on 2018-02-27.
//

#ifndef SMALL_WORLD_TWOPLAYERREGIONS_H
#define SMALL_WORLD_TWOPLAYERREGIONS_H
#include <vector>
#include "Region.h"

class TwoPlayerRegions {
private:
    vector<Region*> regions;
public:
    TwoPlayerRegions();
    virtual ~TwoPlayerRegions();

    void display();
    void createTwoPlayerRegions();
};


#endif //SMALL_WORLD_TWOPLAYERREGIONS_H
