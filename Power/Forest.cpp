
#include "Forest.h"
#include<iostream>
using namespace std;


Forest::Forest() {
    setTokens(4);
    setType("Forest");
    setPower("");
}

Forest::~Forest() {
}

void Forest::powerSkill() {
    cout<<"Collect 1 bonus Victory coin for each Forest Region you occupy."<<endl;
}