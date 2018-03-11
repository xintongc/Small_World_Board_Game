

#ifndef MERCHANT_H
#define MERCHANT_H

#include "Power.h"

class Merchant: public Power {
public:
    Merchant();
    virtual ~Merchant();
    virtual void powerSkill();

};

#endif /* MERCHANT_H */

