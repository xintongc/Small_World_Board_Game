//
// Created by yanra on 2018-02-12.
//

#include "Race.h"
Race::Race() {
    tokens=0;
}
Race::~Race() {}

void Race::raceSkill() {}

int Race::getTokens() const {
    return tokens;
}

const std::string &Race::getSkill() const {
    return skill;
}
