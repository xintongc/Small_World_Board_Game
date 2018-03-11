//
// Created by yanra on 2018-02-12.
//

#include "Wizards.h"
#include <iostream>
using namespace std;

Wizards::Wizards() {
    setTokens(5);
    setType("Wizards");
    //setSkill("");
}

Wizards::~Wizards() {}

void Wizards::raceSkill() {
    cout<<"Each Magic Region your Wizards occupy is worth 1 bonus Victory coin."<<endl;
}