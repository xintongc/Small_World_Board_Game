//
// Created by xintong cheng on 2018-02-12.
//

#ifndef SMALL_WORLD_POWER_H
#define SMALL_WORLD_POWER_H


class Power {
public:
    Power();
    virtual ~Power();

    int getTokens() const;
    void usePower();


    int tokens;

};


#endif //SMALL_WORLD_POWER_H
