//
// Created by xintong cheng on 2018-03-10.
//

#include "RegionBuilder.h"
Region* RegionBuilder::build() {
    return region;
}

RegionBuilder* RegionBuilder::setId(int id){
    region->setId(id);
    return this;
}

RegionBuilder* RegionBuilder::setOwner(Owner owner){
    region->setOwner(owner);
    return this;
}

RegionBuilder* RegionBuilder::setLandform(Landform landform){
    region->setLandform(landform);
    return this;
}
RegionBuilder* RegionBuilder::setLandMark(LandMark landMark){
    region->setLandMark(landMark);
    return this;
}
RegionBuilder* RegionBuilder::setBorder(bool border){
    region->setBorder(border);
    return this;
}
RegionBuilder*  RegionBuilder::setLostTribes(bool lostTribes){
    region->setLostTribes(lostTribes);
    return this;
}
RegionBuilder* RegionBuilder::addGamePieces(GamePieces* pieces){
    region->addGamePieces(pieces);
    return this;
}