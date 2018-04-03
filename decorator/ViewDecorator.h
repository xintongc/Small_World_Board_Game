//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_VIEWDECORATOR_H
#define SMALL_WORLD_VIEWDECORATOR_H

#include "../DesignPattern/Observer.h"

class ViewDecorator : public Observer{
private:
    Observer* basicView;

public:
    ViewDecorator(Observer *basicView);

    ViewDecorator();

    virtual ~ViewDecorator();
    virtual void Update(const std::string&);
    virtual void UpdateStatistics();
    virtual void UpdateBarGraph();


    virtual void showInfo();
    virtual void showInfo(Observer*);
    virtual void showCoins(Observer* observer);
    virtual void showHands(Observer* observer);

};


#endif //SMALL_WORLD_VIEWDECORATOR_H
