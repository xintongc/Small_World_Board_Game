//
// Created by yanra on 2018-03-08.
//

#include "GamePieces.h"

GamePieces::GamePieces() {

}

GamePieces::~GamePieces() {

}

const std::string &GamePieces::getType() const {
    return type;
}

void GamePieces::setType(const std::string &type) {
    GamePieces::type = type;
}

int GamePieces::getAvaliableNum() const {
    return avaliableNum;
}

void GamePieces::setAvaliableNum(int avaliableNum) {
    GamePieces::avaliableNum = avaliableNum;
}


