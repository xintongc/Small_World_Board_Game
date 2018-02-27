//
// Created by xintong cheng on 2018-02-08.
//

#ifndef SMALL_WORLD_MAP_H
#define SMALL_WORLD_MAP_H


#include <iostream>
#include <string>

using namespace std;

class Map {
private:

    int n;
    int **adjacencyMatrix;

public:

    Map(int n);
    ~Map();
    void display();
    void addEdge(int origin, int destin);
    bool connected(int origin, int destin);
    void checkSymmetry();
};



#endif //SMALL_WORLD_MAP_H
