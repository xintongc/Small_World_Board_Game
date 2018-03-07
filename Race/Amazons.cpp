//
// Created by yanra on 2018-02-12.
//

#include "Amazons.h"
#include<iostream>
using namespace std;

Amazons::Amazons() {
    setTokens(6);
    setSkill("Removing four tokens in redeployments");
    setType("Amazons");
}

Amazons::~Amazons() {}

void Amazons::raceSkill() {
    cout<<"Amazons' skill is removing four tokens in redeployments"<<endl;
}