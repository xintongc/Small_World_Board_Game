//
// Created by xintong cheng on 2018-02-10.
//

#ifndef SMALL_WORLD_REGION_H
#define SMALL_WORLD_REGION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Region {

private:

    int id;
    bool occupied;
    bool border;
    vector<string> connectedRegion;

};


#endif //SMALL_WORLD_REGION_H
