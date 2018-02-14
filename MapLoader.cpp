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

    while (getline(inFile, temp)) {

        istringstream buffer(temp);

//        char *y = temp.c_str();
//        cout << (int)temp;

        vector<int> line((istream_iterator<int>(buffer)), istream_iterator<int>());
        numbers.push_back(line);

    }

}



Map MapLoader::buildMap() {

    Map map = Map(numbers.size()+1);

    for ( vector<vector<int>>::size_type i = 0; i < numbers.size(); i++ )
    {
        for ( vector<int>::size_type j = 1; j < numbers[i].size(); j++ )
        {
            try {
                map.addEdge(numbers[i][0],numbers[i][j]);

            }catch (const std::invalid_argument& e) {
                cout << "Invalid map file";
            }

        }
    }

    map.display();

}

