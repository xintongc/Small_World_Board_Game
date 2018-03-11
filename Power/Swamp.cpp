//
// Created by xintong cheng on 2018-02-12.
//

#include "Swamp.h"
#include<iostream>
using namespace std;

Swamp::Swamp() {
    setTokens(4);
    setType("Swamp");
    setPower("");
}

Swamp::Swamp(const Swamp& orig){

}

Swamp::~Swamp() {

}


void Swamp::powerSkill() {
    cout<<"Collect 1 bonus Victory coin for each Swamp Region you occupy at turn's end."<<endl;
}