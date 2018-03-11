
#include "Alchemist.h"
#include<iostream>
using namespace std;

Alchemist::Alchemist() {
    setTokens(4);
    setType("Alchemist");
    setPower("");
}


Alchemist::~Alchemist() {
}

void Alchemist::powerSkill() {
    cout<<"Collect 2 bonus Victory coins at the end of each turn."<<endl;
}