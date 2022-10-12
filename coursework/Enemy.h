#pragma once
#include "Entity.h"


class Enemy : public Entity  
{
public:
	Enemy(float X, float Y, int W, int H) :Entity(X, Y, W, H) 
	{
	}
	void checkCollisionWithMap(float dx,float dy);
	void update(float time);
};

