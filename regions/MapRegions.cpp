//
// Created by xintong cheng on 2018-02-27.
//

#include "MapRegions.h"
#include "RegionBuilder.h"
#include "../gamePieces/Mountains.h"


MapRegions::MapRegions() {}
MapRegions::~MapRegions() {}

void MapRegions::display(){
    for(int i = 0; i < regions.size(); i++){
        regions[i]->info();
    }
}

void MapRegions::info(){
    cout << "Landform: FarmLand, Hill, Forest, Swamp, Lake, Sea, Mountain" << endl;
    cout << "              0      1       2      3      4    5      6" <<endl;
    cout << "LandMark: Non, Mine, Magic, Cavern, Mine_Cavern" << endl;
    cout << "           0     1     2      3          4" <<endl;
}

void MapRegions::twoPlayerRegions(){

    RegionBuilder* regionBuilder1 = new RegionBuilder();
    RegionBuilder* regionBuilder2 = new RegionBuilder();
    RegionBuilder* regionBuilder3 = new RegionBuilder();
    RegionBuilder* regionBuilder4 = new RegionBuilder();
    RegionBuilder* regionBuilder5 = new RegionBuilder();
    RegionBuilder* regionBuilder6 = new RegionBuilder();

    Region* region1 = regionBuilder1->setId(1)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region1);

    Region* region2 = regionBuilder2->setId(2)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region2);

    Region* region3 = regionBuilder3->setId(3)->setLandform(Landform::Forest)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region3);

    Region* region4 = regionBuilder4->setId(4)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setBorder(true)->setLostTribes(true)->build();
    regions.push_back(region4);

    Region* region5 = regionBuilder5->setId(5)->setLandform(Landform::Hill)->setBorder(true)->build();
    regions.push_back(region5);

    Region* region6 = regionBuilder6->setId(6)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine_Cavern)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region6);


}


