

#ifndef WEALTHY_H
#define WEALTHY_H

#include "Power.h"
#include "../Player.h"

class Wealthy: public Power {
public:
    Wealthy();
    virtual ~Wealthy();
    virtual void powerSkill();
    void power(Player&);

};

#endif /* WEALTHY_H */

