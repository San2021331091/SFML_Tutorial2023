#include <SFML/Graphics.hpp>
#include "Game.h"
#pragma once
#ifndef CADILLACS_AND_DINOSAUR_GAME_PLAYER_H
#define CADILLACS_AND_DINOSAUR_GAME_PLAYER_H
using namespace sf;

class Player {

public:
    Player(Texture *texture,Vector2u imageCount,float switchTime,float speed);
    void Update(float deltaTime);
    void draw(RenderWindow &window);
    Vector2f GetPosition(){  return body.getPosition();  }

private:
  RectangleShape body;
  Game game;
  unsigned int row;
  float speed;
  bool faceRight;
};


#endif
