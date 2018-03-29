//
// Created by xintong cheng on 2018-03-10.
//

#ifndef SMALL_WORLD_REGION_H
#define SMALL_WORLD_REGION_H

#include <iostream>
#include <string>
#include <vector>
#include "../gamePieces/GamePieces.h"

using namespace std;

enum class Landform {FarmLand, Hill, Forest, Swamp, Lake, Sea, Mountain};
enum class LandMark {Non, Mine, Magic, Cavern, Mine_Cavern};
enum class Owner {Non, Player1, Player2, Player3, Player4, Player5};

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

class Region {

private:

    int id;
    Landform landform;
    LandMark landMark;
    Owner owner ;
    bool border;
    bool lostTribes;
    int population;
    vector<GamePieces*> gamePieces;

public:
    Region();
    virtual ~Region();

    void addGamePieces(GamePieces* pieces);
    vector <GamePieces*> getGamePiecesVector();
    void displayGamePieces();
    void info();

    int getId() const;
    Landform getLandform() const;
    LandMark getLandMark() const;
    int getOwner();
    bool isBorder() const;
    bool isLostTribes() const;
    int getPopulation() const;
    int getOwnerID();

    void setId(int id);
    void setLandform(Landform landform);
    void setLandMark(LandMark landMark);
    void setOwner(Owner owner);
    void setTokens(int value);
    void setBorder(bool border);
    void setLostTribes(bool lostTribes);
    void setPopulation(int population);

    bool hasMountain();
    bool isFarmLand();
    bool isHill();
    bool isForest();
    bool isSwamp();
    bool isLake();
    bool isSea();
    bool isMine();
    bool isMagic();
    bool isCavern();
    bool isMine_Cavern();


};

#endif //SMALL_WORLD_REGION_H
