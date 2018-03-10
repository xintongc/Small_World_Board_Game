//
// Created by xintong cheng on 2018-03-10.
//

#include "Region.h"
Region::Region() {
    landMark = LandMark ::Non;
    owner = Owner ::Non;
    border = false;
    lostTribes = false;
}

Region::~Region() {}

int Region::getId() const {
    return id;
}

void Region::setId(int id) {
    Region::id = id;
}

Landform Region::getLandform() const {
    return landform;
}

void Region::setLandform(Landform landform) {
    Region::landform = landform;
}

LandMark Region::getLandMark() const {
    return landMark;
}

void Region::setLandMark(LandMark landMark) {
    Region::landMark = landMark;
}

Owner Region::getOwner() const {
    return owner;
}

void Region::setOwner(Owner owner) {
    Region::owner = owner;
}

bool Region::isBorder() const {
    return border;
}

void Region::setBorder(bool border) {
    Region::border = border;
}

bool Region::isLostTribes() const {
    return lostTribes;
}

void Region::setLostTribes(bool lostTribes) {
    Region::lostTribes = lostTribes;
}

//const vector<GamePieces *, allocator<GamePieces *>> &Region::getPieces() const {
//    return Pieces;
//}

//void Region::setPieces(const vector<GamePieces *, allocator<GamePieces *>> &Pieces) {
//    Region::Pieces = Pieces;
//}

void Region::addGamePieces(GamePieces* pieces){
    gamePieces.push_back(pieces);
}

vector<GamePieces*> Region:: getGamePiecesVector(){
    return gamePieces;
}

void Region::displayGamePieces(){
    for(int i = 0; i < gamePieces.size(); i++){
        cout << "GamePieces[" << i << "]= " << gamePieces[i]->getType() << " ";
    }
    cout << endl;
}

void Region::info() {
    cout<< "Region " << id << ": " << "Owmer:" << owner  << " Landform:"
        << landform << " LandMark:" << landMark << " Border:" << isBorder()
        << " LostTribes:" << isLostTribes() << " ";
    displayGamePieces();
}
