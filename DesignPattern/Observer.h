//
// Created by yanra on 2018-03-27.
//

#ifndef SMALL_WORLD_OBSERVER_H
#define SMALL_WORLD_OBSERVER_H


#include <string>

class Observer {
public:
    ~Observer();
    virtual void Update(const std::string&) = 0;
    virtual void UpdateStatistics() = 0;
    virtual void UpdateBarGraph() = 0;
protected:
    Observer();
};


#endif //SMALL_WORLD_OBSERVER_H
