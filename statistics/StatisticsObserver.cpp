//
// Created by xintong cheng on 2018-03-29.
//

#include "StatisticsObserver.h"

StatisticsObserver::StatisticsObserver() {

}

StatisticsObserver::~StatisticsObserver() {

}

void StatisticsObserver::UpdateStatistics() {
    displayStatistics();
}

void StatisticsObserver::Update(const std::string& str){

}

void StatisticsObserver::displayStatistics() {
    cout<<"\n==== From observer pattern ==== ";
    for(int i=0;i<statisticsSubject.size();i++){
        cout <<"Player "<< statisticsSubject[i]->getId() << ": percentage: " << statisticsSubject[i]->calculatePercentage()<<"%";
        statisticsSubject[i]->showBarGraph();


    }
}
