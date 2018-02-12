//
// Created by xintong cheng on 2018-02-08.
//

#include "Map.h"


Map::Map(int n) {

    this->n = n;
//        visited = new bool[n];
    adjacencyMatrix = new int* [n];


    for(int i = 0; i < n; i++){
        adjacencyMatrix[i] = new int[n];
        for(int j = 0; j < n; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        adjacencyMatrix[0][i] = i;
        adjacencyMatrix[i][0] = i;
    }

}

Map::~Map() {
    delete adjacencyMatrix;
}


void Map::display(){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){


            if(j == 0){
                if(i < 10)
                    cout << "0";
            }
            if (i == 0){
                if(j < 10 && j != 0)
                    cout << "0";
            }

            if(i > 0){
                cout << adjacencyMatrix[i][j] <<"  ";
            } else {
                cout << adjacencyMatrix[i][j] <<" ";
            }

        }
        cout << endl;
    }
}

void Map::addEdge(int origin, int destin) {

    if(origin > n || destin > n || origin < 0 || destin < 0){
        cout<<"Invalid edge!\n";
    } else {
        adjacencyMatrix[origin][destin] = 1;
        adjacencyMatrix[destin][origin] = 1;
    }
}

bool Map::connected(int origin, int destin) {
    if(adjacencyMatrix[origin][destin] == 1){
        return true;
    }
    cout << "Region " << origin << " and region " << destin <<" are not connected." << endl;
    return false;
}
