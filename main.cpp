#include <iostream>
#include "Map.h"

using namespace std;


int main() {

    Map map = Map(24);
    map.addEdge(1,2);
    map.addEdge(1,6);
    map.addEdge(2,3);
    map.addEdge(2,6);
    map.addEdge(2,7);

    map.display();


    return 0;
}