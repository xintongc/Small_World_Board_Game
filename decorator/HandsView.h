//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_HANDSVIEW_H
#define SMALL_WORLD_HANDSVIEW_H


#include "../DesignPattern/Observer.h"
#include "ViewDecorator.h"

class HandsView : public ViewDecorator {
public:
    HandsView(Observer *basicView);

    HandsView();

    virtual ~HandsView();

    virtual void Update(const std::string&);
    virtual void UpdateStatistics();
    virtual void UpdateBarGraph();

    virtual void showInfo(Observer* observer);
    virtual void showInfo();
    void  showCoins(Observer* observer);
    void  showHands(Observer* observer);
};


#endif //SMALL_WORLD_HANDSVIEW_H
