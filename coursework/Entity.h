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
	Map map;
public:
	Entity(float X, float Y, int W, int H)
	{
		x = X; w = W; dx = 0;
		y = Y; h = H; dy = 0;
		speed = 0;
		health = 100;
		life = true; isMove = false; onGround = false;
		moveTimer = 0;
	}
	Sprite getSprite() 
	{
		return sprite;
	}
	virtual void CheckColissionWithMapX(float &dx) = 0;
	virtual void CheckColissionWithMapY(float &dy) = 0;
	virtual void update(float time) = 0;
};