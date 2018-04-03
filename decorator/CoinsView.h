//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_COINSVIEW_H
#define SMALL_WORLD_COINSVIEW_H


#include "../DesignPattern/Observer.h"
#include "ViewDecorator.h"

class CoinsView : public ViewDecorator {
public:
    CoinsView();

    virtual ~CoinsView();

    CoinsView(Observer *basicView);



    virtual void Update(const std::string&);
    virtual void UpdateStatistics();
    virtual void UpdateBarGraph();

    virtual void showInfo(Observer* observer);
    virtual void showInfo();
    virtual void showCoins(Observer* observer);
    virtual void showHands(Observer* observer);


};


#endif //SMALL_WORLD_COINSVIEW_H
