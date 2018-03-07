//
// Created by yanra on 2018-02-12.
//

#include "Amazons.h"
#include<iostream>
using namespace std;

Amazons::Amazons() {
    tokens=6;
    skill="Removing four tokens in redeployments";
}

Amazons::~Amazons() {}

void Amazons::raceSkill() {
    cout<<"Amazons' skill is taking out four tokens at the end "<<endl;
}