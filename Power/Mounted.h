

#ifndef MOUNTED_H
#define MOUNTED_H

#include "Power.h"

class Mounted: public Power {
public:
    Mounted();
    Mounted(const Mounted& orig);
    virtual ~Mounted();
private:

};

#endif /* MOUNTED_H */

