#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
using namespace sf;
class Entity
{
protected:
	float dx, dy, x, y, speed,moveTimer;
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
public:
	Entity(float X, float Y, int W, int H)
	{
		x = X; w = W; dx = 0;
		y = Y; h = H; dy = 0;
		speed = 0;
		health = 100;
		life = true; isMove = false; onGround = false;
	}
   
	Sprite getSprite() 
	{
		return sprite;
	}
};