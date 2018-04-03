//
// Created by yanra on 2018-03-27.
//

#include "Subject.h"

Subject::Subject(){
    observersList = new vector<Observer*>;
}
Subject::~Subject(){
   // delete observersList;
}
void Subject::Attach(Observer* o){
    observersList->push_back(o);
};
void Subject::Detach(Observer* o){
//    observersList->remove(o);
};
void Subject::Notify(const std::string &str, Observer *observer){
//    list<Observer *>::iterator i;
//    for (i = observersList->begin(); i != observersList->end(); ++i)
//        (*i)->Update(str);
};

void Subject::NotifyStatistics(){
    vector<Observer *>::iterator i;

    for (i = observersList->begin(); i != observersList->end(); ++i) {
        (*i)->UpdateStatistics();
    }
}
void Subject::NotifyBarGraph(){
        vector<Observer *>::iterator i;
        for (i = observersList->begin(); i != observersList->end(); ++i) {
            (*i)->UpdateBarGraph();
        }
};


void Subject::notifyTurn(Observer *observer){
}

void Subject::notifyConquerAndLoss(){
    vector<Observer *>::iterator i;

    for (i = observersList->begin(); i != observersList->end(); ++i) {
        (*i)->showInfo(*i);
    }
}