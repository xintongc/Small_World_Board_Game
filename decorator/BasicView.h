//
// Created by xintong cheng on 2018-04-02.
//

#ifndef SMALL_WORLD_BASICVIEW_H
#define SMALL_WORLD_BASICVIEW_H


#include "../DesignPattern/Observer.h"

class BasicView : public Observer {
public:

    virtual ~BasicView();

    BasicView();

    virtual void Update(const std::string&);
    virtual void UpdateStatistics();
    virtual void UpdateBarGraph();


    virtual void showInfo();

private:
    int turnRun = 0;
};


#endif //SMALL_WORLD_BASICVIEW_H
