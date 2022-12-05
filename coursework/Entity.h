#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"
using namespace sf;
class Entity
{
protected:
	float dx, dy, x, y, speed;
	int w, h, health, bufHealth;
	bool life, onGround;
	Texture textureEntity;
	Texture textureHealth;
	Sprite spriteEntity;
	Sprite spriteHealth;
	Map map;
	std::string name;
	std::vector <Sprite> healths;
public:
	Entity(float X, float Y);

	Sprite getSprite();

	bool getLife();
	void setLife(bool value);

	void setDx(float value);
	float getDx();

	std::string getName();
	void drawSprite(RenderWindow& window);

	virtual void hit() = 0;
	virtual void CheckColissionWithMapX(float &dx) = 0;
	virtual void CheckColissionWithMapY(float &dy) = 0;
	virtual void update(float time) = 0;
};