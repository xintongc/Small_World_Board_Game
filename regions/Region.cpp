//
// Created by xintong cheng on 2018-03-10.
//

#include "Region.h"
Region::Region() {
    landMark = LandMark ::Non;
    owner = Owner ::Non;
    border = false;
    lostTribes = false;
    population = 0;
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

int Region::getOwner() {
    return (int)owner;
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
    if(id<10){
        cout<< "Region 0" << id << ": " << "Owmer:" << owner <<" Population:" << population << " Landform:"
            << landform << " LandMark:" << landMark << " Border:" << isBorder()
            << " LostTribes:" << isLostTribes() << " ";
    }
    else{
        cout<< "Region " << id << ": " << "Owmer:" << owner <<" Population:" << population << " Landform:"
            << landform << " LandMark:" << landMark << " Border:" << isBorder()
            << " LostTribes:" << isLostTribes() << " ";
    }

    displayGamePieces();
}

int Region::getPopulation() const {
    return population;
}

void Region::setPopulation(int population) {
    Region::population = population;
}

bool Region::hasMountain(){
    for(int i = 0; i < gamePieces.size(); i++){
        if(!gamePieces[i]->getType().compare("Mountains")){
            return true;
        }
    }
    return false;
}

bool Region::isFarmLand(){
    return (int)getLandform()==0;
}

bool Region::isHill(){
    return (int)getLandform()==1;
}

bool Region::isForest(){
    return (int)getLandform()==2;
}

bool Region::isSwamp(){
    return (int)getLandform()==3;
}

bool Region::isLake(){
    return (int)getLandform()==4;
}

bool Region::isSea(){
    return (int)getLandform()==5;
}

bool Region::isMine(){
    return (int)getLandMark()==1;
}

bool Region::isMagic(){
    return (int)getLandMark()==2;
}

bool Region::isCavern(){
    return (int)getLandMark()==3;
}

bool Region::isMine_Cavern(){
    return (int)getLandMark()==4;
}

int Region::getOwnerID() {
    return (int)owner;
}