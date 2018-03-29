//
// Created by yanra on 2018-03-27.
//

#ifndef SMALL_WORLD_OBSERVER_H
#define SMALL_WORLD_OBSERVER_H



class Observer {
public:
    ~Observer();
    virtual void Update() = 0;
protected:
    Observer();
};


#endif //SMALL_WORLD_OBSERVER_H
