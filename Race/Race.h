//
// Created by yanra on 2018-02-12.
//

#ifndef SMALL_WORLD_RACE_H
#define SMALL_WORLD_RACE_H
#include<string>

class Race {
public:
    Race();
    ~Race() ;

    virtual void raceSkill();
    int getTokens() const;
    const std::string &getSkill() const;

    int tokens;
    std::string skill;
};


#endif //SMALL_WORLD_RACE_H
