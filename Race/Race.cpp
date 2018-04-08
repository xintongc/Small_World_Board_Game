//
// Created by yanra on 2018-02-12.
//

#include "Race.h"
Race::Race() {
    tokens=0;
    type="";
    skill="";
}
Race::~Race() {}

void Race::raceSkill() {}

int Race::getTokens() const {
    return tokens;
}

const std::string &Race::getSkill() const {
    return skill;
}

const std::string &Race::getType() const {
    return type;
}

void Race::setTokens(int tokens) {
    Race::tokens = tokens;
}

void Race::setSkill(const std::string &skill) {
    Race::skill = skill;
}

void Race::setType(const std::string &type) {
    Race::type = type;
}
