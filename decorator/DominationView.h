//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_DOMINATIONVIEW_H
#define SMALL_WORLD_DOMINATIONVIEW_H


#include "../DesignPattern/Observer.h"
#include "ViewDecorator.h"

//#include "../Game.h"
#include "../regions/MapRegions.h"
#include "../Player.h"
#include <iostream>

class DominationView : public ViewDecorator{
public:
    DominationView();
    DominationView(Observer *basicView);
    virtual ~DominationView();

    virtual void Update(const std::string&);
    virtual void UpdateStatistics();
    virtual void UpdateBarGraph();

    virtual void showInfo();
    virtual void showInfo(Observer* observer);
    virtual void showCoins(Observer* observer);
    virtual void showHands(Observer* observer);


    void UpdateStatistics(Observer* observer);

};



#endif //SMALL_WORLD_DOMINATIONVIEW_H
