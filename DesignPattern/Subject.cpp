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

//showing percentage data of each player owned regions. 
void Subject::NotifyStatistics(){
    vector<Observer *>::iterator i;

    for (i = observersList->begin(); i != observersList->end(); ++i) {
        (*i)->UpdateStatistics();
    }
}

//shows using some kind of bar graph depicting what percentage of the world is currently being controlled by each player
void Subject::NotifyBarGraph(){
        vector<Observer *>::iterator i;
        for (i = observersList->begin(); i != observersList->end(); ++i) {
            (*i)->UpdateBarGraph();
        }
};


//connecting with decorator pattern
void Subject::notifyTurn(Observer *observer){
}

void Subject::notifyConquerAndLoss(){
    vector<Observer *>::iterator i;

    for (i = observersList->begin(); i != observersList->end(); ++i) {
        (*i)->showInfo(*i);
    }
}

void Subject::notifyHands(){
    vector<Observer *>::iterator i;

    for (i = observersList->begin(); i != observersList->end(); ++i) {
        (*i)->showHands(*i);
    }
}

void Subject::notifyCoins() {
    vector<Observer *>::iterator i;

    for (i = observersList->begin(); i != observersList->end(); ++i) {
        (*i)->showCoins(*i);
    }
}
