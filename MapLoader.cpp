//
// Created by xintong cheng on 2018-02-13.
//

#include <sstream>
#include "MapLoader.h"
MapLoader::MapLoader(void) {

}
MapLoader::~MapLoader(void) {

}
void MapLoader:: openFile(string path) {
    inFile.open(path);
    if (!inFile.good())
    {
        cout << "Unable to open file" << path << endl;
        exit(1); // terminate with error
    }
}

void MapLoader::closeInput()
{
    inFile.close();
}

void MapLoader::readFile()
{
    string temp;
    int checkInt;

    while (getline(inFile, temp)) {

        istringstream buffer(temp);

//        buffer >> checkInt;
//        if (buffer.eof() == false){
//            cout << "Invalid map file";
//            exit(1);
//
//        }

        vector<int> line((istream_iterator<int>(buffer)),
                                 istream_iterator<int>());

        numbers.push_back(line);

    }

}

void MapLoader::displayMap(){
    for ( vector<vector<int>>::size_type i = 0; i < numbers.size(); i++ )
    {
        for ( vector<int>::size_type j = 0; j < numbers[i].size(); j++ )
        {
            cout << numbers[i][j] << ' ';
        }
        cout << endl;
    }
}

Map MapLoader::buildMap() {

    Map map = Map(numbers.size()+1);
    map.display();

}

