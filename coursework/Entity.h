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
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	std::string name;
	std::string filename;
public:
	Entity(float X, float Y, int W, int H)
	{
		x = X; w = W; dx = 0;
		y = Y; h = H; dy = 0;
		speed = 0;
		health = 100;
		life = true; isMove = false; onGround = false;
	/*	texture.loadFromFile("images/" + fileName);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);*/
	}
   
	Sprite getSprite() 
	{
		return sprite;
	}
};