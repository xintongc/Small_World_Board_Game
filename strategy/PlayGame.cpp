#include "PlayGame.h"



PlayGame::PlayGame(PlayerStrategy* strat): strategy(strat)
{
}


PlayGame::~PlayGame()
{
}

void PlayGame::play() {
    strategy->play();
}