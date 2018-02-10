#include <iostream>
#include "Map.h"

using namespace std;


int main() {

    Map map = Map(5);
    map.addEdge(1,2);
    map.addEdge(3,4);

    map.display();

    return 0;
}