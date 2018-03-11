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
    cout<<"Each not empty Region your Orcs conquered this turn is worth 1 bonus Victory coin."<<endl;
}