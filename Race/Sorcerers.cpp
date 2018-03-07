//
// Created by yanra on 2018-02-12.
//

#include "Sorcerers.h"
#include <iostream>
using namespace std;

Sorcerers::Sorcerers() {
    setTokens(5);
    setType("Sorcerers");
    //setSkill("");
}

Sorcerers::~Sorcerers() {}

void Sorcerers::raceSkill() {
    cout<<"Conquer an opponent's region (active tokens) and region must be adjacent to yours"<<endl;
}