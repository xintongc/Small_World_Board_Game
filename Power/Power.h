//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_POWER_H
#define SMALL_WORLD_POWER_H


class Power {
public:

    int tokens;

    Power();
    virtual ~Power();

    int getTokens() const;
    void usePower();


};


#endif //SMALL_WORLD_POWER_H
