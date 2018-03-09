//
// Created by yanra on 2018-03-08.
//

#ifndef SMALL_WORLD_GAMEPIECES_H
#define SMALL_WORLD_GAMEPIECES_H

#include<string>

class GamePieces {
public:
    GamePieces();
    virtual ~GamePieces();

    const std::string &getType() const;
    void setType(const std::string &type);

    int getAvaliableNum() const;
    void setAvaliableNum(int avaliableNum);

private:
    std::string type;
    int avaliableNum;
};


#endif //SMALL_WORLD_GAMEPIECES_H
