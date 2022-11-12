#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
using namespace sf;
class Entity
{
protected:
	float dx, dy, x, y, speed;
	int w, h, health;
	bool life, onGround;
	Texture texture;
	Sprite sprite;
	Map map;
	std::string name;
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
	bool getLife() 
	{
		return life;
	}
	void setLife(bool value) 
	{
		life = value;
	}
	void setHealth(int value) 
	{
		health = value;
	}
	int getHealth() 
	{
		return health;
	}
	std::string getName()
	{
		return name;
	}
	virtual void CheckColissionWithMapX(float &dx) = 0;
	virtual void CheckColissionWithMapY(float &dy) = 0;
	virtual void update(float time) = 0;
};