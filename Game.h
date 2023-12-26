#pragma once
#include <SFML/Graphics.hpp>

#ifndef CADILLACS_AND_DINOSAUR_GAME_GAME_H
#define CADILLACS_AND_DINOSAUR_GAME_GAME_H

using namespace sf;


class Game {

public:
    Game(Texture *texture,Vector2u imageCount,float switchTime);

    void update(int row,float delayTime,bool faceRight);

   IntRect uvRect;

private :
    Vector2u imageCount,currentImage;
    float totalTime,switchTime;
};


#endif
