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

enum class Landform {FarmLand, Hill, Forest, Swamp, Lake, Sea};
enum class LandMark {Non, Mine, Magic, Cavern};
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
    vector<GamePieces*> gamePieces;

public:
    Region();
    virtual ~Region();

    int getId() const;

    void setId(int id);

    Landform getLandform() const;

    void setLandform(Landform landform);

    LandMark getLandMark() const;

    void setLandMark(LandMark landMark);

    Owner getOwner() const;

    void setOwner(Owner owner);

    bool isBorder() const;

    void setBorder(bool border);

    bool isLostTribes() const;

    void setLostTribes(bool lostTribes);

//    const vector<GamePieces *, allocator<GamePieces *>> &getPieces() const;

//    void setPieces(const vector<GamePieces *, allocator<GamePieces *>> &Pieces);

    void addGamePieces(GamePieces* pieces);

    vector <GamePieces*> getGamePiecesVector();

    void displayGamePieces();

    void info();




};

#endif //SMALL_WORLD_REGION_H
