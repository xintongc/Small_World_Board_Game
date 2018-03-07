//
// Created by yanra on 2018-02-12.
//

#include "Skeletons.h"
#include <iostream>
using namespace std;

Skeletons::Skeletons() {
    setTokens(6);
    setType("Skeletons");
    //setSkill("");
}

Skeletons::~Skeletons() {}

void Skeletons::raceSkill() {
    cout<<"Add 1 more tokens for every 2 non-empty regions your conquered this turn"<<endl;
}