//
// Created by xintong cheng on 2018-03-09.
//

#include "RegionBuilder.h"


Region* RegionBuilder::build() {
    return region;
}

RegionBuilder* RegionBuilder::setId(int id){
    region->setId(id);
    return this;
}

RegionBuilder setLandform(Landform landform);
RegionBuilder setLandMark(LandMark landMark);
RegionBuilder setBorder(bool border);
RegionBuilder  setLostTribes(bool lostTribes);
RegionBuilder addGamePieces(GamePieces* pieces);