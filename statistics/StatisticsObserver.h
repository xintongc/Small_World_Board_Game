//
// Created by xintong cheng on 2018-03-29.
//

#ifndef SMALL_WORLD_STATISTICSOBSERVER_H
#define SMALL_WORLD_STATISTICSOBSERVER_H


#include "../DesignPattern/Observer.h"
#include "../Player.h"

class StatisticsObserver : public Observer {
public:
    StatisticsObserver();

    virtual ~StatisticsObserver();

    void UpdateStatistics();
    void Update(const std::string& str);
    //  Player* statisticsSubject;
    vector<Player*> statisticsSubject;

    void displayStatistics();
private:
};


#endif //SMALL_WORLD_STATISTICSOBSERVER_H
