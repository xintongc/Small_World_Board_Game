//
// Created by yanra on 2018-03-08.
//

#include <cstdlib>
#include "Race/Race.h"
#include "Race/Amazons.h"
#include "Race/Dwarves.h"
#include "Race/Elves.h"
#include "Race/Ghouls.h"
#include "Race/Giants.h"
#include "Race/Halflings.h"
#include "Race/Humans.h"
#include "Race/Orcs.h"
#include "Race/Ratmen.h"
#include "Race/Skeletons.h"
#include "Race/Sorcerers.h"
#include "Race/Tritons.h"
#include "Race/Trolls.h"
#include "Race/Wizards.h"
#include "Power/Alchemist.h"
#include "Power/Berserk.h"
#include "Power/Bivouacking.h"
#include "Power/Commando.h"
#include "Power/Diplomat.h"
#include "Power/DragonMaster.h"
#include "Power/Flying.h"
#include "Power/Forest.h"
#include "Power/Fortified.h"
#include "Power/Heroic.h"
#include "Power/Hill.h"
#include "Power/Merchant.h"
#include "Power/Mounted.h"
#include "Power/Pillaging.h"
#include "Power/Seafaring.h"
#include "Power/Spirit.h"
#include "Power/Stout.h"
#include "Power/Swamp.h"
#include "Power/Underworld.h"
#include "Power/Wealthy.h"
#include<iostream>
#include "ComboList.h"
using namespace std;

ComboList::ComboList() {
}


ComboList::~ComboList() {}


void ComboList::initial() {
    for (int i = 0; i < 15; i++) {
        raceUsed[i] = false;
    }
    for (int i = 0; i < 21; i++) {
        powerUsed[i] = false;
    }
}
void ComboList::listAllPairs () {
    //----------random race number and add to race stack----------------
    int chooseRace = 0;
    int size1=0;
    srand (time(NULL));
    do{
        chooseRace = rand() % 14 + 1; //generate number from 1 to 14
        //cout<<chooseRace<<" ";
        if (!raceUsed[chooseRace]){
            raceStack.push(chooseRace);
            raceUsed[chooseRace] = true;
            size1++;
        }
    }while(size1<14);

    cout<<"\n";

    //----------random power number and add to race stack----------------
    int choosePower = 0;
    int size2=0;
    do{
        choosePower = rand() % 20 + 1; //generate number from 1 to 20
        //cout<<choosePower<<" ";
        if (!powerUsed[choosePower]){
            powerStack.push(choosePower);
            powerUsed[choosePower] = true;
            size2++;
        }
    }while(size2<20);
    //cout<<" "<<endl;
}

void ComboList::printStacks() {
    cout<<"\n";
    while( !raceStack.empty() ) {
        cout << raceStack.top() << " ";
        raceStack.pop();
    }
    cout << "\n";
    while( !powerStack.empty() ) {
        cout << powerStack.top() << " ";
        powerStack.pop();
    }
}


//initially select 5 races and powers to be face-up ComboLists
vector <Race> ComboList::initialRaceVector() {
    int temp = 0;
    for (int i = 0; i < 5; i++) {
        if (!raceStack.empty()) {
            temp = raceStack.top();
            raceStack.pop();
        }
        raceVector.push_back(switchRace(temp));
    }
    return raceVector;
}

//initially select 5 races and powers to be face-up ComboLists
vector <Power> ComboList::initialPowerVector() {
    int temp=0;
    for(int i=0;i<5;i++) {
        if (!powerStack.empty()) {
            temp = powerStack.top();
            powerStack.pop();
        }
        powerVector.push_back(switchPower(temp));
    }
    return powerVector;
}

vector <int> ComboList::initialCoinsVector() {
    for(int i=0;i<5;i++){
        coinsVector.push_back(0);
    }
    return coinsVector;
}

void ComboList::printCurrentVectors() {
    cout<<"\nThe current ComboLists are: "<<endl;
    for(int i=0;i<5;i++){
        cout<<raceVector[i].getType()<<" and " <<powerVector[i].getType()<<". Coins are: "<<coinsVector[i]<<endl;
    }
}


//A total of 6 Race banner and Special Power badge ComboLists should be visible face up on the playing area,
// including the one on top of the stacks
void ComboList::showStackTop() {
    int temp1=0;
    int temp2=0;

    if (!raceStack.empty()){
        temp1= raceStack.top();
    }
    if (!powerStack.empty()){
        temp2= powerStack.top();
    }
    cout<<"\nIn stacks, the top ComboList is: ";
    cout<<switchRace(temp1).getType()<<" and "<<switchPower(temp2).getType()<<endl;
}


//replenishes the column of ComboLists available to others
void ComboList::replenishCombo() {
    if(raceVector.size()==powerVector.size()==coinsVector.size()){  //check both vectors have same size
        if(raceVector.size()<5){
            int temp1=0;
            int temp2=0;
            do{
                if (!raceStack.empty()){
                    temp1= raceStack.top();
                    raceStack.pop();
                }
                if (!powerStack.empty()){
                    temp2= powerStack.top();
                    powerStack.pop();
                }
                raceVector.push_back(switchRace(temp1));
                powerVector.push_back(switchPower(temp2));
                coinsVector.push_back(0);
            }while(raceVector.size()<5);
        }
    }
    else
        cout<<"Invalid raceVector, powerVector and coinsVector"<<endl;
}


//create a race and being visible face up on the vector
Race ComboList::switchRace (int x) {
    //cout<<"Race: ";
    switch (x){
        case 1: {
            Amazons amazon;
            //cout<<"amazons are facing up now"<<endl;
            return amazon;
            break;
        }
        case 2: {
            Dwarves dwarve;
            //cout<<"dwarve are facing up now"<<endl;
            return dwarve;
            break;
        }
        case 3: {
            Elves elve;
            //cout<<"elve are facing up now"<<endl;
            return elve;
            break;
        }
        case 4: {
            Ghouls ghoul ;
            //cout<<"ghoul are facing up now"<<endl;
            return ghoul ;
            break;
        }
        case 5: {
            Giants giant ;
            //cout<<"giant are facing up now"<<endl;
            return giant;
            break;
        }
        case 6: {
            Halflings halfling;
            //cout<<"halfling are facing up now"<<endl;
            return halfling;
            break;
        }
        case 7: {
            Humans human;
            //cout<<"human are facing up now"<<endl;
            return human;
            break;
        }
        case 8: {
            Orcs orc ;
            //cout<<"orc are facing up now"<<endl;
            return orc;
            break;
        }
        case 9: {
            Ratmen ratmen;
            //cout<<"ratmen are facing up now"<<endl;
            return ratmen;
            break;
        }
        case 10: {
            Skeletons skeleton ;
            //cout<<"skeleton are facing up now"<<endl;
            return skeleton;
            break;
        }
        case 11: {
            Sorcerers sorcerer;
            //cout<<"sorcerer are facing up now"<<endl;
            return sorcerer;
            break;
        }
        case 12: {
            Tritons triton;
            //cout<<"triton are facing up now"<<endl;
            return triton;
            break;
        }
        case 13: {
            Trolls troll;
            //cout<<"troll are facing up now"<<endl;
            return troll;
            break;
        }
        case 14: {
            Wizards wizard;
            //cout<<"wizard are facing up now"<<endl;
            return wizard;
            break;
        }
        default:
            cout<<"Invaid"<<endl;
    }
}

//create a power and being visible face up on the vector
Power ComboList::switchPower(int x) {
    //cout<<"\nPower: ";
    switch (x){
        case 1:{
            Alchemist alchemist;
            //cout<<"alchemist and ";
            return alchemist;
            break;
        }
        case 2: {
            Berserk berserk;
            //cout<<"berserk and ";
            return berserk;
            break;
        }
        case 3: {
            Bivouacking bivouacking;
            //cout<<"bivouacking and ";
            return bivouacking;
            break;
        }
        case 4: {
            Commando commando;
            //cout<<"commando and ";
            return commando ;
            break;
        }
        case 5: {
            Diplomat diplomat ;
            //cout<<"diplomat and ";
            return diplomat;
            break;
        }
        case 6: {
            DragonMaster dragonMaster;
            //cout<<"dragonMaster and ";
            return dragonMaster;
            break;
        }
        case 7: {
            Flying flying;
            //cout<<"flying and ";
            return flying;
            break;
        }
        case 8: {
            Forest forest ;
            //cout<<"forest and ";
            return forest;
            break;
        }
        case 9: {
            Fortified fortified;
            //cout<<"fortified and ";
            return fortified;
            break;
        }
        case 10: {
            Heroic heroic ;
            //cout<<"heroic and ";
            return heroic;
            break;
        }
        case 11: {
            Hill hill;
            //cout<<"hill and ";
            return hill;
            break;
        }
        case 12: {
            Merchant merchant;
            //cout<<"merchant and ";
            return merchant;
            break;
        }
        case 13: {
            Mounted mounted;
            //cout<<"mounted and ";
            return mounted;
            break;
        }
        case 14: {
            Pillaging pillaging;
            //cout<<"pillaging and ";
            return pillaging;
            break;
        }
        case 15: {
            Seafaring seafaring;
            //cout<<"seafaring and ";
            return seafaring;
            break;
        }
        case 16: {
            Spirit spirit;
            //cout<<"spirit and ";
            return spirit;
            break;
        }
        case 17: {
            Stout stout;
            //cout<<"stout and ";
            return stout;
            break;
        }
        case 18: {
            Swamp swamp;
            //cout<<"swamp and ";
            return swamp;
            break;
        }
        case 19: {
            Underworld underworld;
            //cout<<"underworld and ";
            return underworld;
            break;
        }
        case 20:{
            Wealthy wealthy;
            //cout<<"wealthy and ";
            return wealthy;
            break;
        }
        default:
            cout<<"Invaid"<<endl;
    }
}
