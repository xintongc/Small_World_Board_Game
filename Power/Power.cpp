//
// Created by xintong cheng on 2018-02-12.
//

#include "Power.h"

Power::Power(){
}

Power::~Power() {

}

void Power:: usePower(){

}

int Power::getTokens() const {
    return tokens;
}

void Power::setTokens(int tokens) {
    Power::tokens = tokens;
}

const std::string &Power::getType() const {
    return type;
}

void Power::setType(const std::string &type) {
    Power::type = type;
}

const std::string &Power::getPower() const {
    return power;
}

void Power::setPower(const std::string &power) {
    Power::power = power;
}
