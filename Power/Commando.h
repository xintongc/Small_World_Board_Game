

#ifndef COMMANDO_H
#define COMMANDO_H

#include "Power.h"

class Commando: public Power {
public:
    Commando();
    Commando(const Commando& orig);
    virtual ~Commando();
private:

};

#endif /* COMMANDO_H */

