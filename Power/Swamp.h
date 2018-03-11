//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_SWAMP_H
#define SMALL_WORLD_SWAMP_H


#include "Power.h"

class Swamp : public Power{
public:
    Swamp();
    Swamp(const Swamp& orig);
    virtual ~Swamp();
    virtual void powerSkill();
};


#endif //SMALL_WORLD_SWAMP_H
