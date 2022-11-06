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
	bool life, onGround;
	Texture texture;
	Sprite sprite;
	Map map;
public:
	Entity(float X, float Y)
	{
		health = 100;
		x = X;  dx = 0;
		y = Y;  dy = 0;
		speed = 0;
		health = 100;
		life = true; onGround = false;
	}
	Sprite getSprite() 
	{
		return sprite;
	}
	int getX() 
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	bool Life() 
	{
		return life;
	}
	virtual void CheckColissionWithMapX(float &dx) = 0;
	virtual void CheckColissionWithMapY(float &dy) = 0;
	virtual void update(float time) = 0;
};