//
// Created by yanra on 2018-03-27.
//

#ifndef SMALL_WORLD_SUBJECT_H
#define SMALL_WORLD_SUBJECT_H


#include "Observer.h"
#include "../Player.h"
#include <vector>
using namespace std;

class Subject {
public:
    Subject();
    ~Subject();
    
    virtual void Attach(Observer* o);
    virtual void Detach(Observer* o);
    
    //for part 1 & 2 observer pattern
    virtual void Notify(const std::string &, Observer *);
    virtual void NotifyStatistics();
    virtual void NotifyBarGraph();

    //for part 4 decorator patter
    virtual void notifyTurn(Observer *);
    virtual void notifyConquerAndLoss();
    virtual void notifyHands();
    virtual void notifyCoins();

protected:
    vector<Observer*> *observersList;
};


#endif //SMALL_WORLD_SUBJECT_H
