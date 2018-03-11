//
// Created by xintong cheng on 2018-02-27.
//

#include "TwoPlayerRegions.h"
#include "RegionBuilder.h"
#include "../gamePieces/Mountains.h"


TwoPlayerRegions::TwoPlayerRegions() {}
TwoPlayerRegions::~TwoPlayerRegions() {}

void TwoPlayerRegions::display(){
    for(int i = 0; i < regions.size(); i++){
        regions[i]->info();
    }
}

void TwoPlayerRegions::info(){
    cout << "Landform: FarmLand, Hill, Forest, Swamp, Lake, Sea, Mountain" << endl;
    cout << "              0      1       2      3      4    5      6" <<endl;
    cout << "LandMark: Non, Mine, Magic, Cavern, Mine_Cavern" << endl;
    cout << "           0     1     2      3          4" <<endl;
}

void TwoPlayerRegions::createTwoPlayerRegions(){

    RegionBuilder* regionBuilder = new RegionBuilder();
    Region* region1 = regionBuilder->setId(1)->setLandform(Landform::Sea)->setBorder(true)->build();
    region1->info();
    regions.push_back(region1);

    Region* region2 = regionBuilder->setId(2)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    region2->info();
    regions.push_back(region2);

    Region* region3 = regionBuilder->setId(3)->setLandform(Landform::Forest)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    region3->info();
//    regions.push_back(region3);

    Region* region6 = regionBuilder->setId(6)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine_Cavern)->setBorder(true)->addGamePieces(new Mountains())->build();
    region6->info();
//    regions.push_back(region6);
}


