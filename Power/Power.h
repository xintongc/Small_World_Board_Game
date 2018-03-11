//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_POWER_H
#define SMALL_WORLD_POWER_H


#include <string>

class Power {
public:
    Power();
    virtual ~Power();

    virtual void powerSkill();

    int getTokens() const;
    const std::string &getType() const;
    const std::string &getPower() const;

    void setTokens(int tokens);
    void setType(const std::string &type);
    void setPower(const std::string &power);

private:
    int tokens;
    std::string type;
    std::string power;
};


#endif //SMALL_WORLD_POWER_H
