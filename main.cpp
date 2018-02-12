#include <iostream>
#include "Map.h"

using namespace std;


int main() {

    Map map = Map(23);
    map.addEdge(1,2);
    map.addEdge(3,4);

    map.display();
    cout << map.connected(1,4);
    /////

    return 0;
}