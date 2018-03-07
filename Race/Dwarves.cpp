//
// Created by yanra on 2018-02-12.
//

#include "Dwarves.h"
#include<iostream>
using namespace std;

Dwarves::Dwarves() {
    tokens=3;
    skill="Earn 1 bonus coin for each Mine region";
}

Dwarves::~Dwarves() {}

void Dwarves::raceSkill() {
    cout<<"Dwarves' skill is earing more one coin for each mine region "<<endl;
}