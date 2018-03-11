//
// Created by yanra on 2018-02-12.
//

#include "Humans.h"
#include <iostream>
using namespace std;


Humans::Humans() {
    setTokens(5);
    setType("Humans");
}

Humans::~Humans() {}

void Humans::raceSkill() {
    cout<<"Earn 1 more coin on each Farmland region"<<endl;
}