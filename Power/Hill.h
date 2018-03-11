

#ifndef HILL_H
#define HILL_H

#include "Power.h"

class Hill: public Power {
public:
    Hill();
    Hill(const Hill& orig);
    virtual ~Hill();
    virtual void powerSkill();

};

#endif /* HILL_H */

