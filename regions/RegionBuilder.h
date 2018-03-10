//
// Created by xintong cheng on 2018-03-09.
//

#ifndef SMALL_WORLD_REGIONBUILDER_H
#define SMALL_WORLD_REGIONBUILDER_H


#include "Region.h"

class RegionBuilder {
private:
    Region* region = new Region();

public:

    Region* build();

    RegionBuilder* setId(int id);
    RegionBuilder* setLandform(Landform landform);
    RegionBuilder* setLandMark(LandMark landMark);
    RegionBuilder* setBorder(bool border);
    RegionBuilder* setLostTribes(bool lostTribes);
    RegionBuilder* addGamePieces(GamePieces* pieces);

};


#endif //SMALL_WORLD_REGIONBUILDER_H
