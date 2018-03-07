//
// Created by yanra on 2018-02-12.
//

#include "Orcs.h"
#include <iostream>
using namespace std;


Orcs::Orcs() {
    setTokens(5);
    setType("Orcs");
    //setSkill("");
}

Orcs::~Orcs() {}

void Orcs::raceSkill() {
    cout<<"Earn 1 more coin on each conquered region"<<endl;
}