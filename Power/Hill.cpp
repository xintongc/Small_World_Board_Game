
#include "Hill.h"
#include<iostream>
using namespace std;

Hill::Hill() {
    setTokens(4);
    setType("Hill");
    setPower("");
}

Hill::Hill(const Hill& orig) {
}

Hill::~Hill() {
}

void Hill::powerSkill() {
    cout<<"Collect 1 bonus Victory coin for each Hill Region you occupy. "<<endl;
}