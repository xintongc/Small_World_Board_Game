//
// Created by xintong cheng on 2018-02-27.
//

#include "MapRegions.h"
#include "RegionBuilder.h"
#include "../gamePieces/Mountains.h"

MapRegions* MapRegions::mapRegions = 0;
MapRegions* MapRegions::getMapRegions() {
    if(mapRegions == 0){
        mapRegions = new MapRegions;
    }
    return mapRegions;
}

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

void MapRegions::createTwoPlayerRegions(){

    for (int i=1;i<24;i++){
        regionBuilder.push_back(new RegionBuilder());
    }


    Region* region1 = regionBuilder[1]->setId(1)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region1);

    Region* region2 = regionBuilder[2]->setId(2)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region2);

    Region* region3 = regionBuilder[3]->setId(3)->setLandform(Landform::Forest)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region3);

    Region* region4 = regionBuilder[4]->setId(4)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setBorder(true)->setLostTribes(true)->build();
    regions.push_back(region4);

    Region* region5 = regionBuilder[5]->setId(5)->setLandform(Landform::Hill)->setBorder(true)->build();
    regions.push_back(region5);

    Region* region6 = regionBuilder[6]->setId(6)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine_Cavern)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region6);

    Region* region7 = regionBuilder[7]->setId(7)->setLandform(Landform::Hill)->setLostTribes(true)->build();
    regions.push_back(region7);

    Region* region8 = regionBuilder[8]->setId(8)->setLandform(Landform::Lake)->build();
    regions.push_back(region8);

    Region* region9 = regionBuilder[9]->setId(9)->setLandform(Landform::Mountain)->addGamePieces(new Mountains())->build();
    regions.push_back(region9);

    Region* region10 = regionBuilder[10]->setId(10)->setLandform(Landform::FarmLand)->build();
    regions.push_back(region10);

    Region* region11 = regionBuilder[11]->setId(11)->setLandform(Landform::Forest)->setLandMark(LandMark::Magic)->setBorder(true)->setLostTribes(true)->build();
    regions.push_back(region11);

    Region* region12 = regionBuilder[12]->setId(12)->setLandform(Landform::FarmLand)->setBorder(true)->setLostTribes(true)->build();
    regions.push_back(region12);

    Region* region13 = regionBuilder[13]->setId(13)->setLandform(Landform::Forest)->setLostTribes(true)->build();
    regions.push_back(region13);

    Region* region14 = regionBuilder[14]->setId(14)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Magic)->setLostTribes(true)->build();
    regions.push_back(region14);

    Region* region15 = regionBuilder[15]->setId(15)->setLandform(Landform::Hill)->setLandMark(LandMark::Cavern)->setLostTribes(true)->build();
    regions.push_back(region15);

    Region* region16 = regionBuilder[16]->setId(16)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region16);

    Region* region17 = regionBuilder[17]->setId(17)->setLandform(Landform::Swamp)->setLandMark(LandMark::Magic)->setBorder(true)->setLostTribes(true)->build();
    regions.push_back(region17);

    Region* region18 = regionBuilder[18]->setId(18)->setLandform(Landform::Hill)->setLandMark(LandMark::Cavern)->setBorder(true)->build();
    regions.push_back(region18);

    Region* region19 = regionBuilder[19]->setId(19)->setLandform(Landform::Swamp)->setLandMark(LandMark::Mine)->setBorder(true)->setLostTribes(true)->build();
    regions.push_back(region19);

    Region* region20 = regionBuilder[20]->setId(20)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region20);

    Region* region21 = regionBuilder[21]->setId(21)->setLandform(Landform::Swamp)->setBorder(true)->build();
    regions.push_back(region21);

    Region* region22 = regionBuilder[22]->setId(22)->setLandform(Landform::Forest)->setBorder(true)->build();
    regions.push_back(region22);

    Region* region23 = regionBuilder[23]->setId(23)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region23);

}

void MapRegions::createThreePlayerRegions() {
    for (int i=1;i<31;i++){
        regionBuilder.push_back(new RegionBuilder());
    }

    Region* region1 = regionBuilder[1]->setId(1)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region1);

    Region* region2 = regionBuilder[2]->setId(2)->setLandform(Landform::Forest)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region2);

    Region* region3 = regionBuilder[3]->setId(3)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region3);

    Region* region4 = regionBuilder[4]->setId(4)->setLandform(Landform::FarmLand)->setBorder(true)->build();
    regions.push_back(region4);

    Region* region5 = regionBuilder[5]->setId(5)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setBorder(true)->build();
    regions.push_back(region5);

    Region* region6 = regionBuilder[6]->setId(6)->setLandform(Landform::Forest)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region6);

    Region* region7 = regionBuilder[7]->setId(7)->setLandform(Landform::Swamp)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region7);

    Region* region8 = regionBuilder[8]->setId(8)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Magic)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region8);

    Region* region9 = regionBuilder[9]->setId(9)->setLandform(Landform::Swamp)->build();
    regions.push_back(region9);

    Region* region10 = regionBuilder[10]->setId(10)->setLandform(Landform::Hill)->setLandMark(LandMark::Magic)->setLostTribes(true)->build();
    regions.push_back(region10);

    Region* region11 = regionBuilder[11]->setId(11)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine)->addGamePieces(new Mountains())->build();
    regions.push_back(region11);

    Region* region12 = regionBuilder[12]->setId(12)->setLandform(Landform::FarmLand)->setLostTribes(true)->build();
    regions.push_back(region12);

    Region* region13 = regionBuilder[13]->setId(13)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine_Cavern)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region13);

    Region* region14 = regionBuilder[14]->setId(14)->setLandform(Landform::Swamp)->setLostTribes(true)->build();
    regions.push_back(region14);

    Region* region15 = regionBuilder[15]->setId(15)->setLandform(Landform::Lake)->build();
    regions.push_back(region15);

    Region* region16 = regionBuilder[16]->setId(16)->setLandform(Landform::Mountain)->setLandMark(LandMark::Cavern)->addGamePieces(new Mountains())->build();
    regions.push_back(region16);

    Region* region17 = regionBuilder[17]->setId(17)->setLandform(Landform::Hill)->setLandMark(LandMark::Magic)->build();
    regions.push_back(region17);

    Region* region18 = regionBuilder[18]->setId(18)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region18);

    Region* region19 = regionBuilder[19]->setId(19)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region19);

    Region* region20 = regionBuilder[20]->setId(20)->setLandform(Landform::Forest)->setLandMark(LandMark::Cavern)->setLostTribes(true)->build();
    regions.push_back(region20);

    Region* region21 = regionBuilder[21]->setId(21)->setLandform(Landform::Hill)->build();
    regions.push_back(region21);

    Region* region22 = regionBuilder[22]->setId(22)->setLandform(Landform::Swamp)->setLandMark(LandMark::Magic)->setLostTribes(true)->build();
    regions.push_back(region22);

    Region* region23 = regionBuilder[23]->setId(23)->setLandform(Landform::FarmLand)->setLostTribes(true)->build();
    regions.push_back(region23);

    Region* region24 = regionBuilder[24]->setId(24)->setLandform(Landform::Hill)->setLandMark(LandMark::Cavern)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region24);

    Region* region25 = regionBuilder[25]->setId(25)->setLandform(Landform::Hill)->setBorder(true)->build();
    regions.push_back(region25);

    Region* region26 = regionBuilder[26]->setId(26)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region26);

    Region* region27 = regionBuilder[27]->setId(27)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region27);

    Region* region28 = regionBuilder[28]->setId(28)->setLandform(Landform::Forest)->setBorder(true)->build();
    regions.push_back(region28);

    Region* region29 = regionBuilder[29]->setId(29)->setLandform(Landform::Forest)->setLandMark(LandMark::Mine)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region29);

    Region* region30 = regionBuilder[30]->setId(30)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region30);
}

void MapRegions::createFourPlayerRegions() {
    for (int i = 1; i < 40; i++) {
        regionBuilder.push_back(new RegionBuilder());
    }

    Region *region1 = regionBuilder[1]->setId(1)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region1);

    Region* region2 = regionBuilder[2]->setId(2)->setLandform(Landform::FarmLand)->setBorder(true)->build();
    regions.push_back(region2);

    Region* region3 = regionBuilder[3]->setId(3)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Mine)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region3);

    Region* region4 = regionBuilder[4]->setId(4)->setLandform(Landform::Forest)->setLandMark(LandMark::Cavern)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region4);

    Region* region5 = regionBuilder[5]->setId(5)->setLandform(Landform::Hill)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region5);

    Region* region6 = regionBuilder[6]->setId(6)->setLandform(Landform::Swamp)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region6);

    Region* region7 = regionBuilder[7]->setId(7)->setLandform(Landform::Swamp)->setLandMark(LandMark::Magic)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region7);

    Region* region8 = regionBuilder[8]->setId(8)->setLandform(Landform::Hill)->setLandMark(LandMark::Cavern)->setLostTribes(true)->build();
    regions.push_back(region8);

    Region* region9 = regionBuilder[9]->setId(9)->setLandform(Landform::FarmLand)->build();
    regions.push_back(region9);

    Region* region10 = regionBuilder[10]->setId(10)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine)->addGamePieces(new Mountains())->build();
    regions.push_back(region10);

    Region* region11 = regionBuilder[11]->setId(11)->setLandform(Landform::Forest)->setLandMark(LandMark::Magic)->setLostTribes(true)->build();
    regions.push_back(region11);

    Region* region12 = regionBuilder[12]->setId(12)->setLandform(Landform::Forest)->setLandMark(LandMark::Cavern)->setBorder(true)->build();
    regions.push_back(region12);

    Region* region13 = regionBuilder[13]->setId(13)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region13);

    Region* region14 = regionBuilder[14]->setId(14)->setLandform(Landform::Forest)->setBorder(true)->build();
    regions.push_back(region14);

    Region* region15 = regionBuilder[15]->setId(15)->setLandform(Landform::Swamp)->setLostTribes(true)->build();
    regions.push_back(region15);

    Region* region16 = regionBuilder[16]->setId(16)->setLandform(Landform::Hill)->setLandMark(LandMark::Magic)->build();
    regions.push_back(region16);

    Region* region17 = regionBuilder[17]->setId(17)->setLandform(Landform::Lake)->build();
    regions.push_back(region17);

    Region* region18 = regionBuilder[18]->setId(18)->setLandform(Landform::Swamp)->setLandMark(LandMark::Mine)->build();
    regions.push_back(region18);

    Region* region19 = regionBuilder[19]->setId(19)->setLandform(Landform::FarmLand)->setBorder(true)->build();
    regions.push_back(region19);

    Region* region20 = regionBuilder[20]->setId(20)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region20);

    Region* region21 = regionBuilder[21]->setId(21)->setLandform(Landform::Hill)->build();
    regions.push_back(region21);

    Region* region22 = regionBuilder[22]->setId(22)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine_Cavern)->addGamePieces(new Mountains())->build();
    regions.push_back(region22);

    Region* region23 = regionBuilder[23]->setId(23)->setLandform(Landform::FarmLand)->setLostTribes(true)->build();
    regions.push_back(region23);

    Region* region24 = regionBuilder[24]->setId(24)->setLandform(Landform::Hill)->setLostTribes(true)->build();
    regions.push_back(region24);

    Region* region25 = regionBuilder[25]->setId(25)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region25);

    Region* region26 = regionBuilder[26]->setId(26)->setLandform(Landform::Swamp)->setLandMark(LandMark::Mine)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region26);

    Region* region27 = regionBuilder[27]->setId(27)->setLandform(Landform::Forest)->setLandMark(LandMark::Magic)->setLostTribes(true)->build();
    regions.push_back(region27);

    Region* region28 = regionBuilder[28]->setId(28)->setLandform(Landform::Mountain)->addGamePieces(new Mountains())->build();
    regions.push_back(region28);

    Region* region29 = regionBuilder[29]->setId(29)->setLandform(Landform::FarmLand)->setBorder(true)->build();
    regions.push_back(region29);

    Region* region30 = regionBuilder[30]->setId(30)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region30);

    Region* region31 = regionBuilder[31]->setId(31)->setLandform(Landform::Hill)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region31);

    Region* region32 = regionBuilder[32]->setId(32)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setLostTribes(true)->build();
    regions.push_back(region32);

    Region* region33 = regionBuilder[33]->setId(33)->setLandform(Landform::Forest)->setLandMark(LandMark::Magic)->setLostTribes(true)->build();
    regions.push_back(region33);

    Region* region34 = regionBuilder[34]->setId(34)->setLandform(Landform::Mountain)->setLandMark(LandMark::Cavern)->addGamePieces(new Mountains())->build();
    regions.push_back(region34);

    Region* region35 = regionBuilder[35]->setId(35)->setLandform(Landform::Hill)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region35);

    Region* region36 = regionBuilder[36]->setId(36)->setLandform(Landform::FarmLand)->setBorder(true)->build();
    regions.push_back(region36);

    Region* region37 = regionBuilder[37]->setId(37)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region37);

    Region* region38 = regionBuilder[38]->setId(38)->setLandform(Landform::Forest)->setBorder(true)->build();
    regions.push_back(region38);

    Region* region39 = regionBuilder[39]->setId(39)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region39);
}

void MapRegions::createFivePlayerRegions() {
    for (int i = 1; i < 49; i++) {
        regionBuilder.push_back(new RegionBuilder());
    }

    Region *region1 = regionBuilder[1]->setId(1)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region1);

    Region* region2 = regionBuilder[2]->setId(2)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region2);

    Region* region3 = regionBuilder[3]->setId(3)->setLandform(Landform::Swamp)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region3);

    Region* region4 = regionBuilder[4]->setId(4)->setLandform(Landform::Mountain)->setLandMark(LandMark::Cavern)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region4);

    Region* region5 = regionBuilder[5]->setId(5)->setLandform(Landform::Forest)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region5);

    Region* region6 = regionBuilder[6]->setId(6)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Cavern)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region6);

    Region* region7 = regionBuilder[7]->setId(7)->setLandform(Landform::Swamp)->setBorder(true)->build();
    regions.push_back(region7);

    Region* region8 = regionBuilder[8]->setId(8)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Mine)->setLostTribes(true)->build();
    regions.push_back(region8);

    Region* region9 = regionBuilder[9]->setId(9)->setLandform(Landform::Hill)->build();
    regions.push_back(region9);

    Region* region10 = regionBuilder[10]->setId(10)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine)->addGamePieces(new Mountains())->build();
    regions.push_back(region10);

    Region* region11 = regionBuilder[11]->setId(11)->setLandform(Landform::FarmLand)->setBorder(true)->build();
    regions.push_back(region11);

    Region* region12 = regionBuilder[12]->setId(12)->setLandform(Landform::Hill)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region12);

    Region* region13 = regionBuilder[13]->setId(13)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Cavern)->setLostTribes(true)->build();
    regions.push_back(region13);

    Region* region14 = regionBuilder[14]->setId(14)->setLandform(Landform::Mountain)->addGamePieces(new Mountains())->build();
    regions.push_back(region14);

    Region* region15 = regionBuilder[15]->setId(15)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setLostTribes(true)->build();
    regions.push_back(region15);

    Region* region16 = regionBuilder[16]->setId(16)->setLandform(Landform::Hill)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region16);

    Region* region17 = regionBuilder[17]->setId(17)->setLandform(Landform::Hill)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region17);

    Region* region18 = regionBuilder[18]->setId(18)->setLandform(Landform::Forest)->setLandMark(LandMark::Magic)->setBorder(true)->build();
    regions.push_back(region18);

    Region* region19 = regionBuilder[19]->setId(19)->setLandform(Landform::Swamp)->setLostTribes(true)->build();
    regions.push_back(region19);

    Region* region20 = regionBuilder[20]->setId(20)->setLandform(Landform::Hill)->setLandMark(LandMark::Magic)->build();
    regions.push_back(region20);

    Region* region21 = regionBuilder[21]->setId(21)->setLandform(Landform::Lake)->build();
    regions.push_back(region21);

    Region* region22 = regionBuilder[22]->setId(22)->setLandform(Landform::Forest)->build();
    regions.push_back(region22);

    Region* region23 = regionBuilder[23]->setId(23)->setLandform(Landform::Mountain)->setLandMark(LandMark::Magic)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region23);

    Region* region24 = regionBuilder[24]->setId(24)->setLandform(Landform::FarmLand)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region24);

    Region* region25 = regionBuilder[25]->setId(25)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine_Cavern)->addGamePieces(new Mountains())->build();
    regions.push_back(region25);

    Region* region26 = regionBuilder[26]->setId(26)->setLandform(Landform::Swamp)->setLandMark(LandMark::Mine)->setLostTribes(true)->build();
    regions.push_back(region26);

    Region* region27 = regionBuilder[27]->setId(27)->setLandform(Landform::FarmLand)->setBorder(true)->build();
    regions.push_back(region27);

    Region* region28 = regionBuilder[28]->setId(28)->setLandform(Landform::Forest)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region28);

    Region* region29 = regionBuilder[29]->setId(29)->setLandform(Landform::Swamp)->setBorder(true)->build();
    regions.push_back(region29);

    Region* region30 = regionBuilder[30]->setId(30)->setLandform(Landform::Hill)->setLostTribes(true)->build();
    regions.push_back(region30);

    Region* region31 = regionBuilder[31]->setId(31)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Magic)->build();
    regions.push_back(region31);

    Region* region32 = regionBuilder[32]->setId(32)->setLandform(Landform::Forest)->setLostTribes(true)->build();
    regions.push_back(region32);

    Region* region33 = regionBuilder[33]->setId(33)->setLandform(Landform::Hill)->build();
    regions.push_back(region33);

    Region* region34 = regionBuilder[34]->setId(34)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region34);

    Region* region35 = regionBuilder[35]->setId(35)->setLandform(Landform::FarmLand)->setLandMark(LandMark::Cavern)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region35);

    Region* region36 = regionBuilder[36]->setId(36)->setLandform(Landform::Forest)->setLostTribes(true)->build();
    regions.push_back(region36);

    Region* region37 = regionBuilder[37]->setId(37)->setLandform(Landform::FarmLand)->build();
    regions.push_back(region37);

    Region* region38 = regionBuilder[38]->setId(38)->setLandform(Landform::Swamp)->setLandMark(LandMark::Cavern)->setLostTribes(true)->build();
    regions.push_back(region38);

    Region* region39 = regionBuilder[39]->setId(39)->setLandform(Landform::Forest)->build();
    regions.push_back(region39);

    Region* region40 = regionBuilder[40]->setId(40)->setLandform(Landform::Mountain)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region40);

    Region* region41 = regionBuilder[41]->setId(41)->setLandform(Landform::Mountain)->setLandMark(LandMark::Mine)->addGamePieces(new Mountains())->build();
    regions.push_back(region41);

    Region* region42 = regionBuilder[42]->setId(42)->setLandform(Landform::Hill)->setLandMark(LandMark::Magic)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region42);

    Region* region43 = regionBuilder[43]->setId(43)->setLandform(Landform::Swamp)->setLandMark(LandMark::Mine)->setLostTribes(true)->setBorder(true)->build();
    regions.push_back(region43);

    Region* region44 = regionBuilder[44]->setId(44)->setLandform(Landform::Forest)->setLandMark(LandMark::Magic)->setBorder(true)->setLostTribes(true)->build();
    regions.push_back(region44);

    Region* region45 = regionBuilder[45]->setId(45)->setLandform(Landform::Hill)->setLandMark(LandMark::Mine)->setBorder(true)->build();
    regions.push_back(region45);

    Region* region46 = regionBuilder[46]->setId(46)->setLandform(Landform::Mountain)->setLandMark(LandMark::Magic)->setBorder(true)->addGamePieces(new Mountains())->build();
    regions.push_back(region46);

    Region* region47 = regionBuilder[47]->setId(47)->setLandform(Landform::Forest)->setLandMark(LandMark::Cavern)->setBorder(true)->build();
    regions.push_back(region47);

    Region *region48 = regionBuilder[48]->setId(48)->setLandform(Landform::Sea)->setBorder(true)->build();
    regions.push_back(region48);

}