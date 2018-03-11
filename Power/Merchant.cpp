
#include "Merchant.h"
#include<iostream>
using namespace std;

Merchant::Merchant() {
    setTokens(2);
    setType("Merchant");
    setPower("");
}

Merchant::~Merchant() {
}

void Merchant::powerSkill() {
    cout<<"Collect 1 bonus Victory coin for any Region you occupy."<<endl;
}