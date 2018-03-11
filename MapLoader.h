//
// Created by xintong cheng on 2018-02-13.
//

#ifndef SMALL_WORLD_MAPLOADER_H
#define SMALL_WORLD_MAPLOADER_H

#include<iostream>
#include <fstream>
#include<string>
#include <vector>
#include <sstream>
#include "Map.h"

using namespace std;

class MapLoader {

public:
    MapLoader(void);
    ~MapLoader(void);

    void openFile(string path);
    void closeInput();
    void readFile();
    void buildMap();


private:

    vector<vector<int> > numbers;
    ifstream inFile;

    void checkMissingRegion();
    void checkNoConnectedRegion();

};


#endif //SMALL_WORLD_MAPLOADER_H
