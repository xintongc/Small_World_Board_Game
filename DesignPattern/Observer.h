//
// Created by yanra on 2018-03-27.
//

#ifndef SMALL_WORLD_OBSERVER_H
#define SMALL_WORLD_OBSERVER_H


#include <string>

class Observer {
public:
    ~Observer();
    Observer();
    //for part 1 & 2 observer pattern
    virtual void Update(const std::string&) = 0;
    virtual void UpdateStatistics() = 0;
    virtual void UpdateBarGraph() = 0;

    //for part 4 decorator patter
    virtual void showInfo()= 0;
    virtual void showInfo(Observer* observer)= 0;
    virtual void showCoins(Observer* observer)= 0;
    virtual void showHands(Observer* observer)= 0;

};


#endif //SMALL_WORLD_OBSERVER_H
