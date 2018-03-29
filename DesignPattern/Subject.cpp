//
// Created by yanra on 2018-03-27.
//

#include "Subject.h"

Subject::Subject(){
    observersList = new list<Observer*>;
}
Subject::~Subject(){
   // delete observersList;
}
void Subject::Attach(Observer* o){
    observersList->push_back(o);
};
void Subject::Detach(Observer* o){
    observersList->remove(o);
};
void Subject::Notify(){
    list<Observer *>::iterator i;
    for (i = observersList->begin(); i != observersList->end(); ++i)
        (*i)->Update();
};