
#ifndef FLYING_H
#define FLYING_H

#include "Power.h"

class Flying: public Power {
public:
    Flying();
    Flying(const Flying& orig);
    virtual ~Flying();
private:

};

#endif /* FLYING_H */

