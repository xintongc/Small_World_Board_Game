//
// Created by xintong cheng on 2018-02-13.
//

#include <sstream>
#include<string>
#include "MapLoader.h"
MapLoader::MapLoader(void) {

}
MapLoader::~MapLoader(void) {

}

void MapLoader:: openFile(string path) {
    inFile.open(path);
    if (!inFile.good())
    {
        cout << "Unable to open file" << path << endl;  //if cannot open the file,terminate with error
        exit(1);
    }
}

void MapLoader::closeInput()
{
    inFile.close();
}

void MapLoader::readFile()
{
    string temp;

    while (getline(inFile, temp)) {  //read the map file into a 2D verctor

        istringstream buffer(temp);

        vector<int> line((istream_iterator<int>(buffer)), istream_iterator<int>());
        numbers.push_back(line);

    }

}



void MapLoader::checkMissingRegion(){ //if one region is missing, output error message and exit the system

    for (int i = 0; i < numbers.size(); i++ ){
        if(numbers[i][0] != i + 1){
            cout << "Invaild Map. The region " << i + 1 << " is missing." << endl;
            exit(0);
        }
    }

}

void MapLoader::checkNoConnectedRegion() {  //if one region is not connected with any region, output error message and exit the system
    bool invaild = false;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i].size() == 1){
            cout << "Invaild Map. The region " << i + 1 << " is not connected with any region." << endl;
            invaild = true;
        }
    }
    if(invaild){
        exit(0);
    }
}




Map* MapLoader::buildMap() {  //create a map object from the .map txt file, if two regions are connected, shows 1; otherwise shows 0

    Map* map = Map::getMap(numbers.size()+1);

    checkMissingRegion();
    checkNoConnectedRegion();

    for ( vector<vector<int>>::size_type i = 0; i < numbers.size(); i++ )
    {
        for ( vector<int>::size_type j = 1; j < numbers[i].size(); j++ )
        {
                map->addEdge(numbers[i][0],numbers[i][j]);

        }
    }

    map->checkSymmetry();
    map->display();
    return map;

}

