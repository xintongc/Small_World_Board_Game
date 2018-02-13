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

using namespace std;

class MapLoader {

public:
    MapLoader(void);
    ~MapLoader(void);

    void openFile(string path);
    void closeInput();
    void readFile();
    void displayMap();

private:

    vector<vector<int> > numbers;
    ifstream inFile;

};


#endif //SMALL_WORLD_MAPLOADER_H
