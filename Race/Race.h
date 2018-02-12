//
// Created by yanra on 2018-02-12.
//

#ifndef SMALL_WORLD_RACE_H
#define SMALL_WORLD_RACE_H


class Race {
public:
    Race();
    ~Race() ;

    int getTokens() const;
    virtual void raceSkill() = 0; //Pure virtual function makes this class Abstract class.

int tokens;
};


#endif //SMALL_WORLD_RACE_H
