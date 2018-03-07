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
    const std::string &getType() const;

    void setTokens(int tokens);
    void setSkill(const std::string &skill);
    void setType(const std::string &type);

private:
    int tokens;
    std::string skill;
    std::string type;
};


#endif //SMALL_WORLD_RACE_H
